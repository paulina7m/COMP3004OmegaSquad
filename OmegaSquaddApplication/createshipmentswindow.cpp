#include "createshipmentswindow.h"
#include "ui_createshipmentswindow.h"

CreateShipmentsWindow::CreateShipmentsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateShipmentsWindow)
{
    ui->setupUi(this);
    this->setGeometry(100,167,1000, 539);
}

CreateShipmentsWindow::~CreateShipmentsWindow()
{
    delete ui;
}
