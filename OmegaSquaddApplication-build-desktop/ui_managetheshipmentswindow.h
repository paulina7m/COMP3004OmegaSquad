/********************************************************************************
** Form generated from reading UI file 'managetheshipmentswindow.ui'
**
** Created: Sun Nov 28 19:00:56 2010
**      by: Qt User Interface Compiler version 4.7.0
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

    void setupUi(QDialog *ManageTheShipmentsWindow)
    {
        if (ManageTheShipmentsWindow->objectName().isEmpty())
            ManageTheShipmentsWindow->setObjectName(QString::fromUtf8("ManageTheShipmentsWindow"));
        ManageTheShipmentsWindow->resize(600, 800);
        label = new QLabel(ManageTheShipmentsWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 40, 251, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        tableWidget = new QTableWidget(ManageTheShipmentsWindow);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
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
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(35, 170, 471, 192));
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        pushButton = new QPushButton(ManageTheShipmentsWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 400, 161, 23));

        retranslateUi(ManageTheShipmentsWindow);

        QMetaObject::connectSlotsByName(ManageTheShipmentsWindow);
    } // setupUi

    void retranslateUi(QDialog *ManageTheShipmentsWindow)
    {
        ManageTheShipmentsWindow->setWindowTitle(QApplication::translate("ManageTheShipmentsWindow", "Manage Shipments", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ManageTheShipmentsWindow", "Manage Shipments", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ManageTheShipmentsWindow", "From", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ManageTheShipmentsWindow", "To", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ManageTheShipmentsWindow", "Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ManageTheShipmentsWindow", "Quantity", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ManageTheShipmentsWindow", "Days to Ship", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ManageTheShipmentsWindow", "Sent", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("ManageTheShipmentsWindow", "Sent Date", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("ManageTheShipmentsWindow", "Expected Arrival Date", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("ManageTheShipmentsWindow", "Received", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ManageTheShipmentsWindow", "Create New Shipment", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ManageTheShipmentsWindow: public Ui_ManageTheShipmentsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGETHESHIPMENTSWINDOW_H
