/********************************************************************************
** Form generated from reading UI file 'addsupplieswindow.ui'
**
** Created: Sun Nov 28 19:00:55 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSUPPLIESWINDOW_H
#define UI_ADDSUPPLIESWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddSuppliesWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QCalendarWidget *calendarWidget;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QPushButton *pushButton;

    void setupUi(QDialog *AddSuppliesWindow)
    {
        if (AddSuppliesWindow->objectName().isEmpty())
            AddSuppliesWindow->setObjectName(QString::fromUtf8("AddSuppliesWindow"));
        AddSuppliesWindow->resize(600, 800);
        label = new QLabel(AddSuppliesWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 30, 231, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(AddSuppliesWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 120, 46, 13));
        label_3 = new QLabel(AddSuppliesWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 320, 46, 13));
        label_4 = new QLabel(AddSuppliesWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 350, 46, 13));
        calendarWidget = new QCalendarWidget(AddSuppliesWindow);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(50, 150, 256, 155));
        lineEdit = new QLineEdit(AddSuppliesWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 120, 113, 20));
        lineEdit_2 = new QLineEdit(AddSuppliesWindow);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 390, 113, 20));
        label_5 = new QLabel(AddSuppliesWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 390, 111, 16));
        comboBox = new QComboBox(AddSuppliesWindow);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(130, 320, 141, 22));
        comboBox_2 = new QComboBox(AddSuppliesWindow);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(130, 350, 141, 22));
        pushButton = new QPushButton(AddSuppliesWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 340, 75, 23));

        retranslateUi(AddSuppliesWindow);

        QMetaObject::connectSlotsByName(AddSuppliesWindow);
    } // setupUi

    void retranslateUi(QDialog *AddSuppliesWindow)
    {
        AddSuppliesWindow->setWindowTitle(QApplication::translate("AddSuppliesWindow", "Add Supplies", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddSuppliesWindow", "Add Supply Data", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddSuppliesWindow", "Date:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddSuppliesWindow", "Region:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AddSuppliesWindow", "Disease:", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("AddSuppliesWindow", "DD/MM/YYYY", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AddSuppliesWindow", "Number of Supplies:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AddSuppliesWindow", "Submit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddSuppliesWindow: public Ui_AddSuppliesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSUPPLIESWINDOW_H