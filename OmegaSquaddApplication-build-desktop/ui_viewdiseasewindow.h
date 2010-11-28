/********************************************************************************
** Form generated from reading UI file 'viewdiseasewindow.ui'
**
** Created: Sun Nov 28 17:16:43 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWDISEASEWINDOW_H
#define UI_VIEWDISEASEWINDOW_H

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

class Ui_ViewDiseaseWindow
{
public:
    QAction *actionClose;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionMap;
    QAction *actionAdd_Disease;
    QAction *actionAdd_Supply;
    QAction *actionCreate_Shipment;
    QAction *actionManage_Shipment;
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

    void setupUi(QMainWindow *ViewDiseaseWindow)
    {
        if (ViewDiseaseWindow->objectName().isEmpty())
            ViewDiseaseWindow->setObjectName(QString::fromUtf8("ViewDiseaseWindow"));
        ViewDiseaseWindow->resize(800, 600);
        actionClose = new QAction(ViewDiseaseWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionZoom_In = new QAction(ViewDiseaseWindow);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        actionZoom_Out = new QAction(ViewDiseaseWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        actionMap = new QAction(ViewDiseaseWindow);
        actionMap->setObjectName(QString::fromUtf8("actionMap"));
        actionAdd_Disease = new QAction(ViewDiseaseWindow);
        actionAdd_Disease->setObjectName(QString::fromUtf8("actionAdd_Disease"));
        actionAdd_Supply = new QAction(ViewDiseaseWindow);
        actionAdd_Supply->setObjectName(QString::fromUtf8("actionAdd_Supply"));
        actionCreate_Shipment = new QAction(ViewDiseaseWindow);
        actionCreate_Shipment->setObjectName(QString::fromUtf8("actionCreate_Shipment"));
        actionManage_Shipment = new QAction(ViewDiseaseWindow);
        actionManage_Shipment->setObjectName(QString::fromUtf8("actionManage_Shipment"));
        actionView_Supplies = new QAction(ViewDiseaseWindow);
        actionView_Supplies->setObjectName(QString::fromUtf8("actionView_Supplies"));
        centralwidget = new QWidget(ViewDiseaseWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 30, 201, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 80, 501, 192));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 320, 161, 23));
        ViewDiseaseWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ViewDiseaseWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        ViewDiseaseWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ViewDiseaseWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ViewDiseaseWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionClose);
        menuFile->addAction(actionMap);
        menuFile->addAction(actionAdd_Disease);
        menuFile->addAction(actionAdd_Supply);
        menuFile->addAction(actionCreate_Shipment);
        menuFile->addAction(actionManage_Shipment);
        menuFile->addAction(actionView_Supplies);
        menuView->addAction(actionZoom_In);
        menuView->addAction(actionZoom_Out);

        retranslateUi(ViewDiseaseWindow);

        QMetaObject::connectSlotsByName(ViewDiseaseWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ViewDiseaseWindow)
    {
        ViewDiseaseWindow->setWindowTitle(QApplication::translate("ViewDiseaseWindow", "CET System", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("ViewDiseaseWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionZoom_In->setText(QApplication::translate("ViewDiseaseWindow", "Zoom In", 0, QApplication::UnicodeUTF8));
        actionZoom_Out->setText(QApplication::translate("ViewDiseaseWindow", "Zoom Out", 0, QApplication::UnicodeUTF8));
        actionMap->setText(QApplication::translate("ViewDiseaseWindow", "Map", 0, QApplication::UnicodeUTF8));
        actionAdd_Disease->setText(QApplication::translate("ViewDiseaseWindow", "Add Disease", 0, QApplication::UnicodeUTF8));
        actionAdd_Supply->setText(QApplication::translate("ViewDiseaseWindow", "Add Supply", 0, QApplication::UnicodeUTF8));
        actionCreate_Shipment->setText(QApplication::translate("ViewDiseaseWindow", "Create Shipment", 0, QApplication::UnicodeUTF8));
        actionManage_Shipment->setText(QApplication::translate("ViewDiseaseWindow", "Manage Shipment", 0, QApplication::UnicodeUTF8));
        actionView_Supplies->setText(QApplication::translate("ViewDiseaseWindow", "View Supplies", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ViewDiseaseWindow", "Diseases Data", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ViewDiseaseWindow", "Date", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ViewDiseaseWindow", "City", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ViewDiseaseWindow", "Disease", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ViewDiseaseWindow", "Number of Cases", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ViewDiseaseWindow", "Edit", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ViewDiseaseWindow", "Add New Disease Data", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("ViewDiseaseWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("ViewDiseaseWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("ViewDiseaseWindow", "View", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("ViewDiseaseWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewDiseaseWindow: public Ui_ViewDiseaseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWDISEASEWINDOW_H
