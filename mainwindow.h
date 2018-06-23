#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "downloadmanager.h"
#include <QUrl>
#include <QListWidgetItem>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    DownloadManager * manager;
    list<QString> listOfUrlsInLevels[11];
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void on_pushButtonDownload_clicked();
    void on_pushButtonSearch_clicked();
    void on_listWidgetDownloadeds_itemClicked(QListWidgetItem *item);
    void on_listWidgetFiltred_itemClicked(QListWidgetItem *item);
};

#endif // MAINWINDOW_H
