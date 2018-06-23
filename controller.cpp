#include "controller.h"

#include "mainwindow.h"

Controller::Controller(QString Url, QListWidget *listWidgetDownloadeds, QListWidget *listWidgetFiles, QListWidget *listWidgetLinks, DownloadManager *manager, QLabel * label, int level)
{

    this->listWidgetDownloadeds=listWidgetDownloadeds;
    this->listWidgetFiles=listWidgetFiles;
    this->listWidgetLinks=listWidgetLinks;
    this->Url=Url;
    this->manager=manager;
    this->label=label;
    this->level=level;
    listWidgetDownloadeds->clear();
    listWidgetFiles->clear();
    listWidgetLinks->clear();
    manager->DownloadedList.clear();
    connect(manager,SIGNAL(oneDownloadFinished()),this,SLOT(updateListWidgetDownloadeds()));
    QObject::connect(manager, SIGNAL(finished()), this, SLOT(load()));

}

void Controller::setLabelSpeed(QLabel *value)
{
    labelSpeed = value;
}

void Controller::run()
{
    label->setText("در حال دانلود ...");
}

void Controller::load()
{
    listWidgetDownloadeds->clear();

    for(auto item:manager->DownloadedList)
        listWidgetDownloadeds->addItem(item.second);

    QFile file(manager->DownloadedList.back().second);
    QString baseUrl=manager->DownloadedList.back().first;

    if(!baseUrl.endsWith("//"))
        baseUrl+="//";

    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    file.open(QIODevice::ReadOnly);
    QString string=stream.readAll();

    string.replace(" ","");
    int start=string.indexOf("href=\"",0);
    while(string.indexOf("href=\"",start)!=-1)
    {
        QString url=string.mid(start+5,string.indexOf("\"",start+5)-start-5);
        if(!url.toLower().startsWith("http://") && !url.toLower().startsWith("https://"))
            url=baseUrl+url;

        url.replace("////","/");
        url.replace("///","/");
        url.replace("//","/");
        url.replace("http:/","http://");
        url.replace("https:/","https://");

        if(QFileInfo(url).suffix().isEmpty() || QFileInfo(url).suffix()=="html"||QFileInfo(url).suffix()=="php"||QFileInfo(url).suffix()=="asp" )
            listWidgetLinks->addItem(url);
        else
            listWidgetFiles->addItem(url);

        if(level>=0)
        {
            QUrl Url;
            Url.setUrl(url);
            manager->append(Url);
        }
        start=string.indexOf("href=\"",start)+1;
    }
    start=string.indexOf("src=\"",0);
    while(string.indexOf("src=\"",start)!=-1)
    {
        QString url=string.mid(start+4,string.indexOf("\"",start+4)-start-4);

        if(!url.toLower().startsWith("http://") && !url.toLower().startsWith("https://"))
            url=baseUrl+url;

        url.replace("////","/");
        url.replace("///","/");
        url.replace("//","/");
        url.replace("http:/","http://");
        url.replace("https:/","https://");

        if(QFileInfo(url).suffix().isEmpty() || QFileInfo(url).suffix()=="html"||QFileInfo(url).suffix()=="php"||QFileInfo(url).suffix()=="asp" )
            listWidgetLinks->addItem(url);
        else
            listWidgetFiles->addItem(url);

        if(level>=0)
        {
            QUrl Url;
            Url.setUrl(url);
            manager->append(Url);
        }
        start=string.indexOf("src=\"",start)+1;
    }
    if(manager->downloadQueue.isEmpty())
    {
        label->setText("دانلودی در جریان نیست.");
        labelSpeed->setText("0 bytes/sec");
    }
    else
        label->setText("در حال دانلود " + manager->downloadQueue.head().url());

}

void Controller::updateListWidgetDownloadeds()
{
    if(!manager->DownloadedList.isEmpty())
       listWidgetDownloadeds->addItem(manager->DownloadedList.back().second);
    if(!manager->downloadQueue.isEmpty())
        label->setText("...در حال دانلود " + manager->downloadQueue.head().url());

}
