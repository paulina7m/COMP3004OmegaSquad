/********************************************************************************
** Form generated from reading UI file 'createshipmentswindow.ui'
**
** Created: Thu Dec 2 13:22:55 2010
**      by: Qt User Interface Compiler version 4.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESHIPMENTSWINDOW_H
#define UI_CREATESHIPMENTSWINDOW_H

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

class Ui_CreateShipmentsWindow
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_3;
    QGroupBox *groupBox_3;
    QSpinBox *spinBox;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *CreateShipmentsWindow)
    {
        if (CreateShipmentsWindow->objectName().isEmpty())
            CreateShipmentsWindow->setObjectName(QString::fromUtf8("CreateShipmentsWindow"));
        CreateShipmentsWindow->resize(437, 510);
        label = new QLabel(CreateShipmentsWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 271, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        groupBox = new QGroupBox(CreateShipmentsWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(50, 80, 331, 151));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 30, 291, 103));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        comboBox_2 = new QComboBox(widget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        verticalLayout->addWidget(comboBox_2);

        groupBox_2 = new QGroupBox(CreateShipmentsWindow);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(50, 240, 331, 80));
        comboBox_3 = new QComboBox(groupBox_2);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(20, 40, 291, 22));
        comboBox_3->raise();
        groupBox->raise();
        groupBox_3 = new QGroupBox(CreateShipmentsWindow);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(50, 330, 331, 80));
        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(20, 40, 151, 25));
        spinBox->setMaximum(99999);
        widget1 = new QWidget(CreateShipmentsWindow);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(50, 430, 166, 32));
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        retranslateUi(CreateShipmentsWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), CreateShipmentsWindow, SLOT(CreateShipmentsWindowSubmitButtonHandler()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), CreateShipmentsWindow, SLOT(CreateShipmentsWindowCancelButtonHandler()));

        QMetaObject::connectSlotsByName(CreateShipmentsWindow);
    } // setupUi

    void retranslateUi(QDialog *CreateShipmentsWindow)
    {
        CreateShipmentsWindow->setWindowTitle(QApplication::translate("CreateShipmentsWindow", "Create Shipment", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateShipmentsWindow", "Create A Shipment", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CreateShipmentsWindow", "Regions", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CreateShipmentsWindow", "From:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CreateShipmentsWindow", "To:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("CreateShipmentsWindow", "Supply Type", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("CreateShipmentsWindow", "Quantity", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("CreateShipmentsWindow", "Create", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("CreateShipmentsWindow", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateShipmentsWindow: public Ui_CreateShipmentsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESHIPMENTSWINDOW_H
