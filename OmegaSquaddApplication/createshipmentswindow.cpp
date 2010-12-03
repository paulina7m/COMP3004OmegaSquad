#include "createshipmentswindow.h"
#include "ui_createshipmentswindow.h"
#include "managetheshipmentswindow.h"
#include "Inventory.h"

CreateShipmentsWindow::CreateShipmentsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateShipmentsWindow)
{
    ui->setupUi(this);
    cameFrom = false;

    //Fill the combobox with Regions
    //srcRegion, destRegion
    QString supplyAmount = "";
    QString supplyQuantity;
    bool quantityFound = false;
    DataHandler *dh = new DataHandler();
    if (dh->isConnected()) {
        ui->comboBox->addItems(fetchListOfRegions());
        ui->comboBox_2->addItems(fetchListOfRegions());
        ui->comboBox_3->addItems(fetchListOfSupplies());
        inventoryList = dh->getInventory();


        for (int j = 0; j < regionList.size(); j++) {
            //if the region name is the same as the combobox initial region listed
            if (regionList[j].getName() == ui->comboBox->currentText()) {
                for (int i = 0; i < inventoryList.size(); i++) {
                    //qDebug() << inventoryList[i].getRegionId();
                    if(regionList[j].getId() == inventoryList[i].getRegionId()) {
                        for (int k = 0; k < supplyList.size(); k++) {
                            if (supplyList[k].getName() == ui->comboBox_3->currentText()) {
                                //qDebug() << inventoryList[i].getId();
                                supplyAmount = regionList[j].getName();
                                supplyAmount.append(" currently has ");
                                supplyAmount.append(supplyQuantity.setNum(inventoryList[i].getQuantity()));
                                supplyAmount.append(" quantities of " );
                                ui->srcRegionSupplies->setText(supplyAmount);
                                ui->spinBox->setEnabled(true);
                                ui->spinBox->setMaximum(inventoryList[i].getQuantity());
                                quantityFound = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (quantityFound == false) {
            supplyAmount = ui->comboBox->currentText();
            supplyAmount.append(" currently has 0 quantities of ");
            ui->srcRegionSupplies->setText(supplyAmount);
            ui->spinBox->setDisabled(true);
        }
    }
    else {
        ui->pushButton->hide();
    }
    delete dh;
}

void CreateShipmentsWindow::notifyUser() {
    //qDebug() << ui->comboBox->currentText();
    //qDebug() << ui->comboBox_3->currentText();

    ui->srcRegionSupplies->setText("");
    QString supplyAmount = "";
    QString supplyQuantity = "";
    bool quantityFound = false;

    //inventoryList[i].getRegionId()
    //inventoryList[i].getSupplyType()
    //inventoryList[i].getQuantity()

    for (int i = 0; i < regionList.size(); i++) {
        for (int j = 0; j < supplyList.size(); j++) {
            for (int k = 0; k < inventoryList.size(); k++) {
                if (regionList[i].getId() == inventoryList[k].getRegionId() &&
                    supplyList[j].getId() == inventoryList[k].getSupplyType() &&
                    regionList[i].getName() == ui->comboBox->currentText() &&
                    supplyList[j].getName() == ui->comboBox_3->currentText()) {

                    //qDebug() << inventoryList[i].getId();
                    supplyAmount = regionList[i].getName();
                    supplyAmount.append(" currently has ");
                    supplyAmount.append(supplyQuantity.setNum(inventoryList[k].getQuantity()));
                    supplyAmount.append(" quantities of " );
                    ui->srcRegionSupplies->setText(supplyAmount);
                    ui->spinBox->setEnabled(true);
                    ui->spinBox->setMaximum(inventoryList[k].getQuantity());
                    quantityFound = true;
                    break;
                }
            }
        }
    }

    if (quantityFound == false) {
        supplyAmount = ui->comboBox->currentText();
        supplyAmount.append(" currently has 0 quantities of ");
        ui->srcRegionSupplies->setText(supplyAmount);
        ui->spinBox->setDisabled(true);
    }

}

void CreateShipmentsWindow::changeText(QString inputs) {
    QStringList someInputs = inputs.split("-");
    QString source = someInputs[0];
    QString supply = someInputs[1];
    qDebug() << source << supply;
}

//Get a list of regions from the server
QStringList CreateShipmentsWindow::fetchListOfRegions() {
    QStringList list;

    DataHandler *dh = new DataHandler;
    regionList = dh->getRegions();
    for (int i = 0; i < regionList.size(); i++) {
        list.push_front(regionList[i].getName());
    }
    delete dh;

    /*
    //Workaround
    aRegion1 = new Region1(5931, 2, "Richmond", 0, 0);
    bRegion1 = new Region1(5932, 2, "Vancouver", 0, 0);
    regionList.append(*aRegion1);
    regionList.append(*bRegion1);
    for (int i = 0; i < regionList.size(); i++) {
        list.push_front(regionList[i].getName());
    }
    */

    return list;
}

//Get a list of Supplies
QStringList CreateShipmentsWindow::fetchListOfSupplies() {
    QStringList list;

    DataHandler *dh = new DataHandler;
    supplyList = dh->getSupplyTypes();
    for (int i = 0; i < supplyList.size(); i++) {
        list.push_front(supplyList[i].getName());
    }
    delete dh;

    /*
    //Workaround
    aSupply = new SupplyType(6213, "Dialysis Machine", 2, 1);
    bSupply = new SupplyType(6220, "Panadol", 9, 1);
    supplyList.append(*aSupply);
    supplyList.append(*bSupply);
    for (int i = 0; i < supplyList.size(); i++) {
        list.push_front(supplyList[i].getName());
    }
    */

    return list;
}

void CreateShipmentsWindow::fromManager(int flag) {
    if (flag == 1) {
        cameFrom = true;
    }
    else {
        cameFrom = false;
    }
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
        if (ui->comboBox_3->currentText() == supplyList[i].getName()) {
            supplyType = supplyList[i].getId();
        }
    }

    //Get the quantity entered
    quantity = ui->spinBox->value();
    date = QDate::currentDate().toString("yyyy-MM-dd");

    //qDebug() << quantity;

    //Save Shipment
    //Required inputs: Region Id for the supply, the supply type and the quantity
    //DOES NOT WORK
    //Required inputs: source region id number , the destination region id number, the date of creation ("YYYY-MM-DD") and Quantity requested
    //Optional inputs: notes (this can be empty string)
    //(int srcRegion, int destRegion, QString createdDate, int supplyType, int quantityRequested, QString notes)
    DataHandler *dh = new DataHandler;
    dh->saveShipment(srcRegionId, destRegionId, date, supplyType, quantity, "");

    /*
    int srcQuantity;
    int destQuantity;
    bool destUpdated = false;
    //Update the source regions depleted inventory
    for (int i = 0; i < inventoryList.size(); i++) {
        if (inventoryList[i].getRegionId() == srcRegionId) {
            srcQuantity = inventoryList[i].getQuantity() - quantity;
        }
    }
    dh->updateInventory(srcRegionId, srcQuantity);


    //Update the destination regions increased inventory
    for (int i = 0; i < inventoryList.size(); i++) {
        if (inventoryList[i].getRegionId() == destRegionId) {
            destQuantity = inventoryList[i].getQuantity() + quantity;
            destUpdated = true;
        }
    }
    if (destUpdated) {
        dh->updateInventory(destRegionId, destQuantity);
    }
    else {
        dh->saveInventory(destRegionId, supplyType, destQuantity);
    }
    */

    delete dh;



    //Use a confirmation popup dialog
    msgBox.setText("Shipment has been created.");
    msgBox.exec();

    if (cameFrom) {
        //open the management window again
        ManageTheShipmentsWindow *managementWindow = new ManageTheShipmentsWindow;
        managementWindow->show();
        managementWindow->isModal();
    }

    //close the window
    CreateShipmentsWindow::close();
    }
}

void CreateShipmentsWindow::CreateShipmentsWindowCancelButtonHandler() {

    if (cameFrom) {
        //open the management window again
        ManageTheShipmentsWindow *managementWindow = new ManageTheShipmentsWindow;
        managementWindow->show();
        managementWindow->isModal();
    }

    CreateShipmentsWindow::close();
}


CreateShipmentsWindow::~CreateShipmentsWindow()
{
    delete ui;
}
