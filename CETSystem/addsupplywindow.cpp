#include "addsupplywindow.h"
#include "ui_addsupplywindow.h"

AddSupplyWindow::AddSupplyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddSupplyWindow)
{
    ui->setupUi(this);
}

AddSupplyWindow::~AddSupplyWindow()
{
    delete ui;
}
