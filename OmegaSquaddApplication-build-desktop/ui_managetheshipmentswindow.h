/********************************************************************************
** Form generated from reading UI file 'managetheshipmentswindow.ui'
**
** Created: Thu Dec 2 13:22:55 2010
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGETHESHIPMENTSWINDOW_H
#define UI_MANAGETHESHIPMENTSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageTheShipmentsWindow
{
public:
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *ManageTheShipmentsWindow)
    {
        if (ManageTheShipmentsWindow->objectName().isEmpty())
            ManageTheShipmentsWindow->setObjectName(QString::fromUtf8("ManageTheShipmentsWindow"));
        ManageTheShipmentsWindow->resize(1081, 499);
        QFont font;
        font.setPointSize(10);
        ManageTheShipmentsWindow->setFont(font);
        label = new QLabel(ManageTheShipmentsWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 251, 61));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);
        tableWidget = new QTableWidget(ManageTheShipmentsWindow);
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
        tableWidget->setGeometry(QRect(30, 80, 1021, 351));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        pushButton = new QPushButton(ManageTheShipmentsWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 450, 161, 23));
        pushButton_2 = new QPushButton(ManageTheShipmentsWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 450, 101, 23));

        retranslateUi(ManageTheShipmentsWindow);
        QObject::connect(pushButton_2, SIGNAL(clicked()), ManageTheShipmentsWindow, SLOT(ManageTheShipmentsWindowCancelButtonHandler()));
        QObject::connect(pushButton, SIGNAL(clicked()), ManageTheShipmentsWindow, SLOT(ManageTheShipmentsWindowSubmitButtonHandler()));

        QMetaObject::connectSlotsByName(ManageTheShipmentsWindow);
    } // setupUi

    void retranslateUi(QDialog *ManageTheShipmentsWindow)
    {
        ManageTheShipmentsWindow->setWindowTitle(QApplication::translate("ManageTheShipmentsWindow", "Manage Shipments", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ManageTheShipmentsWindow", "Manage Shipments", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ManageTheShipmentsWindow", "Shipment #", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ManageTheShipmentsWindow", "From", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ManageTheShipmentsWindow", "To", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ManageTheShipmentsWindow", "Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ManageTheShipmentsWindow", "Quantity", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ManageTheShipmentsWindow", "Date Created", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("ManageTheShipmentsWindow", "Date Sent", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("ManageTheShipmentsWindow", "Date Received", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("ManageTheShipmentsWindow", "Date Cancelled", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("ManageTheShipmentsWindow", "Current Status", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ManageTheShipmentsWindow", "Create New Shipment", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ManageTheShipmentsWindow", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ManageTheShipmentsWindow: public Ui_ManageTheShipmentsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGETHESHIPMENTSWINDOW_H
