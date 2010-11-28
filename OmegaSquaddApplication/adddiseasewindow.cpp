#include "adddiseasewindow.h"
#include "ui_adddiseasewindow.h"

AddDiseaseWindow::AddDiseaseWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddDiseaseWindow)
{
    ui->setupUi(this);
}

AddDiseaseWindow::~AddDiseaseWindow()
{
    delete ui;
}

