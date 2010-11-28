#include "createshipmentwindow.h"
#include "ui_createshipmentwindow.h"

CreateShipmentWindow::CreateShipmentWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CreateShipmentWindow)
{
    ui->setupUi(this);
}

CreateShipmentWindow::~CreateShipmentWindow()
{
    delete ui;
}
