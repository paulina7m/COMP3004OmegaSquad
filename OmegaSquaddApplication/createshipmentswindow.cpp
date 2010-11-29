#include "createshipmentswindow.h"
#include "ui_createshipmentswindow.h"

CreateShipmentsWindow::CreateShipmentsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateShipmentsWindow)
{
    ui->setupUi(this);
}

CreateShipmentsWindow::~CreateShipmentsWindow()
{
    delete ui;
}
