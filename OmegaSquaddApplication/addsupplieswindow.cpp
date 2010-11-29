#include "addsupplieswindow.h"
#include "ui_addsupplieswindow.h"
#include <QDebug>

AddSuppliesWindow::AddSuppliesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSuppliesWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->comboBox->addItems(fetchListOfRegions());
    //ui->comboBox_2->addItems(fetchListOfSupplies());
    dh = new DataHandler;
}

AddSuppliesWindow::~AddSuppliesWindow()
{
    delete ui;
}

QStringList AddSuppliesWindow::fetchListOfRegions()
{
    QStringList list;

    regionList = dh->getRegions();
    for(int i = 0; i < regionList.size(); i++)
        list.push_front(regionList[i].getName());

    return list;
}
