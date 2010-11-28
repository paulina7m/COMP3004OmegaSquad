/********************************************************************************
** Form generated from reading UI file 'manageshipmentswindow.ui'
**
** Created: Sun Nov 28 17:16:43 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGESHIPMENTSWINDOW_H
#define UI_MANAGESHIPMENTSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageShipmentsWindow
{
public:
    QAction *actionClose;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionMap;
    QAction *actionAdd_Disease;
    QAction *actionAdd_Supply;
    QAction *actionCreate_Shipment;
    QAction *actionView_Diseases;
    QAction *actionView_Supplies;
    QWidget *centralwidget;
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ManageShipmentsWindow)
    {
        if (ManageShipmentsWindow->objectName().isEmpty())
            ManageShipmentsWindow->setObjectName(QString::fromUtf8("ManageShipmentsWindow"));
        ManageShipmentsWindow->resize(841, 599);
        actionClose = new QAction(ManageShipmentsWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionZoom_In = new QAction(ManageShipmentsWindow);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        actionZoom_Out = new QAction(ManageShipmentsWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        actionMap = new QAction(ManageShipmentsWindow);
        actionMap->setObjectName(QString::fromUtf8("actionMap"));
        actionAdd_Disease = new QAction(ManageShipmentsWindow);
        actionAdd_Disease->setObjectName(QString::fromUtf8("actionAdd_Disease"));
        actionAdd_Supply = new QAction(ManageShipmentsWindow);
        actionAdd_Supply->setObjectName(QString::fromUtf8("actionAdd_Supply"));
        actionCreate_Shipment = new QAction(ManageShipmentsWindow);
        actionCreate_Shipment->setObjectName(QString::fromUtf8("actionCreate_Shipment"));
        actionView_Diseases = new QAction(ManageShipmentsWindow);
        actionView_Diseases->setObjectName(QString::fromUtf8("actionView_Diseases"));
        actionView_Supplies = new QAction(ManageShipmentsWindow);
        actionView_Supplies->setObjectName(QString::fromUtf8("actionView_Supplies"));
        centralwidget = new QWidget(ManageShipmentsWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 251, 41));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 100, 481, 192));
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 330, 121, 23));
        ManageShipmentsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ManageShipmentsWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 841, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        ManageShipmentsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ManageShipmentsWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ManageShipmentsWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionClose);
        menuFile->addAction(actionMap);
        menuFile->addAction(actionAdd_Disease);
        menuFile->addAction(actionAdd_Supply);
        menuFile->addAction(actionCreate_Shipment);
        menuFile->addAction(actionView_Diseases);
        menuFile->addAction(actionView_Supplies);
        menuView->addAction(actionZoom_In);
        menuView->addAction(actionZoom_Out);

        retranslateUi(ManageShipmentsWindow);

        QMetaObject::connectSlotsByName(ManageShipmentsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ManageShipmentsWindow)
    {
        ManageShipmentsWindow->setWindowTitle(QApplication::translate("ManageShipmentsWindow", "CET System", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("ManageShipmentsWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionZoom_In->setText(QApplication::translate("ManageShipmentsWindow", "Zoom In", 0, QApplication::UnicodeUTF8));
        actionZoom_Out->setText(QApplication::translate("ManageShipmentsWindow", "Zoom Out", 0, QApplication::UnicodeUTF8));
        actionMap->setText(QApplication::translate("ManageShipmentsWindow", "Map", 0, QApplication::UnicodeUTF8));
        actionAdd_Disease->setText(QApplication::translate("ManageShipmentsWindow", "Add Disease", 0, QApplication::UnicodeUTF8));
        actionAdd_Supply->setText(QApplication::translate("ManageShipmentsWindow", "Add Supply", 0, QApplication::UnicodeUTF8));
        actionCreate_Shipment->setText(QApplication::translate("ManageShipmentsWindow", "Create Shipment", 0, QApplication::UnicodeUTF8));
        actionView_Diseases->setText(QApplication::translate("ManageShipmentsWindow", "View Diseases", 0, QApplication::UnicodeUTF8));
        actionView_Supplies->setText(QApplication::translate("ManageShipmentsWindow", "View Supplies", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ManageShipmentsWindow", "Manage Shipments", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ManageShipmentsWindow", "From", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ManageShipmentsWindow", "To", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ManageShipmentsWindow", "Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ManageShipmentsWindow", "Quantity", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ManageShipmentsWindow", "Days to Ship", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ManageShipmentsWindow", "Sent", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("ManageShipmentsWindow", "Sent Date", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("ManageShipmentsWindow", "Expected Arrival Date", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("ManageShipmentsWindow", "Received", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("ManageShipmentsWindow", "Date Received", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ManageShipmentsWindow", "Create New Shipment", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("ManageShipmentsWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("ManageShipmentsWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("ManageShipmentsWindow", "View", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("ManageShipmentsWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ManageShipmentsWindow: public Ui_ManageShipmentsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGESHIPMENTSWINDOW_H
