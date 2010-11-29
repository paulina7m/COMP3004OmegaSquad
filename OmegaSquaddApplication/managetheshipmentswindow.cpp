#include "managetheshipmentswindow.h"
#include "ui_managetheshipmentswindow.h"

ManageTheShipmentsWindow::ManageTheShipmentsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageTheShipmentsWindow)
{
    ui->setupUi(this);
    this->setGeometry(100,167,1000, 539);
}

ManageTheShipmentsWindow::~ManageTheShipmentsWindow()
{
    delete ui;
}
