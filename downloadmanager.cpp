#include "downloadmanager.h"
#include <QTextStream>

using namespace std;

QList<pair<QString,QString>> DownloadManager::DownloadedList;

DownloadManager::DownloadManager(QObject *parent)
    : QObject(parent)
{
}

void DownloadManager::append(const QStringList &urls)
{
    for (const QString &urlAsString : urls)
        append(QUrl::fromEncoded(urlAsString.toLocal8Bit()));

    if (downloadQueue.isEmpty())
        QTimer::singleShot(0, this, SIGNAL(finished()));
}

void DownloadManager::append(const QUrl &url)
{
    if (downloadQueue.isEmpty())
        QTimer::singleShot(0, this, SLOT(startNextDownload()));

    downloadQueue.enqueue(url);
    ++totalCount;
}

QString DownloadManager::saveFileName(const QUrl &url)
{
    QString FolderAddress=url.url();
    FolderAddress.replace("http://","");
    FolderAddress.replace("https://","");
    bool flag=true;
    FolderAddress+="/";
    FolderAddress.replace("////","/");
    FolderAddress.replace("///","/");
    FolderAddress.replace("//","/");
    FolderAddress.replace("?","");
    FolderAddress.replace("*","");
    FolderAddress.replace("<","");
    FolderAddress.replace(">","");
    if(!QDir(FolderAddress).exists())
    {
        QString path="";
        int count=FolderAddress.count("/");
        for(auto item:FolderAddress.split("/"))
        {
            if(item=="")
                continue;
            if(count==1)
                break;
            path+=item+"/";
            QDir().mkdir(path);
            count--;
        }
        FolderAddress=path;
    }

    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "download."+(QFileInfo(path).completeSuffix()==""?"html":QFileInfo(path).completeSuffix());
    basename=FolderAddress+basename;
    if (QFile::exists(basename)) {
        basename=FolderAddress+(QFileInfo(path).baseName().isEmpty()?"download":QFileInfo(path).baseName());
        int i = 0;
        while (QFile::exists(basename +"_" +QString::number(i)+"."+(QFileInfo(path).completeSuffix()==""?"html":QFileInfo(path).completeSuffix())))
            ++i;
        basename += "_" + QString::number(i)+"."+(QFileInfo(path).completeSuffix()==""?"html":QFileInfo(path).completeSuffix());
    }
    basename +=(QFileInfo(basename).completeSuffix()==""?".html":"");
    return basename;
}


void DownloadManager::startNextDownload()
{
    if (downloadQueue.isEmpty()) {
        emit finished();
        return;
    }
    QUrl url = downloadQueue.dequeue();

    QString filename = saveFileName(url);
    output.setFileName(filename);
    if (!output.open(QIODevice::WriteOnly)) {
        startNextDownload();
        return;                 // skip this download
    }
    emit oneDownloadFinished();
    DownloadedList.push_back(make_pair(url.url(), filename));
    QNetworkRequest request(url);
    currentDownload = manager.get(request);
    connect(currentDownload, SIGNAL(downloadProgress(qint64,qint64)),
            SLOT(downloadProgress(qint64,qint64)));
    connect(currentDownload, SIGNAL(finished()),
            SLOT(downloadFinished()));
    connect(currentDownload, SIGNAL(readyRead()),
            SLOT(downloadReadyRead()));

    // prepare the output
    downloadTime.start();
}

void DownloadManager::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    progressBar->setValue(bytesReceived*100/bytesTotal);
    double speed = bytesReceived * 1000.0 / downloadTime.elapsed();
    QString unit;
    if (speed < 1024)
        unit = "bytes/sec";
    else if (speed < 1024*1024)
    {
        speed /= 1024;
        unit = "kB/s";
    }
    else
    {
        speed /= 1024*1024;
        unit = "MB/s";
    }
    labelSpeed->setText(QString::fromStdString( to_string( (int)speed)+" ")+unit);
}

void DownloadManager::downloadFinished()
{
    output.close();
    if (currentDownload->error())
        output.remove();
    else
    {
        if (isHttpRedirect())
        {
            reportRedirect();
            output.remove();
        }
        else
            ++downloadedCount;
    }
    currentDownload->deleteLater();

    startNextDownload();
}

void DownloadManager::downloadReadyRead()
{
    output.write(currentDownload->readAll());
}

bool DownloadManager::isHttpRedirect() const
{
    int statusCode = currentDownload->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    return statusCode == 301 || statusCode == 302 || statusCode == 303
            || statusCode == 305 || statusCode == 307 || statusCode == 308;
}

void DownloadManager::reportRedirect()
{
    QUrl requestUrl = currentDownload->request().url();

    QVariant target = currentDownload->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if (!target.isValid())
        return;
    QUrl redirectUrl = target.toUrl();
    if (redirectUrl.isRelative())
        redirectUrl = requestUrl.resolved(redirectUrl);
}

void DownloadManager::setLabelSpeed(QLabel *value)
{
    labelSpeed = value;
}

void DownloadManager::setProgressBar(QProgressBar *value)
{
    progressBar = value;
}



