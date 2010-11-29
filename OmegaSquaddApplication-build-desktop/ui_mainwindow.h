/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Nov 28 19:40:54 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_CET;
    QAction *actionDelete;
    QAction *actionOpen;
    QAction *actionShipments;
    QAction *actionAdd_Disease_Data;
    QAction *actionAdd_Supplies_Data;
    QAction *actionAdd_New_Shipment;
    QAction *actionManage_Shipments;
    QAction *actionSupplies_Data;
    QAction *actionShipments_2;
    QAction *actionMap;
    QAction *actionClose;
    QAction *actionTabular_Diseases_Data;
    QWidget *centralWidget;
    QLabel *label;
    QComboBox *e_s_selector;
    QComboBox *type_selector;
    QWebView *mapView;
    QGroupBox *groupBox;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *namebox;
    QTextEdit *idbox;
    QLabel *numberof_label;
    QTextEdit *numberofbox;
    QPushButton *pushButton;
    QTextEdit *loadinglabel;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuHelp;
    QMenu *menuEnter_New_Data;
    QMenu *menuShipments;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(998, 583);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionAbout_CET = new QAction(MainWindow);
        actionAbout_CET->setObjectName(QString::fromUtf8("actionAbout_CET"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionShipments = new QAction(MainWindow);
        actionShipments->setObjectName(QString::fromUtf8("actionShipments"));
        actionAdd_Disease_Data = new QAction(MainWindow);
        actionAdd_Disease_Data->setObjectName(QString::fromUtf8("actionAdd_Disease_Data"));
        actionAdd_Supplies_Data = new QAction(MainWindow);
        actionAdd_Supplies_Data->setObjectName(QString::fromUtf8("actionAdd_Supplies_Data"));
        actionAdd_New_Shipment = new QAction(MainWindow);
        actionAdd_New_Shipment->setObjectName(QString::fromUtf8("actionAdd_New_Shipment"));
        actionManage_Shipments = new QAction(MainWindow);
        actionManage_Shipments->setObjectName(QString::fromUtf8("actionManage_Shipments"));
        actionSupplies_Data = new QAction(MainWindow);
        actionSupplies_Data->setObjectName(QString::fromUtf8("actionSupplies_Data"));
        actionShipments_2 = new QAction(MainWindow);
        actionShipments_2->setObjectName(QString::fromUtf8("actionShipments_2"));
        actionMap = new QAction(MainWindow);
        actionMap->setObjectName(QString::fromUtf8("actionMap"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionTabular_Diseases_Data = new QAction(MainWindow);
        actionTabular_Diseases_Data->setObjectName(QString::fromUtf8("actionTabular_Diseases_Data"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMouseTracking(false);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(15, 60, 91, 16));
        e_s_selector = new QComboBox(centralWidget);
        e_s_selector->setObjectName(QString::fromUtf8("e_s_selector"));
        e_s_selector->setGeometry(QRect(10, 80, 171, 26));
        type_selector = new QComboBox(centralWidget);
        type_selector->setObjectName(QString::fromUtf8("type_selector"));
        type_selector->setGeometry(QRect(10, 110, 171, 26));
        mapView = new QWebView(centralWidget);
        mapView->setObjectName(QString::fromUtf8("mapView"));
        mapView->setGeometry(QRect(190, 40, 781, 461));
        mapView->setMouseTracking(true);
        mapView->setUrl(QUrl("about:blank"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 150, 171, 351));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 30, 121, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 130, 101, 16));
        namebox = new QTextEdit(groupBox);
        namebox->setObjectName(QString::fromUtf8("namebox"));
        namebox->setEnabled(false);
        namebox->setGeometry(QRect(10, 50, 151, 71));
        idbox = new QTextEdit(groupBox);
        idbox->setObjectName(QString::fromUtf8("idbox"));
        idbox->setEnabled(false);
        idbox->setGeometry(QRect(10, 150, 151, 31));
        numberof_label = new QLabel(groupBox);
        numberof_label->setObjectName(QString::fromUtf8("numberof_label"));
        numberof_label->setGeometry(QRect(10, 190, 131, 16));
        numberofbox = new QTextEdit(groupBox);
        numberofbox->setObjectName(QString::fromUtf8("numberofbox"));
        numberofbox->setEnabled(false);
        numberofbox->setGeometry(QRect(10, 210, 151, 31));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 300, 114, 32));
        loadinglabel = new QTextEdit(centralWidget);
        loadinglabel->setObjectName(QString::fromUtf8("loadinglabel"));
        loadinglabel->setEnabled(false);
        loadinglabel->setGeometry(QRect(480, 180, 201, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 998, 21));
        menuBar->setNativeMenuBar(false);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuEnter_New_Data = new QMenu(menuBar);
        menuEnter_New_Data->setObjectName(QString::fromUtf8("menuEnter_New_Data"));
        menuShipments = new QMenu(menuBar);
        menuShipments->setObjectName(QString::fromUtf8("menuShipments"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEnter_New_Data->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuShipments->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionClose);
        menuView->addAction(actionSupplies_Data);
        menuView->addAction(actionTabular_Diseases_Data);
        menuHelp->addAction(actionAbout_CET);
        menuEnter_New_Data->addAction(actionAdd_Disease_Data);
        menuEnter_New_Data->addAction(actionAdd_Supplies_Data);
        menuShipments->addAction(actionAdd_New_Shipment);
        menuShipments->addAction(actionManage_Shipments);

        retranslateUi(MainWindow);
        QObject::connect(actionClose, SIGNAL(activated()), MainWindow, SLOT(close()));
        QObject::connect(actionAdd_Disease_Data, SIGNAL(activated()), MainWindow, SLOT(AddDiseaseHandler()));
        QObject::connect(actionAdd_Supplies_Data, SIGNAL(activated()), MainWindow, SLOT(AddSupplyHandler()));
        QObject::connect(actionTabular_Diseases_Data, SIGNAL(activated()), MainWindow, SLOT(ViewDiseasesHandler()));
        QObject::connect(actionSupplies_Data, SIGNAL(activated()), MainWindow, SLOT(ViewSuppliesHandler()));
        QObject::connect(actionAdd_New_Shipment, SIGNAL(activated()), MainWindow, SLOT(AddShipmentHandler()));
        QObject::connect(actionManage_Shipments, SIGNAL(activated()), MainWindow, SLOT(ManageShipmentsHandler()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "The Canadian Epidemic Tracker", 0, QApplication::UnicodeUTF8));
        actionAbout_CET->setText(QApplication::translate("MainWindow", "About CET", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionShipments->setText(QApplication::translate("MainWindow", "Tabular Disease Data", 0, QApplication::UnicodeUTF8));
        actionAdd_Disease_Data->setText(QApplication::translate("MainWindow", "Disease Data", 0, QApplication::UnicodeUTF8));
        actionAdd_Supplies_Data->setText(QApplication::translate("MainWindow", "Supplies Data", 0, QApplication::UnicodeUTF8));
        actionAdd_New_Shipment->setText(QApplication::translate("MainWindow", "Add New Shipment", 0, QApplication::UnicodeUTF8));
        actionManage_Shipments->setText(QApplication::translate("MainWindow", "Manage Shipments", 0, QApplication::UnicodeUTF8));
        actionSupplies_Data->setText(QApplication::translate("MainWindow", "Tabular Supplies Data", 0, QApplication::UnicodeUTF8));
        actionShipments_2->setText(QApplication::translate("MainWindow", "Shipments Manager", 0, QApplication::UnicodeUTF8));
        actionMap->setText(QApplication::translate("MainWindow", "Map", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionTabular_Diseases_Data->setText(QApplication::translate("MainWindow", "Tabular Diseases Data", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Show data for:", 0, QApplication::UnicodeUTF8));
        e_s_selector->clear();
        e_s_selector->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Epidemics", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Supplies", 0, QApplication::UnicodeUTF8)
        );
        type_selector->clear();
        type_selector->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "H1N1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Small Pox", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "HIV", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Plague", 0, QApplication::UnicodeUTF8)
        );
        groupBox->setTitle(QApplication::translate("MainWindow", "Health Unit Information:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Name:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "ID:", 0, QApplication::UnicodeUTF8));
        numberof_label->setText(QApplication::translate("MainWindow", "Number of Cases:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Edit Data", 0, QApplication::UnicodeUTF8));
        loadinglabel->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Lucida Grande'; font-size:13pt;\">Loading Health Unit Zones...</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        menuEnter_New_Data->setTitle(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
        menuShipments->setTitle(QApplication::translate("MainWindow", "Shipping", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
