#include "viewthesupplieswindow.h"
#include "ui_viewthesupplieswindow.h"

ViewTheSuppliesWindow::ViewTheSuppliesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTheSuppliesWindow)
{
    ui->setupUi(this);
}

ViewTheSuppliesWindow::~ViewTheSuppliesWindow()
{
    delete ui;
}
