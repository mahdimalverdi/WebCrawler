#include "filtercontroller.h"


FilterController::FilterController(DownloadManager *manager, QListWidget *listWidgetFiltered, QString Words)
{
    this->manager=manager;
    this->listWidgetFiltered=listWidgetFiltered;
    this->Word=Words.replace(" ","");
}

void FilterController::run()
{
    listWidgetFiltered->clear();
    for(auto url:manager->DownloadedList)
    {
        bool flag=true;
        QFile file(url.second);
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        file.open(QIODevice::ReadOnly);
        QString string=stream.readAll();
        for(auto item:Word.split("-"))
        {
            if(!string.contains(item))
                flag=false;
        }
        if(flag)
            listWidgetFiltered->addItem(url.second);
    }
}
