#include "addsupplieswindow.h"
#include "ui_addsupplieswindow.h"
#include "DataHandler.h"
#include <QList>

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

QList AddSuppliesWindow::fetchListOfDiseases()
{
    QList list;
    DataHandler dataHandler;

    list.insert(dataHandler.getDiseaseTypes());

    return list;
}
