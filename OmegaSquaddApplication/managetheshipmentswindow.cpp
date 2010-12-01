#include "managetheshipmentswindow.h"
#include "ui_managetheshipmentswindow.h"
#include "createshipmentswindow.h"
#include <QComboBox>
#include <QCheckBox>

ManageTheShipmentsWindow::ManageTheShipmentsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageTheShipmentsWindow)
{
    ui->setupUi(this);
    shipStateList.clear();


    //This calls the database
    DataHandler *dh = new DataHandler();
    //Get a list of case reports
    QList<Shipment> shipmentList = dh->getShipments();
    QList<ShipmentDetail> shipmentDetailList = dh->getShipmentDetails();
    QList<SupplyType> supplyList = dh->getSupplyTypes();
    QList<Region1> Region1List = dh->getRegions();
    delete dh;

    //Map the edit buttons to the case id number
    QSignalMapper *signalMapper = new QSignalMapper(this);

    //CHECK THIS
    //Set the number rows and columns of the table
    ui->tableWidget->setRowCount(shipmentList.size());
    ui->tableWidget->setColumnCount(10);
    QString srcRegionName;
    QString destRegionName;
    int destRegionId;
    QString supplyType;
    int supplyId;
    QString dateCreated;
    QString dateShipped;
    QString dateReceived;
    QString dateCancelled;
    int shipmentId;
    QString shipmentIdStr;
    int shipmentDetailId;
    QString statusStr;
    QString quantityStr;
    int quantity;

    //qDebug() << "before looping";
    for (int i = 0; i < shipmentList.size(); i++) {
        shipmentId= shipmentList[i].getId();
        //qDebug() << "looping";
        //Get the Supply type and quantity
        for (int l = 0; l < shipmentDetailList.size(); l++) {
            if (shipmentDetailList[l].getShipmentId() == shipmentList[i].getId()) {
                shipmentDetailId = shipmentDetailList[l].getId();
                for (int k = 0; k < supplyList.size(); k++) {
                    if (shipmentDetailList[l].getSupplyType() == supplyList[k].getId()) {
                        supplyType = supplyList[k].getName();
                        supplyId = supplyList[k].getId();
                    }
                }
                quantity = shipmentDetailList[l].getQuantityRequested();
            }
        }

        for (int j = 0; j < Region1List.size(); j++) {
            if (shipmentList[i].getSrcRegion() == Region1List[j].getId()) {
                   srcRegionName = Region1List[j].getName();
            }
            if (shipmentList[i].getDestRegion() == Region1List[j].getId()) {
                   destRegionName = Region1List[j].getName();
                   destRegionId = Region1List[j].getId();
            }
        }


        dateCreated = shipmentList[i].getCreatedDate();
        dateReceived = shipmentList[i].getReceivedDate();
        dateShipped = shipmentList[i].getShippedDate();
        dateCancelled = shipmentList[i].getCancelledDate();
        //qDebug() << dateReceived;
        if (dateReceived == "null") {
            dateReceived = "";
        }
        if (dateShipped == "null") {
            dateShipped = "";
        }
        if (dateCancelled == "null") {
            dateCancelled = "";
        }
        //shipmentStateStr(int enumValue) {
        //qDebug() << "Shipment state" << shipmentList[l].getShipmentState();
        //ENUMERATED VALUE, CHANGE TO STRING

        status = shipmentList[i].getShipmentState();

        if (status == 0) {
            statusStr = "Created";
        }
        else if (status == 1) {
            statusStr = "Shipped";
        }
        else if (status == 2) {
            statusStr = "Received";
        }
        else {
            statusStr = "Cancelled";
        }







        //qDebug() << i << srcRegionName;
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(shipmentIdStr.setNum(shipmentId)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(srcRegionName));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(destRegionName));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(supplyType));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(quantityStr.setNum(quantity)));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(dateCreated));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(dateShipped));
        ui->tableWidget->setItem(i, 7, new QTableWidgetItem(dateReceived));
        ui->tableWidget->setItem(i, 8, new QTableWidgetItem(dateCancelled));

        //If received
        if (status == 2) {
            ui->tableWidget->setItem(i, 9, new QTableWidgetItem("Received"));
        }
        //If cancelled
        else if (status == 3) {
            ui->tableWidget->setItem(i, 9, new QTableWidgetItem("Cancelled"));
        }
        //If Shipped, cannot be cancelled or created, remove from list
        else if (status == 1) {
            QComboBox *Box = new QComboBox(this);
            shipStateList.clear();
            shipStateList.push_front("Received");
            shipStateList.push_front("Shipped");

            Box->addItems(shipStateList);

            ui->tableWidget->setCellWidget(i, 9, Box);
            Box->setCurrentIndex(0);


            connect(Box, SIGNAL(currentIndexChanged(int)), signalMapper, SLOT(map()));
            //row, id, shippingstate for Shipment
            signalMapper->setMapping(Box, QString("%1-%2-%3-%4-%5").arg(shipmentId).arg(shipmentDetailId).arg(quantity).arg(destRegionId).arg(supplyId));
        }
        //otherwise have a dropdown list of options
        else {
            QComboBox *Box = new QComboBox(this);
            shipStateList.clear();
            shipStateList.push_front("Cancelled");
            shipStateList.push_front("Shipped");
            shipStateList.push_front("Created");

            Box->addItems(shipStateList);

            ui->tableWidget->setCellWidget(i, 9, Box);
            Box->setCurrentIndex(status);

            connect(Box, SIGNAL(currentIndexChanged(int)), signalMapper, SLOT(map()));
            //row, id, shippingstate for Shipment
            signalMapper->setMapping(Box, QString("%1-%2-%3-%4-%5").arg(shipmentId).arg(shipmentDetailId).arg(quantity).arg(destRegionId).arg(supplyId));
        }
    }
    ui->tableWidget->setSortingEnabled(true);

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(changeShipmentStatus(QString)));
}


