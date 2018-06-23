#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QtNetwork>
#include <QtCore>
#include <QList>
#include <QString>
#include <algorithm>
#include <QProgressBar>
#include <QLabel>
using namespace std;
class DownloadManager: public QObject
{
    Q_OBJECT
public:
    explicit DownloadManager(QObject *parent = nullptr);

    void append(const QUrl &url);
    void append(const QStringList &urls);
    QString saveFileName(const QUrl &url);

    static QList<pair<QString,QString>> DownloadedList;
    QQueue<QUrl> downloadQueue;

    void setProgressBar( QProgressBar *value);
    void setLabelSpeed(QLabel *value);

signals:
    void finished();
    void oneDownloadFinished();

private slots:
    void startNextDownload();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);
    void downloadFinished();
    void downloadReadyRead();

private:
    bool isHttpRedirect() const;
    void reportRedirect();

    QProgressBar * progressBar;
    QLabel * labelSpeed;
    QNetworkAccessManager manager;
    QNetworkReply *currentDownload = nullptr;
    QFile output;
    QTime downloadTime;
    int downloadedCount = 0;
    int totalCount = 0;
};

#endif
