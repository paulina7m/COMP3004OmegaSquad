/********************************************************************************
** Form generated from reading UI file 'viewthesupplieswindow.ui'
**
** Created: Fri Dec 3 17:28:59 2010
**      by: Qt User Interface Compiler version 4.7.1
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewTheSuppliesWindow
{
public:
    QLabel *label;
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *ViewTheSuppliesWindow)
    {
        if (ViewTheSuppliesWindow->objectName().isEmpty())
            ViewTheSuppliesWindow->setObjectName(QString::fromUtf8("ViewTheSuppliesWindow"));
        ViewTheSuppliesWindow->resize(597, 375);
        label = new QLabel(ViewTheSuppliesWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 10, 201, 71));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        tableWidget = new QTableWidget(ViewTheSuppliesWindow);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(50, 80, 491, 192));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->horizontalHeader()->setDefaultSectionSize(112);
        layoutWidget = new QWidget(ViewTheSuppliesWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 300, 272, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(ViewTheSuppliesWindow);
        QObject::connect(pushButton_2, SIGNAL(clicked()), ViewTheSuppliesWindow, SLOT(ViewTheSuppliesWindowCancelButtonHandler()));
        QObject::connect(pushButton, SIGNAL(clicked()), ViewTheSuppliesWindow, SLOT(ViewTheSuppliesWindowSubmitButtonHandler()));

        QMetaObject::connectSlotsByName(ViewTheSuppliesWindow);
    } // setupUi

    void retranslateUi(QDialog *ViewTheSuppliesWindow)
    {
        ViewTheSuppliesWindow->setWindowTitle(QApplication::translate("ViewTheSuppliesWindow", "View Inventory", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ViewTheSuppliesWindow", "Supplies Data", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ViewTheSuppliesWindow", "City", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ViewTheSuppliesWindow", "Type of Supplies", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ViewTheSuppliesWindow", "Number of Supplies", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ViewTheSuppliesWindow", "Edit", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ViewTheSuppliesWindow", "Add New Supplies Data", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ViewTheSuppliesWindow", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewTheSuppliesWindow: public Ui_ViewTheSuppliesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWTHESUPPLIESWINDOW_H
