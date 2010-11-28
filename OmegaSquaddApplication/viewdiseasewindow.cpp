#include "viewdiseasewindow.h"
#include "ui_viewdiseasewindow.h"

ViewDiseaseWindow::ViewDiseaseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ViewDiseaseWindow)
{
    ui->setupUi(this);
}

ViewDiseaseWindow::~ViewDiseaseWindow()
{
    delete ui;
}
