#include "manageshipmentswindow.h"
#include "ui_manageshipmentswindow.h"

ManageShipmentsWindow::ManageShipmentsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ManageShipmentsWindow)
{
    ui->setupUi(this);
}

ManageShipmentsWindow::~ManageShipmentsWindow()
{
    delete ui;
}
