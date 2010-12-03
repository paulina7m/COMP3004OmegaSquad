/********************************************************************************
** Form generated from reading UI file 'viewthediseaseswindow.ui'
**
** Created: Fri Dec 3 17:28:59 2010
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWTHEDISEASESWINDOW_H
#define UI_VIEWTHEDISEASESWINDOW_H

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

class Ui_ViewTheDiseasesWindow
{
public:
    QLabel *label;
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *ViewTheDiseasesWindow)
    {
        if (ViewTheDiseasesWindow->objectName().isEmpty())
            ViewTheDiseasesWindow->setObjectName(QString::fromUtf8("ViewTheDiseasesWindow"));
        ViewTheDiseasesWindow->resize(652, 363);
        label = new QLabel(ViewTheDiseasesWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 20, 221, 41));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        tableWidget = new QTableWidget(ViewTheDiseasesWindow);
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
        tableWidget->setGeometry(QRect(40, 80, 581, 192));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->horizontalHeader()->setDefaultSectionSize(112);
        layoutWidget = new QWidget(ViewTheDiseasesWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 300, 267, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(ViewTheDiseasesWindow);
        QObject::connect(pushButton_2, SIGNAL(clicked()), ViewTheDiseasesWindow, SLOT(viewTheDiseasesWindowCancelButtonHandler()));
        QObject::connect(pushButton, SIGNAL(clicked()), ViewTheDiseasesWindow, SLOT(viewTheDiseasesWindowNewButtonHandler()));

        QMetaObject::connectSlotsByName(ViewTheDiseasesWindow);
    } // setupUi

    void retranslateUi(QDialog *ViewTheDiseasesWindow)
    {
        ViewTheDiseasesWindow->setWindowTitle(QApplication::translate("ViewTheDiseasesWindow", "View Epidemic Cases", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ViewTheDiseasesWindow", "Epidemic Cases", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ViewTheDiseasesWindow", "Date", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ViewTheDiseasesWindow", "Region", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ViewTheDiseasesWindow", "Disease", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ViewTheDiseasesWindow", "Number of Cases", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ViewTheDiseasesWindow", "Edit", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ViewTheDiseasesWindow", "Add New Disease Data", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ViewTheDiseasesWindow", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewTheDiseasesWindow: public Ui_ViewTheDiseasesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWTHEDISEASESWINDOW_H
