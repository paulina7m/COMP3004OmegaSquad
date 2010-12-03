/********************************************************************************
** Form generated from reading UI file 'addsupplieswindow.ui'
**
** Created: Fri Dec 3 17:28:59 2010
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSUPPLIESWINDOW_H
#define UI_ADDSUPPLIESWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddSuppliesWindow
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QLabel *label_6;
    QGroupBox *groupBox_2;
    QComboBox *comboBox;
    QGroupBox *groupBox_3;
    QComboBox *comboBox_2;
    QGroupBox *groupBox_4;
    QSpinBox *spinBox;

    void setupUi(QDialog *AddSuppliesWindow)
    {
        if (AddSuppliesWindow->objectName().isEmpty())
            AddSuppliesWindow->setObjectName(QString::fromUtf8("AddSuppliesWindow"));
        AddSuppliesWindow->resize(302, 432);
        label = new QLabel(AddSuppliesWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 261, 41));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        layoutWidget = new QWidget(AddSuppliesWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 380, 170, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        layoutWidget1 = new QWidget(AddSuppliesWindow);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 50, 261, 321));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 40, 241, 16));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_6->setFont(font1);

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(layoutWidget1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 40, 241, 22));

        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(layoutWidget1);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(10, 40, 241, 22));

        gridLayout->addWidget(groupBox_3, 2, 0, 1, 1);

        groupBox_4 = new QGroupBox(layoutWidget1);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        spinBox = new QSpinBox(groupBox_4);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(10, 40, 131, 25));
        spinBox->setMaximum(99999);

        gridLayout->addWidget(groupBox_4, 3, 0, 1, 1);


        retranslateUi(AddSuppliesWindow);
        QObject::connect(pushButton_2, SIGNAL(clicked()), AddSuppliesWindow, SLOT(addSuppliesCancelButtonHandler()));
        QObject::connect(pushButton, SIGNAL(clicked()), AddSuppliesWindow, SLOT(addSuppliesSubmitButtonHandler()));

        QMetaObject::connectSlotsByName(AddSuppliesWindow);
    } // setupUi

    void retranslateUi(QDialog *AddSuppliesWindow)
    {
        AddSuppliesWindow->setWindowTitle(QApplication::translate("AddSuppliesWindow", "Supply Data Entry Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddSuppliesWindow", "Supply Data Entry Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AddSuppliesWindow", "Submit", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("AddSuppliesWindow", "Cancel", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("AddSuppliesWindow", "Date Of Entry", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AddSuppliesWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("AddSuppliesWindow", "Region", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("AddSuppliesWindow", "Supply", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("AddSuppliesWindow", "Number Of Supplies", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddSuppliesWindow: public Ui_AddSuppliesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSUPPLIESWINDOW_H
