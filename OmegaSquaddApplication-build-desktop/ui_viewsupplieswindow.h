/********************************************************************************
** Form generated from reading UI file 'viewsupplieswindow.ui'
**
** Created: Sun Nov 28 17:16:43 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWSUPPLIESWINDOW_H
#define UI_VIEWSUPPLIESWINDOW_H

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

class Ui_ViewSuppliesWindow
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
    QAction *actionView_Diseases;
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

    void setupUi(QMainWindow *ViewSuppliesWindow)
    {
        if (ViewSuppliesWindow->objectName().isEmpty())
            ViewSuppliesWindow->setObjectName(QString::fromUtf8("ViewSuppliesWindow"));
        ViewSuppliesWindow->resize(800, 600);
        actionClose = new QAction(ViewSuppliesWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionZoom_In = new QAction(ViewSuppliesWindow);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        actionZoom_Out = new QAction(ViewSuppliesWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        actionMap = new QAction(ViewSuppliesWindow);
        actionMap->setObjectName(QString::fromUtf8("actionMap"));
        actionAdd_Disease = new QAction(ViewSuppliesWindow);
        actionAdd_Disease->setObjectName(QString::fromUtf8("actionAdd_Disease"));
        actionAdd_Supply = new QAction(ViewSuppliesWindow);
        actionAdd_Supply->setObjectName(QString::fromUtf8("actionAdd_Supply"));
        actionCreate_Shipment = new QAction(ViewSuppliesWindow);
        actionCreate_Shipment->setObjectName(QString::fromUtf8("actionCreate_Shipment"));
        actionManage_Shipment = new QAction(ViewSuppliesWindow);
        actionManage_Shipment->setObjectName(QString::fromUtf8("actionManage_Shipment"));
        actionView_Diseases = new QAction(ViewSuppliesWindow);
        actionView_Diseases->setObjectName(QString::fromUtf8("actionView_Diseases"));
        centralwidget = new QWidget(ViewSuppliesWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 30, 221, 51));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QFont font1;
        font1.setPointSize(8);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(50, 140, 401, 161));
        tableWidget->setMinimumSize(QSize(401, 0));
        tableWidget->setMaximumSize(QSize(401, 16777215));
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget->horizontalHeader()->setMinimumSectionSize(27);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 350, 131, 23));
        ViewSuppliesWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ViewSuppliesWindow);
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
        ViewSuppliesWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ViewSuppliesWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ViewSuppliesWindow->setStatusBar(statusbar);

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
        menuFile->addAction(actionView_Diseases);
        menuView->addAction(actionZoom_In);
        menuView->addAction(actionZoom_Out);

        retranslateUi(ViewSuppliesWindow);

        QMetaObject::connectSlotsByName(ViewSuppliesWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ViewSuppliesWindow)
    {
        ViewSuppliesWindow->setWindowTitle(QApplication::translate("ViewSuppliesWindow", "CET System", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("ViewSuppliesWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionZoom_In->setText(QApplication::translate("ViewSuppliesWindow", "Zoom In", 0, QApplication::UnicodeUTF8));
        actionZoom_Out->setText(QApplication::translate("ViewSuppliesWindow", "Zoom Out", 0, QApplication::UnicodeUTF8));
        actionMap->setText(QApplication::translate("ViewSuppliesWindow", "Map", 0, QApplication::UnicodeUTF8));
        actionAdd_Disease->setText(QApplication::translate("ViewSuppliesWindow", "Add Disease", 0, QApplication::UnicodeUTF8));
        actionAdd_Supply->setText(QApplication::translate("ViewSuppliesWindow", "Add Supply", 0, QApplication::UnicodeUTF8));
        actionCreate_Shipment->setText(QApplication::translate("ViewSuppliesWindow", "Create Shipment", 0, QApplication::UnicodeUTF8));
        actionManage_Shipment->setText(QApplication::translate("ViewSuppliesWindow", "Manage Shipment", 0, QApplication::UnicodeUTF8));
        actionView_Diseases->setText(QApplication::translate("ViewSuppliesWindow", "View Diseases", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ViewSuppliesWindow", "Supplies Data", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ViewSuppliesWindow", "City", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ViewSuppliesWindow", "Types of Supplies", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ViewSuppliesWindow", "Number of Supplies", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ViewSuppliesWindow", "Edit", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ViewSuppliesWindow", "Add New Supply Data", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("ViewSuppliesWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("ViewSuppliesWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("ViewSuppliesWindow", "View", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("ViewSuppliesWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewSuppliesWindow: public Ui_ViewSuppliesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWSUPPLIESWINDOW_H
