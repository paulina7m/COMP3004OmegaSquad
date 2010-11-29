#include "adddiseaseswindow.h"
#include "ui_adddiseaseswindow.h"

AddDiseasesWindow::AddDiseasesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDiseasesWindow)
{
    ui->setupUi(this);
}

AddDiseasesWindow::~AddDiseasesWindow()
{
    delete ui;
}
