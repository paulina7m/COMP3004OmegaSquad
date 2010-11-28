/********************************************************************************
** Form generated from reading UI file 'AddDiseaseWindow.ui'
**
** Created: Sun Nov 28 17:16:43 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDISEASEWINDOW_H
#define UI_ADDDISEASEWINDOW_H

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

class Ui_AddDiseaseWindow
{
public:
    QAction *actionMap;
    QAction *actionMap_2;
    QAction *actionAdd_Supply;
    QAction *actionCreat_Shipment;
    QAction *actionManage_Shipment;
    QAction *actionView_Diseases;
    QAction *actionView_Supplies;
    QAction *actionClose_this;
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QCalendarWidget *calendarWidget;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddDiseaseWindow)
    {
        if (AddDiseaseWindow->objectName().isEmpty())
            AddDiseaseWindow->setObjectName(QString::fromUtf8("AddDiseaseWindow"));
        AddDiseaseWindow->resize(800, 600);
        actionMap = new QAction(AddDiseaseWindow);
        actionMap->setObjectName(QString::fromUtf8("actionMap"));
        actionMap_2 = new QAction(AddDiseaseWindow);
        actionMap_2->setObjectName(QString::fromUtf8("actionMap_2"));
        actionAdd_Supply = new QAction(AddDiseaseWindow);
        actionAdd_Supply->setObjectName(QString::fromUtf8("actionAdd_Supply"));
        actionCreat_Shipment = new QAction(AddDiseaseWindow);
        actionCreat_Shipment->setObjectName(QString::fromUtf8("actionCreat_Shipment"));
        actionManage_Shipment = new QAction(AddDiseaseWindow);
        actionManage_Shipment->setObjectName(QString::fromUtf8("actionManage_Shipment"));
        actionView_Diseases = new QAction(AddDiseaseWindow);
        actionView_Diseases->setObjectName(QString::fromUtf8("actionView_Diseases"));
        actionView_Supplies = new QAction(AddDiseaseWindow);
        actionView_Supplies->setObjectName(QString::fromUtf8("actionView_Supplies"));
        actionClose_this = new QAction(AddDiseaseWindow);
        actionClose_this->setObjectName(QString::fromUtf8("actionClose_this"));
        centralwidget = new QWidget(AddDiseaseWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 30, 401, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 130, 46, 13));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 130, 113, 20));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(40, 160, 256, 155));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 350, 46, 13));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 380, 46, 13));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 410, 81, 16));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(70, 340, 131, 22));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(70, 380, 131, 22));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(80, 410, 113, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 450, 75, 23));
        AddDiseaseWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddDiseaseWindow);
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
        AddDiseaseWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AddDiseaseWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AddDiseaseWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionClose_this);
        menuFile->addAction(actionMap_2);
        menuFile->addAction(actionAdd_Supply);
        menuFile->addAction(actionCreat_Shipment);
        menuFile->addAction(actionManage_Shipment);
        menuFile->addAction(actionView_Diseases);
        menuFile->addAction(actionView_Supplies);

        retranslateUi(AddDiseaseWindow);
        QObject::connect(actionClose_this, SIGNAL(activated()), AddDiseaseWindow, SLOT(close()));
        QObject::connect(actionMap_2, SIGNAL(activated()), AddDiseaseWindow, SLOT(MapHandler()));
        QObject::connect(actionAdd_Supply, SIGNAL(activated()), AddDiseaseWindow, SLOT(AddSupplyHandler()));
        QObject::connect(actionCreat_Shipment, SIGNAL(activated()), AddDiseaseWindow, SLOT(CreateShipmentHandler()));
        QObject::connect(actionManage_Shipment, SIGNAL(activated()), AddDiseaseWindow, SLOT(ManageShipmentsHandler()));
        QObject::connect(actionView_Diseases, SIGNAL(activated()), AddDiseaseWindow, SLOT(ViewDiseasesHandler()));
        QObject::connect(actionView_Supplies, SIGNAL(activated()), AddDiseaseWindow, SLOT(ViewSuppliesHandler()));

        QMetaObject::connectSlotsByName(AddDiseaseWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AddDiseaseWindow)
    {
        AddDiseaseWindow->setWindowTitle(QApplication::translate("AddDiseaseWindow", "CET System", 0, QApplication::UnicodeUTF8));
        actionMap->setText(QApplication::translate("AddDiseaseWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionMap_2->setText(QApplication::translate("AddDiseaseWindow", "Map", 0, QApplication::UnicodeUTF8));
        actionAdd_Supply->setText(QApplication::translate("AddDiseaseWindow", "Add Supply", 0, QApplication::UnicodeUTF8));
        actionCreat_Shipment->setText(QApplication::translate("AddDiseaseWindow", "Create Shipment", 0, QApplication::UnicodeUTF8));
        actionManage_Shipment->setText(QApplication::translate("AddDiseaseWindow", "Manage Shipment", 0, QApplication::UnicodeUTF8));
        actionView_Diseases->setText(QApplication::translate("AddDiseaseWindow", "View Diseases", 0, QApplication::UnicodeUTF8));
        actionView_Supplies->setText(QApplication::translate("AddDiseaseWindow", "View Supplies", 0, QApplication::UnicodeUTF8));
        actionClose_this->setText(QApplication::translate("AddDiseaseWindow", "Close", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddDiseaseWindow", "Disease Data Entry Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddDiseaseWindow", "Date:", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("AddDiseaseWindow", "DD/MM/YYYY", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddDiseaseWindow", "City:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AddDiseaseWindow", "Disease:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AddDiseaseWindow", "# of cases:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AddDiseaseWindow", "Submit", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("AddDiseaseWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("AddDiseaseWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("AddDiseaseWindow", "View", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("AddDiseaseWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddDiseaseWindow: public Ui_AddDiseaseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDISEASEWINDOW_H
