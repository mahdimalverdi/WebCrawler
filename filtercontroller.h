#ifndef FILTERCONTROLLER_H
#define FILTERCONTROLLER_H
#include <QThread>
#include <downloadmanager.h>
#include <QListWidget>
#include <QString>
class FilterController : public QThread
{
public:
    FilterController(DownloadManager * manager,QListWidget * listWidgetFiltered,QString Words);
private:
    DownloadManager * manager;
    QListWidget * listWidgetFiltered;
    QString Word;
protected:
    void run();
};

#endif // FILTERCONTROLLER_H
