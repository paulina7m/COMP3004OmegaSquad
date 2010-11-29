#include "managetheshipmentswindow.h"
#include "ui_managetheshipmentswindow.h"

ManageTheShipmentsWindow::ManageTheShipmentsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageTheShipmentsWindow)
{
    ui->setupUi(this);
}

ManageTheShipmentsWindow::~ManageTheShipmentsWindow()
{
    delete ui;
}
