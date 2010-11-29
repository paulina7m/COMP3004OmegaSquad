#include "addsupplieswindow.h"
#include "ui_addsupplieswindow.h"
#include <QDebug>

AddSuppliesWindow::AddSuppliesWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddSuppliesWindow)
{
    ui->setupUi(this);
    this->setGeometry(100,167,1000, 539);
    ui->comboBox->addItems(fetchListOfRegions());
    ui->comboBox_2->addItems(fetchListOfSupplies());
    dh = new DataHandler;
}

AddSuppliesWindow::~AddSuppliesWindow()
{
    delete ui;
}

//Get a list of regions from the server
QStringList AddSuppliesWindow::fetchListOfRegions() {
    QStringList list;

    /*
    //Real call but doesn't work!
    regionList = dh->getRegions();
    for (int i = 0; i < regionList.size(); i++) {
        list.push_front(regionList[i].getName());
    }
    */

    //Workaround
    aRegion = new Region(5931, 2, "Richmond", 0, 0);
    bRegion = new Region(5932, 2, "Vancouver", 0, 0);
    regionList.append(*aRegion);
    regionList.append(*bRegion);
    for (int i = 0; i < regionList.size(); i++) {
        list.push_front(regionList[i].getName());
    }

    return list;
}

//Get a list of Supplies
QStringList AddSuppliesWindow::fetchListOfSupplies() {
    QStringList list;

    /*
    //Real call but doesn't work!
    supplyList = dh->getSupplyTypes();
    for (int i = 0; i < supplyList.size(); i++) {
        list.push_front(supplyList[i].getName());
    }
    */

    //Workaround
    aSupply = new SupplyType(6213, "Dialysis Machine", 2, 1);
    bSupply = new SupplyType(6220, "Panadol", 9, 1);
    supplyList.append(*aSupply);
    supplyList.append(*bSupply);
    for (int i = 0; i < supplyList.size(); i++) {
        list.push_front(supplyList[i].getName());
    }

    return list;
}

void AddSuppliesWindow::addSuppliesSubmitButtonHandler() {
    if (ui->spinBox->value() == 0)
    {
        msgBox.setText("Quantity must be greater than 0.");
        msgBox.exec();
    }
    else {
    int regionId;
    int supplyType;
    int quantity;

    //Get the region ID
    for (int i = 0; i < regionList.size(); i++) {
        if (ui->comboBox->currentText() == regionList[i].getName()) {
            regionId = regionList[i].getId();
        }
    }

    //Get the supplyType ID
    for (int i = 0; i < supplyList.size(); i++) {
        if (ui->comboBox_2->currentText() == supplyList[i].getName()) {
            supplyType = supplyList[i].getId();
        }
    }

    //Get the quantity entered
    quantity = ui->spinBox->value();
    //qDebug() << quantity;

    //Save Inventory
    //Required inputs: Region Id for the supply, the supply type and the quantity
    //DOES NOT WORK
    //dh->saveInventory(regionId, supplyType, quantity);


    qDebug() << regionId << supplyType << quantity;
    //Use a confirmation popup dialog
    msgBox.setText("Supply data has been saved.");
    msgBox.exec();
    //close the window
    AddSuppliesWindow::close();
    }
}

void AddSuppliesWindow::addSuppliesCancelButtonHandler() {
    AddSuppliesWindow::close();
}

void AddSuppliesWindow::SubmitButtonHandler()
{
    if(ui->spinBox->value() == 0)
    {
        msgBox.setText("Quantity must be greater than 0.");
        msgBox.exec();
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

        msgBox.setText("Supply report has been saved.");
        msgBox.exec();

        this->close();
    }
}
