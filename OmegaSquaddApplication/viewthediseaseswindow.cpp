#include "viewthediseaseswindow.h"
#include "ui_viewthediseaseswindow.h"

ViewTheDiseasesWindow::ViewTheDiseasesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTheDiseasesWindow)
{
    ui->setupUi(this);
}

ViewTheDiseasesWindow::~ViewTheDiseasesWindow()
{
    delete ui;
}
