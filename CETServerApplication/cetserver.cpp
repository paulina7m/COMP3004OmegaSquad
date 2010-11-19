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
