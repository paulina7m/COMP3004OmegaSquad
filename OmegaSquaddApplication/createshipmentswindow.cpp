#include "createshipmentswindow.h"
#include "ui_createshipmentswindow.h"

CreateShipmentsWindow::CreateShipmentsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateShipmentsWindow)
{
    ui->setupUi(this);

    //Fill the combobox with Regions
    //srcRegion, destRegion
    ui->comboBox->addItems(fetchListOfRegions());
    ui->comboBox_2->addItems(fetchListOfRegions());
    ui->comboBox_3->addItems(fetchListOfSupplies());
    dh = new DataHandler;
}

//Get a list of regions from the server
QStringList CreateShipmentsWindow::fetchListOfRegions() {
    QStringList list;

    /*
    //Real call but doesn't work!
    regionList = dh->getRegions();
    for (int i = 0; i < regionList.size(); i++) {
        list.push_front(regionList[i].getName());
    }
    */

    //Workaround
    aRegion1 = new Region1(5931, 2, "Richmond", 0, 0);
    bRegion1 = new Region1(5932, 2, "Vancouver", 0, 0);
    regionList.append(*aRegion1);
    regionList.append(*bRegion1);
    for (int i = 0; i < regionList.size(); i++) {
        list.push_front(regionList[i].getName());
    }

    return list;
}

//Get a list of Supplies
QStringList CreateShipmentsWindow::fetchListOfSupplies() {
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

void CreateShipmentsWindow::CreateShipmentsWindowSubmitButtonHandler() {
    //Save the srcRegion, destRegion, shipmentState, createdDate, supplytype, quantityRequested
    if (ui->spinBox->value() == 0)
    {
        msgBox.setText("Quantity must be greater than 0.");
        msgBox.exec();
    }
    else {
    int srcRegionId;
    int destRegionId;
    int supplyType;
    QString date;
    int quantity;

    //Get the region ID
    for (int i = 0; i < regionList.size(); i++) {
        if (ui->comboBox->currentText() == regionList[i].getName()) {
            srcRegionId = regionList[i].getId();
        }
    }

    for (int i = 0; i < regionList.size(); i++) {
        if (ui->comboBox_2->currentText() == regionList[i].getName()) {
            destRegionId = regionList[i].getId();
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
    date = QDate::currentDate().toString("yyyy-MM-dd");

    //qDebug() << quantity;

    //Save Inventory
    //Required inputs: Region Id for the supply, the supply type and the quantity
    //DOES NOT WORK
    //Required inputs: source region id number , the destination region id number, the date of creation ("YYYY-MM-DD") and Quantity requested
    //Optional inputs: notes (this can be empty string)
    //(int srcRegion, int destRegion, QString createdDate, int supplyType, int quantityRequested, QString notes)
    //dh->saveShipment(srcRegionId, destRegionId, date, supplyType, quantity, "");


    //Use a confirmation popup dialog
    msgBox.setText("Supply data has been saved.");
    msgBox.exec();
    //close the window
    CreateShipmentsWindow::close();
    }
}

void CreateShipmentsWindow::CreateShipmentsWindowCancelButtonHandler() {
    CreateShipmentsWindow::close();
}


CreateShipmentsWindow::~CreateShipmentsWindow()
{
    delete ui;
}
