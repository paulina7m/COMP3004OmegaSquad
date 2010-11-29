#include "viewthediseaseswindow.h"
#include "ui_viewthediseaseswindow.h"

ViewTheDiseasesWindow::ViewTheDiseasesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTheDiseasesWindow)
{
    ui->setupUi(this);
    this->setGeometry(100,167,1000, 539);
}

ViewTheDiseasesWindow::~ViewTheDiseasesWindow()
{
    delete ui;
}