void ManageTheShipmentsWindow::changeShipmentStatus(QString idState) {
    //Map the edit buttons to the case id number
    QStringList someIds = idState.split("-");
    QString idStr;
    int id = someIds[0].toInt();
    int detailId = someIds[1].toInt();
    int shipmentQuantity = someIds[2].toInt();
    int regionId = someIds[3].toInt();
    int supplyTypeId = someIds[4].toInt();
    QSignalMapper *signalMapper = new QSignalMapper(this);
    QString shipmentState;

    QList<QTableWidgetItem*> widgetItems = ui->tableWidget->findItems(idStr.setNum(id), Qt::MatchExactly);
    int row = ui->tableWidget->row(widgetItems[0]);
    QComboBox* Box = (QComboBox*)ui->tableWidget->cellWidget(row, 9);
    shipmentState = Box->currentText();

    /*
    qDebug() << "Row: " << row;
    qDebug() << "Id: " << id;
    qDebug() << "ShipmentDetail Id: " << detailId;
    qDebug() << "Shipment Quantity: " << shipmentQuantity;
    qDebug() << "Shipment State: " << shipmentState;
    qDebug() << "Region: " << regionId;
    qDebug() << "supplyTypeId: " << supplyTypeId;
    */


    //Cancelled
    if (shipmentState == "Cancelled") {
        ui->tableWidget->setItem(row, 8, new QTableWidgetItem(QDate::currentDate().toString("yyyy-MM-dd")));
        ui->tableWidget->removeCellWidget(row, 9);
        ui->tableWidget->setItem(row, 9, new QTableWidgetItem("Cancelled"));

        DataHandler *dh = new DataHandler();
        //Update the Shipment in the database
        //Update Shipments
        //Required inputs: shipment id number , shipmentdetail id number and any one of ShippedDate, ReceivedDate or CancelledDate.
        //NOTE: Any dates you're not updating must be passed in as empty strings.
        //If you pass in a shippedDate string, make sure you pass in a quantityShipped number (greater than 0), otherwise, the quantityShipped number should be 0
        //Optional inputs: notes (this can be empty string)
        dh->updateShipment(id, detailId, 0, "", "", QDate::currentDate().toString("yyyy-MM-dd"), "");
        delete dh;
    }
    //Received
    else if (shipmentState == "Received") {
        ui->tableWidget->setItem(row, 7, new QTableWidgetItem(QDate::currentDate().toString("yyyy-MM-dd")));
        ui->tableWidget->removeCellWidget(row, 9);
        ui->tableWidget->setItem(row, 9, new QTableWidgetItem("Received"));

        DataHandler *dh = new DataHandler();
        //Update the Shipment in the database
        //Update Shipments
        //Required inputs: shipment id number , shipmentdetail id number and any one of ShippedDate, ReceivedDate or CancelledDate.
        //NOTE: Any dates you're not updating must be passed in as empty strings.
        //If you pass in a shippedDate string, make sure you pass in a quantityShipped number (greater than 0), otherwise, the quantityShipped number should be 0
        //Optional inputs: notes (this can be empty string)
        dh->updateShipment(id, detailId, 0, "", QDate::currentDate().toString("yyyy-MM-dd"), "", "");

        //Add to inventory
        //First check to see if there are any identical regions AND supplytypes
        QList<Inventory> inventoryList = dh->getInventory();
        for (int i = 0; i < inventoryList.size(); i++) {
            if (inventoryList[i].getRegionId() == regionId && inventoryList[i].getSupplyType() == supplyTypeId) {
                int updateQuantity = inventoryList[i].getQuantity() + shipmentQuantity;
                //Update Inventory with the new quantity
                dh->updateInventory(inventoryList[i].getId(), updateQuantity);
            }
            else {
                //Insert new Inventory
                dh->saveInventory(regionId, supplyTypeId, shipmentQuantity);
            }
        }

        delete dh;
    }
    //Shipped
    else if (shipmentState == "Shipped") {
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(QDate::currentDate().toString("yyyy-MM-dd")));
        ui->tableWidget->removeCellWidget(row, 9);
        QComboBox *Box = new QComboBox(this);
        shipStateList.clear();
        shipStateList.push_front("Received");
        shipStateList.push_front("Shipped");

        Box->addItems(shipStateList);

        ui->tableWidget->setCellWidget(row, 9, Box);
        Box->setCurrentIndex(0);

        DataHandler *dh = new DataHandler();
        //Update the Shipment in the database
        //Update Shipments
        //Required inputs: shipment id number , shipmentdetail id number and any one of ShippedDate, ReceivedDate or CancelledDate.
        //NOTE: Any dates you're not updating must be passed in as empty strings.
        //If you pass in a shippedDate string, make sure you pass in a quantityShipped number (greater than 0), otherwise, the quantityShipped number should be 0
        //Optional inputs: notes (this can be empty string)
        dh->updateShipment(id, detailId, shipmentQuantity, QDate::currentDate().toString("yyyy-MM-dd"), "", "", "");
        delete dh;

        connect(Box, SIGNAL(currentIndexChanged(int)), signalMapper, SLOT(map()));
        //row, id, shippingstate for Shipment
        signalMapper->setMapping(Box, QString("%1-%2-%3").arg(id).arg(detailId).arg(shipmentQuantity));
        connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(changeShipmentStatus(QString)));
    }

}

void ManageTheShipmentsWindow::ManageTheShipmentsWindowSubmitButtonHandler() {
    CreateShipmentsWindow *createShipmentsWindow = new CreateShipmentsWindow;
    createShipmentsWindow->show();
    createShipmentsWindow->isModal();
}

void ManageTheShipmentsWindow::ManageTheShipmentsWindowCancelButtonHandler() {
    ManageTheShipmentsWindow::close();
}

ManageTheShipmentsWindow::~ManageTheShipmentsWindow()
{
    delete ui;
}
