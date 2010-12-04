#include "configurecet.h"
#include "ui_configurecet.h"
#include <QFile>
#include <QDebug>
#include <QIODevice>
#include <QTextStream>
#include <QDir>
#include <QRegExpValidator>

ConfigureCet::ConfigureCet(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::ConfigureCet)
{
    ui->setupUi(this);





    QString filename = "config.cet";
    file = new QFile(filename);


    if(!file->exists()) //if file does not exist
    {
        if (!file->open(QIODevice::ReadWrite)) //open it in read write mode, this creates a new file
        {
            //qDebug() << "error creating file";

        }else{
            //qDebug() << "file created";
            QString newIP = "127.0.0.1";
            file->write(newIP.toAscii(),newIP.length());
            file->setPermissions(QFile::ReadOwner | QFile::WriteOwner | QFile::ReadUser | QFile::WriteUser | QFile::ReadGroup | QFile::WriteGroup | QFile::ReadOther | QFile::WriteOther);
        }
        ui->plainTextEdit->setPlainText("127.0.0.1");
    }else{ //if file does exist open for reading
        if (!file->open(QIODevice::ReadWrite)){
            //qDebug() << "error opening file";
        }else{
            //qDebug() << "file opened";
            //read in ip address
            ipAddress = file->readAll();
            ui->plainTextEdit->setPlainText(ipAddress);
            //qDebug() << ipAddress;
        }
    }
    file->close();
}

void ConfigureCet::configureCetSubmitButtonHandler() {
    QString newIP = (QString) ui->plainTextEdit->toPlainText();
    QRegExp rx("^[0-2]?[0-9]?[0-9]\\.[0-2]?[0-9]?[0-9]\\.[0-2]?[0-9]?[0-9]\\.[0-2]?[0-9]?[0-9]$");
    if (newIP == "..." || !rx.exactMatch(newIP)) {
        //false
        msgBox.setText("Invalid IP entered.");
        msgBox.exec();
    }
    else {
        QString filename = "config.cet";
        file = new QFile(filename);

        if (!file->open(QIODevice::WriteOnly)){
            //qDebug() << "error opening file";
        }else{
            //qDebug() << "file opened";
            //read in ip address
            file->write(newIP.toAscii(),newIP.length());
            //qDebug() << ipAddress;
        }
        file->close();
        ConfigureCet::close();
    }
}

void ConfigureCet::configureCetCancelButtonHandler() {
    ConfigureCet::close();
}

ConfigureCet::~ConfigureCet()
{
    delete ui;
}
