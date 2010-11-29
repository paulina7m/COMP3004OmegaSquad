/********************************************************************************
** Form generated from reading UI file 'viewthesupplieswindow.ui'
**
** Created: Mon Nov 29 14:35:40 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWTHESUPPLIESWINDOW_H
#define UI_VIEWTHESUPPLIESWINDOW_H

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

class Ui_ViewTheSuppliesWindow
{
public:
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QDialog *ViewTheSuppliesWindow)
    {
        if (ViewTheSuppliesWindow->objectName().isEmpty())
            ViewTheSuppliesWindow->setObjectName(QString::fromUtf8("ViewTheSuppliesWindow"));
        ViewTheSuppliesWindow->resize(600, 800);
        label = new QLabel(ViewTheSuppliesWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 20, 201, 71));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        tableWidget = new QTableWidget(ViewTheSuppliesWindow);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(90, 140, 431, 192));
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        pushButton = new QPushButton(ViewTheSuppliesWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 380, 221, 23));

        retranslateUi(ViewTheSuppliesWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), ViewTheSuppliesWindow, SLOT(AddNewSupplyHandler()));

        QMetaObject::connectSlotsByName(ViewTheSuppliesWindow);
    } // setupUi

    void retranslateUi(QDialog *ViewTheSuppliesWindow)
    {
        ViewTheSuppliesWindow->setWindowTitle(QApplication::translate("ViewTheSuppliesWindow", "View Supplies", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ViewTheSuppliesWindow", "Supplies Data", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ViewTheSuppliesWindow", "Region", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ViewTheSuppliesWindow", "Type of Supplies", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ViewTheSuppliesWindow", "Number of Supplies", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ViewTheSuppliesWindow", "Add New Supplies Data", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewTheSuppliesWindow: public Ui_ViewTheSuppliesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWTHESUPPLIESWINDOW_H
