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

QStringList AddSuppliesWindow::fetchListOfSupplies()
{
    QStringList list;

    supplyList = dh->getSupplyTypes();
    for(int i = 0; i < regionList.size(); i++)
        list.push_front(supplyList[i].getName());

    return list;
}

void AddSuppliesWindow::SubmitButtonHandler()
{
    if(ui->spinBox->value() == 0)
    {
        messageBox.setText("Quantity must be greater than 0.");
        messageBox.exec();
    }
    else
    {
        int regionID;
        QString date;
        int supplyType;
        int quantity;

        for(int i = 0; i < regionList.size(); i++)
            if(ui->comboBox->currentText() == regionList[i].getName())
                regionID = regionList[i].getId();

        for(int i = 0; i < supplyList.size(); i++)
            if(ui->comboBox_2->currentText() == supplyList[i].getName())
                supplyType = supplyList[i].getId();

        quantity = ui->spinBox->value();

        date = ui->dateEdit->text();

        messageBox.setText("Supply report has been saved.");
        messageBox.exec();

        this->close();
    }
}
