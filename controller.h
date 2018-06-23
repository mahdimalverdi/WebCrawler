#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QThread>
#include <QList>
#include <QString>
#include <downloadmanager.h>
#include <QListWidget>
#include <QLabel>

class Controller: public QThread
{
    Q_OBJECT
public:
    Controller(QString Url,QListWidget * listWidgetDownloadeds,QListWidget * listWidgetFiles,QListWidget * listWidgetLinks,DownloadManager * manager,QLabel * label,int level);
    void setLabelSpeed(QLabel *value);

private:
    QString Url;
    DownloadManager * manager;
    QList<QString> * listOfUrlsInLevels;
    QListWidget * listWidgetDownloadeds;
    QListWidget * listWidgetFiles;
    QListWidget * listWidgetLinks;
    QLabel * label;
    QLabel * labelSpeed;
    int level=2;
protected:
    void run();
private slots:
    void load();
    void updateListWidgetDownloadeds();
signals:
    void resultReady();
};

#endif // CONTROLLER_H
