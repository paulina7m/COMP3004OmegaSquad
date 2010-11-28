#include "addsupplieswindow.h"
#include "ui_addsupplieswindow.h"

AddSuppliesWindow::AddSuppliesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSuppliesWindow)
{
    ui->setupUi(this);
}

AddSuppliesWindow::~AddSuppliesWindow()
{
    delete ui;
}
