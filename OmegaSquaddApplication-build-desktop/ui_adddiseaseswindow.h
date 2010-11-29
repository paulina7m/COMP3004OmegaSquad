/********************************************************************************
** Form generated from reading UI file 'adddiseaseswindow.ui'
**
** Created: Mon Nov 29 18:40:25 2010
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDISEASESWINDOW_H
#define UI_ADDDISEASESWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AddDiseasesWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QCalendarWidget *calendarWidget;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QDateEdit *dateEdit;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;

    void setupUi(QDialog *AddDiseasesWindow)
    {
        if (AddDiseasesWindow->objectName().isEmpty())
            AddDiseasesWindow->setObjectName(QString::fromUtf8("AddDiseasesWindow"));
        AddDiseasesWindow->resize(1002, 541);
        label = new QLabel(AddDiseasesWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 30, 261, 41));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(AddDiseasesWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 110, 46, 13));
        calendarWidget = new QCalendarWidget(AddDiseasesWindow);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(170, 140, 256, 155));
        label_3 = new QLabel(AddDiseasesWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 320, 46, 13));
        label_4 = new QLabel(AddDiseasesWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(200, 360, 46, 13));
        label_5 = new QLabel(AddDiseasesWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(200, 400, 101, 16));
        comboBox = new QComboBox(AddDiseasesWindow);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(260, 320, 131, 22));
        comboBox_2 = new QComboBox(AddDiseasesWindow);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(260, 360, 131, 22));
        pushButton = new QPushButton(AddDiseasesWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 450, 75, 23));
        dateEdit = new QDateEdit(AddDiseasesWindow);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(240, 100, 110, 25));
        spinBox = new QSpinBox(AddDiseasesWindow);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(310, 400, 57, 25));
        pushButton_2 = new QPushButton(AddDiseasesWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 450, 75, 23));

        retranslateUi(AddDiseasesWindow);
        QObject::connect(dateEdit, SIGNAL(dateChanged(QDate)), calendarWidget, SLOT(setSelectedDate(QDate)));
        QObject::connect(calendarWidget, SIGNAL(clicked(QDate)), dateEdit, SLOT(setDate(QDate)));
        QObject::connect(pushButton, SIGNAL(clicked()), AddDiseasesWindow, SLOT(addCaseSubmitButtonHandler()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), AddDiseasesWindow, SLOT(addCaseCancelButtonHandler()));

        QMetaObject::connectSlotsByName(AddDiseasesWindow);
    } // setupUi

    void retranslateUi(QDialog *AddDiseasesWindow)
    {
        AddDiseasesWindow->setWindowTitle(QApplication::translate("AddDiseasesWindow", "Add Disease", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddDiseasesWindow", "Epidemics Data Entry Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddDiseasesWindow", "Date:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddDiseasesWindow", "Region:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AddDiseasesWindow", "Disease:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("AddDiseasesWindow", "Number of Cases:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AddDiseasesWindow", "Submit", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("AddDiseasesWindow", "yyyy-MM-dd", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("AddDiseasesWindow", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddDiseasesWindow: public Ui_AddDiseasesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDISEASESWINDOW_H
