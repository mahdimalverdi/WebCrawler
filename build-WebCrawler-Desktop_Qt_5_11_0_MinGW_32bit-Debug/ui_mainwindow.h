/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QListWidget *listWidgetDownloadeds;
    QLabel *labelDownloadeds;
    QLabel *labelLinks;
    QLabel *label;
    QComboBox *comboBoxLevel;
    QLabel *labelWords;
    QListWidget *listWidgetFiltred;
    QLabel *labelFiles;
    QLineEdit *lineEditUrl;
    QPushButton *pushButtonDownload;
    QListWidget *listWidgetFiles;
    QPushButton *pushButtonSearch;
    QLabel *label_2;
    QLabel *labelFiltred;
    QListWidget *listWidgetLinks;
    QLineEdit *lineEditWords;
    QTextEdit *textEdit;
    QProgressBar *progressBar;
    QLabel *labelSpeed;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 433);
        MainWindow->setStyleSheet(QLatin1String("QWidget{\n"
"font: 8pt \"IRANSans\";\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        listWidgetDownloadeds = new QListWidget(centralWidget);
        listWidgetDownloadeds->setObjectName(QStringLiteral("listWidgetDownloadeds"));

        gridLayout->addWidget(listWidgetDownloadeds, 5, 4, 1, 2);

        labelDownloadeds = new QLabel(centralWidget);
        labelDownloadeds->setObjectName(QStringLiteral("labelDownloadeds"));

        gridLayout->addWidget(labelDownloadeds, 4, 4, 1, 2);

        labelLinks = new QLabel(centralWidget);
        labelLinks->setObjectName(QStringLiteral("labelLinks"));

        gridLayout->addWidget(labelLinks, 4, 3, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 8, 1, 1, 5);

        comboBoxLevel = new QComboBox(centralWidget);
        comboBoxLevel->setObjectName(QStringLiteral("comboBoxLevel"));
        comboBoxLevel->setEditable(false);

        gridLayout->addWidget(comboBoxLevel, 3, 4, 1, 1);

        labelWords = new QLabel(centralWidget);
        labelWords->setObjectName(QStringLiteral("labelWords"));

        gridLayout->addWidget(labelWords, 3, 3, 1, 1);

        listWidgetFiltred = new QListWidget(centralWidget);
        listWidgetFiltred->setObjectName(QStringLiteral("listWidgetFiltred"));

        gridLayout->addWidget(listWidgetFiltred, 5, 0, 1, 1);

        labelFiles = new QLabel(centralWidget);
        labelFiles->setObjectName(QStringLiteral("labelFiles"));

        gridLayout->addWidget(labelFiles, 4, 1, 1, 1);

        lineEditUrl = new QLineEdit(centralWidget);
        lineEditUrl->setObjectName(QStringLiteral("lineEditUrl"));

        gridLayout->addWidget(lineEditUrl, 0, 0, 1, 6);

        pushButtonDownload = new QPushButton(centralWidget);
        pushButtonDownload->setObjectName(QStringLiteral("pushButtonDownload"));

        gridLayout->addWidget(pushButtonDownload, 1, 0, 1, 6);

        listWidgetFiles = new QListWidget(centralWidget);
        listWidgetFiles->setObjectName(QStringLiteral("listWidgetFiles"));

        gridLayout->addWidget(listWidgetFiles, 5, 1, 1, 1);

        pushButtonSearch = new QPushButton(centralWidget);
        pushButtonSearch->setObjectName(QStringLiteral("pushButtonSearch"));

        gridLayout->addWidget(pushButtonSearch, 3, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 3, 5, 1, 1);

        labelFiltred = new QLabel(centralWidget);
        labelFiltred->setObjectName(QStringLiteral("labelFiltred"));

        gridLayout->addWidget(labelFiltred, 4, 0, 1, 1);

        listWidgetLinks = new QListWidget(centralWidget);
        listWidgetLinks->setObjectName(QStringLiteral("listWidgetLinks"));

        gridLayout->addWidget(listWidgetLinks, 5, 2, 1, 2);

        lineEditWords = new QLineEdit(centralWidget);
        lineEditWords->setObjectName(QStringLiteral("lineEditWords"));

        gridLayout->addWidget(lineEditWords, 3, 1, 1, 2);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 10, 0, 1, 6);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(100);
        progressBar->setTextVisible(true);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        gridLayout->addWidget(progressBar, 9, 0, 1, 5);

        labelSpeed = new QLabel(centralWidget);
        labelSpeed->setObjectName(QStringLiteral("labelSpeed"));

        gridLayout->addWidget(labelSpeed, 9, 5, 1, 1);

        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 2);
        gridLayout->setColumnStretch(4, 2);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        labelDownloadeds->setText(QApplication::translate("MainWindow", "\330\257\330\247\331\206\331\204\331\210\330\257 \330\264\330\257\331\207 \331\207\330\247", nullptr));
        labelLinks->setText(QApplication::translate("MainWindow", "\331\204\333\214\331\206\332\251 \331\207\330\247", nullptr));
        label->setText(QApplication::translate("MainWindow", "\330\257\330\247\331\206\331\204\331\210\330\257\333\214 \330\257\330\261 \330\254\330\261\333\214\330\247\331\206 \331\206\333\214\330\263\330\252", nullptr));
        comboBoxLevel->setCurrentText(QString());
        labelWords->setText(QApplication::translate("MainWindow", "\332\251\331\204\331\205\330\247\330\252 :", nullptr));
        labelFiles->setText(QApplication::translate("MainWindow", "\331\201\330\247\333\214\331\204 \331\207\330\247", nullptr));
        pushButtonDownload->setText(QApplication::translate("MainWindow", "\330\264\330\261\331\210\330\271 \331\276\333\214\331\205\330\247\333\214\330\264", nullptr));
        pushButtonSearch->setText(QApplication::translate("MainWindow", "\330\254\330\263\330\252 \331\210 \330\254\331\210", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\330\263\330\267\330\255 \330\254\330\263\330\252\330\254\331\210 :", nullptr));
        labelFiltred->setText(QApplication::translate("MainWindow", "\331\201\333\214\331\204\330\252\330\261 \330\264\330\257\331\207 \331\207\330\247", nullptr));
        labelSpeed->setText(QApplication::translate("MainWindow", "0 bytes/sec", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
