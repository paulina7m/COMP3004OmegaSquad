/********************************************************************************
** Form generated from reading UI file 'adddiseaseswindow.ui'
**
** Created: Fri Dec 3 17:28:59 2010
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
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddDiseasesWindow
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_4;
    QLabel *label_6;
    QGroupBox *groupBox;
    QComboBox *comboBox;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_2;
    QGroupBox *groupBox_3;
    QSpinBox *spinBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *AddDiseasesWindow)
    {
        if (AddDiseasesWindow->objectName().isEmpty())
            AddDiseasesWindow->setObjectName(QString::fromUtf8("AddDiseasesWindow"));
        AddDiseasesWindow->resize(376, 478);
        label = new QLabel(AddDiseasesWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(46, 31, 261, 24));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        layoutWidget = new QWidget(AddDiseasesWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 70, 291, 331));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 40, 261, 16));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_6->setFont(font1);

        verticalLayout->addWidget(groupBox_4);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 40, 261, 26));

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(10, 40, 261, 26));

        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 30, 131, 25));
        spinBox->setMaximum(99999);

        verticalLayout->addWidget(groupBox_3);

        layoutWidget1 = new QWidget(AddDiseasesWindow);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(41, 420, 170, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(AddDiseasesWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), AddDiseasesWindow, SLOT(addCaseSubmitButtonHandler()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), AddDiseasesWindow, SLOT(addCaseCancelButtonHandler()));

        QMetaObject::connectSlotsByName(AddDiseasesWindow);
    } // setupUi

    void retranslateUi(QDialog *AddDiseasesWindow)
    {
        AddDiseasesWindow->setWindowTitle(QApplication::translate("AddDiseasesWindow", "Epidemics Data Entry Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddDiseasesWindow", "Epidemics Data Entry Form", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("AddDiseasesWindow", "Date Of Entry", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AddDiseasesWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("AddDiseasesWindow", "Region", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("AddDiseasesWindow", "Disease", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("AddDiseasesWindow", "Number Of Cases", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("AddDiseasesWindow", "Submit", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("AddDiseasesWindow", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddDiseasesWindow: public Ui_AddDiseasesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDISEASESWINDOW_H
