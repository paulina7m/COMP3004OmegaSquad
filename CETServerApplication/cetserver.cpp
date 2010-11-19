#include "cetserver.h"
#include "ui_cetserver.h"

CETServer::CETServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CETServer)
{
    ui->setupUi(this);
}

CETServer::~CETServer()
{
    delete ui;
}

/*Start server button handler*/
void CETServer::startServerButtonHandler() {
    ui->statusText->appendPlainText("Start Server");
}

/*Stop server button handler*/
void CETServer::stopServerButtonHandler() {
    ui->statusText->appendPlainText("Stop Server");
}

/*Press Exit in the menu*/
void CETServer::on_actionExit_triggered()
{
    CETServer::close();
}
