/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAndGate;
    QAction *actionOrGate;
    QAction *actionInverter;
    QAction *actionWire;
    QAction *actionNandGate;
    QAction *actionNorGate;
    QAction *actionXorGate;
    QAction *actionXnorGate;
    QAction *actionClear;
    QAction *actionDelete;
    QAction *actionInputGate;
    QAction *actionMENU;
    QWidget *centralwidget;
    QPushButton *startButton;
    QTextEdit *textEdit;
    QPushButton *EvaluateButton;
    QPushButton *menuButton;
    QLabel *truthTableTitle;
    QTableWidget *previewTableWidget;
    QWidget *truthTableContainer;
    QLabel *tipDescription;
    QWidget *gridLayoutWidget;
    QGridLayout *LevelsGrid;
    QPushButton *ButtonLevel8;
    QPushButton *ButtonLevel12;
    QPushButton *ButtonLevel10;
    QPushButton *ButtonLevel9;
    QPushButton *ButtonLevel11;
    QPushButton *ButtonLevel7;
    QPushButton *ButtonLevel1;
    QPushButton *ButtonLevel2;
    QPushButton *ButtonLevel3;
    QPushButton *ButtonLevel4;
    QPushButton *ButtonLevel5;
    QPushButton *ButtonLevel6;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1440, 900);
        MainWindow->setMinimumSize(QSize(1280, 800));
        actionAndGate = new QAction(MainWindow);
        actionAndGate->setObjectName("actionAndGate");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/GATES/AND.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionAndGate->setIcon(icon);
        actionAndGate->setMenuRole(QAction::MenuRole::NoRole);
        actionOrGate = new QAction(MainWindow);
        actionOrGate->setObjectName("actionOrGate");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/GATES/OR.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionOrGate->setIcon(icon1);
        actionOrGate->setMenuRole(QAction::MenuRole::NoRole);
        actionInverter = new QAction(MainWindow);
        actionInverter->setObjectName("actionInverter");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/GATES/NOT.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionInverter->setIcon(icon2);
        actionInverter->setMenuRole(QAction::MenuRole::NoRole);
        actionWire = new QAction(MainWindow);
        actionWire->setObjectName("actionWire");
        actionWire->setCheckable(true);
        actionWire->setMenuRole(QAction::MenuRole::NoRole);
        actionNandGate = new QAction(MainWindow);
        actionNandGate->setObjectName("actionNandGate");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/GATES/NAND.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNandGate->setIcon(icon3);
        actionNandGate->setMenuRole(QAction::MenuRole::NoRole);
        actionNorGate = new QAction(MainWindow);
        actionNorGate->setObjectName("actionNorGate");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/GATES/NOR.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNorGate->setIcon(icon4);
        actionNorGate->setMenuRole(QAction::MenuRole::NoRole);
        actionXorGate = new QAction(MainWindow);
        actionXorGate->setObjectName("actionXorGate");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/GATES/XOR.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionXorGate->setIcon(icon5);
        actionXorGate->setMenuRole(QAction::MenuRole::NoRole);
        actionXnorGate = new QAction(MainWindow);
        actionXnorGate->setObjectName("actionXnorGate");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/GATES/XNOR.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionXnorGate->setIcon(icon6);
        actionXnorGate->setMenuRole(QAction::MenuRole::NoRole);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName("actionClear");
        QIcon icon7(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        actionClear->setIcon(icon7);
        actionClear->setMenuRole(QAction::MenuRole::NoRole);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName("actionDelete");
        actionDelete->setCheckable(true);
        actionDelete->setMenuRole(QAction::MenuRole::NoRole);
        actionInputGate = new QAction(MainWindow);
        actionInputGate->setObjectName("actionInputGate");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/GATES/INPUT-OFF.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionInputGate->setIcon(icon8);
        actionInputGate->setMenuRole(QAction::MenuRole::NoRole);
        actionMENU = new QAction(MainWindow);
        actionMENU->setObjectName("actionMENU");
        actionMENU->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(575, 340, 290, 90));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        startButton->setFont(font);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(370, 80, 700, 240));
        EvaluateButton = new QPushButton(centralwidget);
        EvaluateButton->setObjectName("EvaluateButton");
        EvaluateButton->setGeometry(QRect(1100, 780, 280, 70));
        menuButton = new QPushButton(centralwidget);
        menuButton->setObjectName("menuButton");
        menuButton->setGeometry(QRect(1280, 15, 140, 50));
        truthTableTitle = new QLabel(centralwidget);
        truthTableTitle->setObjectName("truthTableTitle");
        truthTableTitle->setGeometry(QRect(520, 90, 400, 40));
        truthTableTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);
        previewTableWidget = new QTableWidget(centralwidget);
        previewTableWidget->setObjectName("previewTableWidget");
        previewTableWidget->setGeometry(QRect(520, 140, 420, 470));
        truthTableContainer = new QWidget(centralwidget);
        truthTableContainer->setObjectName("truthTableContainer");
        truthTableContainer->setGeometry(QRect(510, 85, 420, 550));
        tipDescription = new QLabel(centralwidget);
        tipDescription->setObjectName("tipDescription");
        tipDescription->setGeometry(QRect(520, 30, 380, 50));
        tipDescription->setAlignment(Qt::AlignmentFlag::AlignCenter);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(320, 430, 800, 480));
        LevelsGrid = new QGridLayout(gridLayoutWidget);
        LevelsGrid->setSpacing(12);
        LevelsGrid->setObjectName("LevelsGrid");
        LevelsGrid->setContentsMargins(10, 10, 10, 10);
        ButtonLevel8 = new QPushButton(gridLayoutWidget);
        ButtonLevel8->setObjectName("ButtonLevel8");

        LevelsGrid->addWidget(ButtonLevel8, 1, 1, 1, 1);

        ButtonLevel12 = new QPushButton(gridLayoutWidget);
        ButtonLevel12->setObjectName("ButtonLevel12");

        LevelsGrid->addWidget(ButtonLevel12, 5, 1, 1, 1);

        ButtonLevel10 = new QPushButton(gridLayoutWidget);
        ButtonLevel10->setObjectName("ButtonLevel10");

        LevelsGrid->addWidget(ButtonLevel10, 3, 1, 1, 1);

        ButtonLevel9 = new QPushButton(gridLayoutWidget);
        ButtonLevel9->setObjectName("ButtonLevel9");

        LevelsGrid->addWidget(ButtonLevel9, 2, 1, 1, 1);

        ButtonLevel11 = new QPushButton(gridLayoutWidget);
        ButtonLevel11->setObjectName("ButtonLevel11");

        LevelsGrid->addWidget(ButtonLevel11, 4, 1, 1, 1);

        ButtonLevel7 = new QPushButton(gridLayoutWidget);
        ButtonLevel7->setObjectName("ButtonLevel7");

        LevelsGrid->addWidget(ButtonLevel7, 0, 1, 1, 1);

        ButtonLevel1 = new QPushButton(gridLayoutWidget);
        ButtonLevel1->setObjectName("ButtonLevel1");

        LevelsGrid->addWidget(ButtonLevel1, 0, 0, 1, 1);

        ButtonLevel2 = new QPushButton(gridLayoutWidget);
        ButtonLevel2->setObjectName("ButtonLevel2");

        LevelsGrid->addWidget(ButtonLevel2, 1, 0, 1, 1);

        ButtonLevel3 = new QPushButton(gridLayoutWidget);
        ButtonLevel3->setObjectName("ButtonLevel3");

        LevelsGrid->addWidget(ButtonLevel3, 2, 0, 1, 1);

        ButtonLevel4 = new QPushButton(gridLayoutWidget);
        ButtonLevel4->setObjectName("ButtonLevel4");

        LevelsGrid->addWidget(ButtonLevel4, 3, 0, 1, 1);

        ButtonLevel5 = new QPushButton(gridLayoutWidget);
        ButtonLevel5->setObjectName("ButtonLevel5");

        LevelsGrid->addWidget(ButtonLevel5, 4, 0, 1, 1);

        ButtonLevel6 = new QPushButton(gridLayoutWidget);
        ButtonLevel6->setObjectName("ButtonLevel6");

        LevelsGrid->addWidget(ButtonLevel6, 5, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1440, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::LeftToolBarArea, toolBar);

        toolBar->addAction(actionWire);
        toolBar->addAction(actionDelete);
        toolBar->addAction(actionClear);
        toolBar->addAction(actionInverter);
        toolBar->addAction(actionOrGate);
        toolBar->addAction(actionAndGate);
        toolBar->addAction(actionNorGate);
        toolBar->addAction(actionNandGate);
        toolBar->addAction(actionXorGate);
        toolBar->addAction(actionXnorGate);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Circuit Builder - Educational Logic Gate Simulator", nullptr));
        actionAndGate->setText(QCoreApplication::translate("MainWindow", "AndGate", nullptr));
        actionOrGate->setText(QCoreApplication::translate("MainWindow", "OrGate", nullptr));
        actionInverter->setText(QCoreApplication::translate("MainWindow", "Inverter", nullptr));
        actionWire->setText(QCoreApplication::translate("MainWindow", "WIRE\n"
"MODE", nullptr));
        actionNandGate->setText(QCoreApplication::translate("MainWindow", "NandGate", nullptr));
        actionNorGate->setText(QCoreApplication::translate("MainWindow", "NorGate", nullptr));
        actionXorGate->setText(QCoreApplication::translate("MainWindow", "XorGate", nullptr));
        actionXnorGate->setText(QCoreApplication::translate("MainWindow", "XnorGate", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "CLEAR\n"
"ALL", nullptr));
        actionDelete->setText(QCoreApplication::translate("MainWindow", "X\n"
"DELETE", nullptr));
        actionInputGate->setText(QCoreApplication::translate("MainWindow", "InputGate", nullptr));
        actionMENU->setText(QCoreApplication::translate("MainWindow", "MENU", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "START GAME", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:20px; margin-bottom:5px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:42pt; font-weight:700; color:#00b4d8;\">CIRCUIT BUILDER</span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:10px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:18pt; font-weight:600; color:#2d3748;\">Master Digital Logic Throu"
                        "gh Interactive Design</span></p>\n"
"<p align=\"center\" style=\" margin-top:16px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:15pt; font-weight:600; color:#0096c7;\">Select a Level Below or Click Start Game</span></p>\n"
"<p align=\"center\" style=\" margin-top:10px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:14pt; color:#4a5568;\">12 Progressive Levels - Easy to Expert</span></p>\n"
"<p align=\"center\" style=\" margin-top:6px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Segoe UI'; font-size:14pt; color:#4a5568;\">AND - OR - NOT - NAND - NOR - XOR - XNOR</span></p></body></html>", nullptr));
        EvaluateButton->setText(QCoreApplication::translate("MainWindow", "Evaluate Circuit", nullptr));
        menuButton->setText(QCoreApplication::translate("MainWindow", "MENU", nullptr));
        truthTableTitle->setText(QCoreApplication::translate("MainWindow", "TRUTH TABLE", nullptr));
        tipDescription->setText(QString());
        ButtonLevel8->setText(QCoreApplication::translate("MainWindow", "LEVEL 8", nullptr));
        ButtonLevel12->setText(QCoreApplication::translate("MainWindow", "LEVEL 12", nullptr));
        ButtonLevel10->setText(QCoreApplication::translate("MainWindow", "LEVEL 10", nullptr));
        ButtonLevel9->setText(QCoreApplication::translate("MainWindow", "LEVEL 9", nullptr));
        ButtonLevel11->setText(QCoreApplication::translate("MainWindow", "LEVEL 11", nullptr));
        ButtonLevel7->setText(QCoreApplication::translate("MainWindow", "LEVEL 7", nullptr));
        ButtonLevel1->setText(QCoreApplication::translate("MainWindow", "LEVEL 1", nullptr));
        ButtonLevel2->setText(QCoreApplication::translate("MainWindow", "LEVEL 2", nullptr));
        ButtonLevel3->setText(QCoreApplication::translate("MainWindow", "LEVEL 3", nullptr));
        ButtonLevel4->setText(QCoreApplication::translate("MainWindow", "LEVEL 4", nullptr));
        ButtonLevel5->setText(QCoreApplication::translate("MainWindow", "LEVEL 5", nullptr));
        ButtonLevel6->setText(QCoreApplication::translate("MainWindow", "LEVEL 6", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
