/********************************************************************************
** Form generated from reading UI file 'addsupplywindow.ui'
**
** Created: Sun Nov 28 17:16:43 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSUPPLYWINDOW_H
#define UI_ADDSUPPLYWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddSupplyWindow
{
public:
    QAction *actionClose;
    QAction *actionZoom_in;
    QAction *actionZoom_out;
    QAction *actionMap;
    QAction *actionAdd_Disease;
    QAction *actionCreate_Shipment;
    QAction *actionManage_Shipment;
    QAction *actionView_Diseases;
    QAction *actionView_Supplies;
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QCalendarWidget *calendarWidget;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QLabel *label_5;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddSupplyWindow)
    {
        if (AddSupplyWindow->objectName().isEmpty())
            AddSupplyWindow->setObjectName(QString::fromUtf8("AddSupplyWindow"));
        AddSupplyWindow->resize(800, 600);
        actionClose = new QAction(AddSupplyWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionZoom_in = new QAction(AddSupplyWindow);
        actionZoom_in->setObjectName(QString::fromUtf8("actionZoom_in"));
        actionZoom_out = new QAction(AddSupplyWindow);
        actionZoom_out->setObjectName(QString::fromUtf8("actionZoom_out"));
        actionMap = new QAction(AddSupplyWindow);
        actionMap->setObjectName(QString::fromUtf8("actionMap"));
        actionAdd_Disease = new QAction(AddSupplyWindow);
        actionAdd_Disease->setObjectName(QString::fromUtf8("actionAdd_Disease"));
        actionCreate_Shipment = new QAction(AddSupplyWindow);
        actionCreate_Shipment->setObjectName(QString::fromUtf8("actionCreate_Shipment"));
        actionManage_Shipment = new QAction(AddSupplyWindow);
        actionManage_Shipment->setObjectName(QString::fromUtf8("actionManage_Shipment"));
        actionView_Diseases = new QAction(AddSupplyWindow);
        actionView_Diseases->setObjectName(QString::fromUtf8("actionView_Diseases"));
        actionView_Supplies = new QAction(AddSupplyWindow);
        actionView_Supplies->setObjectName(QString::fromUtf8("actionView_Supplies"));
        centralwidget = new QWidget(AddSupplyWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 90, 46, 13));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 90, 113, 20));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(30, 120, 256, 155));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 300, 46, 13));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 330, 46, 13));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 370, 71, 16));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 360, 113, 20));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(90, 300, 121, 22));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(90, 330, 121, 22));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(390, 320, 75, 23));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 30, 301, 31));
        QFont font;
        font.setPointSize(20);
        label_5->setFont(font);
        AddSupplyWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddSupplyWindow);
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
        AddSupplyWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AddSupplyWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AddSupplyWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionClose);
        menuFile->addAction(actionMap);
        menuFile->addAction(actionAdd_Disease);
        menuFile->addAction(actionCreate_Shipment);
        menuFile->addAction(actionManage_Shipment);
        menuFile->addAction(actionView_Diseases);
        menuFile->addAction(actionView_Supplies);
        menuView->addAction(actionZoom_in);
        menuView->addAction(actionZoom_out);

        retranslateUi(AddSupplyWindow);
        QObject::connect(actionClose, SIGNAL(activated()), AddSupplyWindow, SLOT(close()));
        QObject::connect(actionMap, SIGNAL(activated()), AddSupplyWindow, SLOT(MapHandler()));
        QObject::connect(actionAdd_Disease, SIGNAL(activated()), AddSupplyWindow, SLOT(AddDiseaseHandler()));
        QObject::connect(actionCreate_Shipment, SIGNAL(activated()), AddSupplyWindow, SLOT(CreateShipmentHandler()));
        QObject::connect(actionManage_Shipment, SIGNAL(activated()), AddSupplyWindow, SLOT(ManageShipmentHandler()));

        QMetaObject::connectSlotsByName(AddSupplyWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AddSupplyWindow)
    {
        AddSupplyWindow->setWindowTitle(QApplication::translate("AddSupplyWindow", "CET System", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("AddSupplyWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionZoom_in->setText(QApplication::translate("AddSupplyWindow", "Zoom In", 0, QApplication::UnicodeUTF8));
        actionZoom_out->setText(QApplication::translate("AddSupplyWindow", "Zoom Out", 0, QApplication::UnicodeUTF8));
        actionMap->setText(QApplication::translate("AddSupplyWindow", "Map", 0, QApplication::UnicodeUTF8));
        actionAdd_Disease->setText(QApplication::translate("AddSupplyWindow", "Add Disease", 0, QApplication::UnicodeUTF8));
        actionCreate_Shipment->setText(QApplication::translate("AddSupplyWindow", "Create Shipment", 0, QApplication::UnicodeUTF8));
        actionManage_Shipment->setText(QApplication::translate("AddSupplyWindow", "Manage Shipment", 0, QApplication::UnicodeUTF8));
        actionView_Diseases->setText(QApplication::translate("AddSupplyWindow", "View Diseases", 0, QApplication::UnicodeUTF8));
        actionView_Supplies->setText(QApplication::translate("AddSupplyWindow", "View Supplies", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddSupplyWindow", "Date:", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("AddSupplyWindow", "DD/MM/YYYY", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddSupplyWindow", "City:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddSupplyWindow", "Disease:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AddSupplyWindow", "# of Supplies:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AddSupplyWindow", "Submit", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AddSupplyWindow", "Supplies Data Entry Form", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("AddSupplyWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("AddSupplyWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("AddSupplyWindow", "View", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("AddSupplyWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddSupplyWindow: public Ui_AddSupplyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSUPPLYWINDOW_H
