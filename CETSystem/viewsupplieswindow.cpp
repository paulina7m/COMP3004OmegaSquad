#include "viewsupplieswindow.h"
#include "ui_viewsupplieswindow.h"

ViewSuppliesWindow::ViewSuppliesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewSuppliesWindow)
{
    ui->setupUi(this);
}

ViewSuppliesWindow::~ViewSuppliesWindow()
{
    delete ui;
}
