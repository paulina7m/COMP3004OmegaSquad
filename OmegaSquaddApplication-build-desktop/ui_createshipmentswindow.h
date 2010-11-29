/********************************************************************************
** Form generated from reading UI file 'createshipmentswindow.ui'
**
** Created: Sun Nov 28 19:00:55 2010
**      by: Qt User Interface Compiler version 4.7.0
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreateShipmentsWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QDialog *CreateShipmentsWindow)
    {
        if (CreateShipmentsWindow->objectName().isEmpty())
            CreateShipmentsWindow->setObjectName(QString::fromUtf8("CreateShipmentsWindow"));
        CreateShipmentsWindow->resize(600, 800);
        label = new QLabel(CreateShipmentsWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 50, 271, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label_2 = new QLabel(CreateShipmentsWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 160, 46, 13));
        label_3 = new QLabel(CreateShipmentsWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 200, 46, 13));
        label_4 = new QLabel(CreateShipmentsWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 240, 46, 13));
        comboBox = new QComboBox(CreateShipmentsWindow);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(110, 160, 151, 22));
        comboBox_2 = new QComboBox(CreateShipmentsWindow);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(110, 200, 151, 22));
        comboBox_3 = new QComboBox(CreateShipmentsWindow);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(110, 230, 151, 22));
        label_5 = new QLabel(CreateShipmentsWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 300, 46, 13));
        label_6 = new QLabel(CreateShipmentsWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 330, 81, 16));
        lineEdit = new QLineEdit(CreateShipmentsWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 290, 113, 20));
        lineEdit_2 = new QLineEdit(CreateShipmentsWindow);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(130, 330, 113, 20));
        pushButton = new QPushButton(CreateShipmentsWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 310, 75, 23));

        retranslateUi(CreateShipmentsWindow);

        QMetaObject::connectSlotsByName(CreateShipmentsWindow);
    } // setupUi

    void retranslateUi(QDialog *CreateShipmentsWindow)
    {
        CreateShipmentsWindow->setWindowTitle(QApplication::translate("CreateShipmentsWindow", "Create Shipment", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateShipmentsWindow", "Create A Shipment", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CreateShipmentsWindow", "From:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CreateShipmentsWindow", "To:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CreateShipmentsWindow", "Type:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CreateShipmentsWindow", "Quantity:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CreateShipmentsWindow", "Delivery Time:", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("CreateShipmentsWindow", "Create", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateShipmentsWindow: public Ui_CreateShipmentsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESHIPMENTSWINDOW_H
