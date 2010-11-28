/********************************************************************************
** Form generated from reading UI file 'createshipmentwindow.ui'
**
** Created: Sun Nov 28 17:16:43 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESHIPMENTWINDOW_H
#define UI_CREATESHIPMENTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
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

class Ui_CreateShipmentWindow
{
public:
    QAction *actionClose;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionMap;
    QAction *actionAdd_Disease;
    QAction *actionAdd_Supply;
    QAction *actionCreat_Shipment;
    QAction *actionManage_Shipment;
    QAction *actionView_Diseases;
    QAction *actionView_Supplies;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CreateShipmentWindow)
    {
        if (CreateShipmentWindow->objectName().isEmpty())
            CreateShipmentWindow->setObjectName(QString::fromUtf8("CreateShipmentWindow"));
        CreateShipmentWindow->resize(800, 600);
        actionClose = new QAction(CreateShipmentWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionZoom_In = new QAction(CreateShipmentWindow);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        actionZoom_Out = new QAction(CreateShipmentWindow);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        actionMap = new QAction(CreateShipmentWindow);
        actionMap->setObjectName(QString::fromUtf8("actionMap"));
        actionAdd_Disease = new QAction(CreateShipmentWindow);
        actionAdd_Disease->setObjectName(QString::fromUtf8("actionAdd_Disease"));
        actionAdd_Supply = new QAction(CreateShipmentWindow);
        actionAdd_Supply->setObjectName(QString::fromUtf8("actionAdd_Supply"));
        actionCreat_Shipment = new QAction(CreateShipmentWindow);
        actionCreat_Shipment->setObjectName(QString::fromUtf8("actionCreat_Shipment"));
        actionManage_Shipment = new QAction(CreateShipmentWindow);
        actionManage_Shipment->setObjectName(QString::fromUtf8("actionManage_Shipment"));
        actionView_Diseases = new QAction(CreateShipmentWindow);
        actionView_Diseases->setObjectName(QString::fromUtf8("actionView_Diseases"));
        actionView_Supplies = new QAction(CreateShipmentWindow);
        actionView_Supplies->setObjectName(QString::fromUtf8("actionView_Supplies"));
        centralwidget = new QWidget(CreateShipmentWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 50, 251, 41));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 170, 46, 13));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 190, 46, 13));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 220, 46, 13));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 270, 46, 13));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 300, 81, 16));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(120, 160, 121, 22));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(120, 190, 121, 22));
        comboBox_3 = new QComboBox(centralwidget);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(120, 220, 121, 22));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 260, 113, 20));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 300, 113, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 340, 75, 23));
        CreateShipmentWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CreateShipmentWindow);
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
        CreateShipmentWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CreateShipmentWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CreateShipmentWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionClose);
        menuFile->addAction(actionMap);
        menuFile->addAction(actionAdd_Disease);
        menuFile->addAction(actionAdd_Supply);
        menuFile->addAction(actionManage_Shipment);
        menuFile->addAction(actionView_Diseases);
        menuFile->addAction(actionView_Supplies);
        menuView->addAction(actionZoom_In);
        menuView->addAction(actionZoom_Out);

        retranslateUi(CreateShipmentWindow);

        QMetaObject::connectSlotsByName(CreateShipmentWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CreateShipmentWindow)
    {
        CreateShipmentWindow->setWindowTitle(QApplication::translate("CreateShipmentWindow", "CET System", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("CreateShipmentWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionZoom_In->setText(QApplication::translate("CreateShipmentWindow", "Zoom In", 0, QApplication::UnicodeUTF8));
        actionZoom_Out->setText(QApplication::translate("CreateShipmentWindow", "Zoom Out", 0, QApplication::UnicodeUTF8));
        actionMap->setText(QApplication::translate("CreateShipmentWindow", "Map", 0, QApplication::UnicodeUTF8));
        actionAdd_Disease->setText(QApplication::translate("CreateShipmentWindow", "Add Disease", 0, QApplication::UnicodeUTF8));
        actionAdd_Supply->setText(QApplication::translate("CreateShipmentWindow", "Add Supply", 0, QApplication::UnicodeUTF8));
        actionCreat_Shipment->setText(QApplication::translate("CreateShipmentWindow", "Creat Shipment", 0, QApplication::UnicodeUTF8));
        actionManage_Shipment->setText(QApplication::translate("CreateShipmentWindow", "Manage Shipment", 0, QApplication::UnicodeUTF8));
        actionView_Diseases->setText(QApplication::translate("CreateShipmentWindow", "View Diseases", 0, QApplication::UnicodeUTF8));
        actionView_Supplies->setText(QApplication::translate("CreateShipmentWindow", "View Supplies", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateShipmentWindow", "Create A Shipment", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CreateShipmentWindow", "From:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CreateShipmentWindow", "To:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CreateShipmentWindow", "Type:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CreateShipmentWindow", "Quantity:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CreateShipmentWindow", "Delivery Time:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("CreateShipmentWindow", "Create", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("CreateShipmentWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("CreateShipmentWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("CreateShipmentWindow", "View", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("CreateShipmentWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateShipmentWindow: public Ui_CreateShipmentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESHIPMENTWINDOW_H
