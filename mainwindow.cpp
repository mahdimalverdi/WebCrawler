#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QString>
#include <QTextCodec>
#include "downloadmanager.h"
#include <QMessageBox>
#include <QFile>
#include <QDataStream>
#include <qtextstream.h>
#include <QDir>
#include <controller.h>
#include <filtercontroller.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBoxLevel->addItem("1");
    ui->comboBoxLevel->addItem("2");
    ui->comboBoxLevel->addItem("3");
    ui->comboBoxLevel->addItem("4");
    ui->comboBoxLevel->addItem("5");
    ui->comboBoxLevel->addItem("6");
    ui->comboBoxLevel->addItem("7");
    ui->comboBoxLevel->addItem("8");
    ui->comboBoxLevel->addItem("9");
    ui->comboBoxLevel->addItem("10");
    manager=new DownloadManager();
    manager->setProgressBar(ui->progressBar);
    manager->setLabelSpeed(ui->labelSpeed);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonDownload_clicked()
{
    QUrl Url;

    QString baseUrl=ui->lineEditUrl->text().toLower();
    Url.setUrl(baseUrl);

    manager->append(Url);
    Controller *c=new Controller(ui->lineEditUrl->text(),ui->listWidgetDownloadeds,ui->listWidgetFiles,ui->listWidgetLinks,manager,ui->label,ui->comboBoxLevel->currentIndex());
    c->setLabelSpeed(ui->labelSpeed);
    c->start();

}

void MainWindow::on_pushButtonSearch_clicked()
{
    FilterController *f=new FilterController(manager,ui->listWidgetFiltred,ui->lineEditWords->text());
    f->start();
}

void MainWindow::on_listWidgetDownloadeds_itemClicked(QListWidgetItem *item)
{
    QFile file(item->text());
    QTextStream stream(&file);
    file.open(QIODevice::ReadOnly);
    stream.setCodec("UTF-8");
    ui->textEdit->setText(stream.readAll());
}

void MainWindow::on_listWidgetFiltred_itemClicked(QListWidgetItem *item)
{

    QFile file(item->text());
    QTextStream stream(&file);
    file.open(QIODevice::ReadOnly);
    stream.setCodec("UTF-8");
    ui->textEdit->setText(stream.readAll());
}
