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
    if (dh->isConnected()) {
    //Get a list of case reports
    QList<Shipment> shipmentList = dh->getShipments();
    QList<ShipmentDetail> shipmentDetailList = dh->getShipmentDetails();
    QList<SupplyType> supplyList = dh->getSupplyTypes();
    QList<Region1> Region1List = dh->getRegions();


    //Map the edit buttons to the case id number
    QSignalMapper *signalMapper = new QSignalMapper(this);

    //CHECK THIS
    //Set the number rows and columns of the table
    ui->tableWidget->setRowCount(shipmentList.size());
    ui->tableWidget->setColumnCount(10);
    QString srcRegionName;
    int srcRegionId;
    QString destRegionName;
    int destRegionId;
    QString supplyType;
    int supplyId;
    QString dateCreated;
    QString dateShipped;
    QString dateReceived;
    QString dateCancelled;
    int shipmentId;
    int shipmentDetailId;
    QString statusStr;
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
                if (shipmentDetailList[l].getQuantityShipped() > 0) {
                    quantity = shipmentDetailList[l].getQuantityShipped();
                }
                else {
                    quantity = shipmentDetailList[l].getQuantityRequested();
                }
            }
        }

        for (int j = 0; j < Region1List.size(); j++) {
            if (shipmentList[i].getSrcRegion() == Region1List[j].getId()) {
                   srcRegionName = Region1List[j].getName();
                   srcRegionId = Region1List[j].getId();
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
        ui->tableWidget->setItem(i, 0, idText = new QTableWidgetItem());
        idText->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        idText->setData(Qt::DisplayRole, shipmentId);
        ui->tableWidget->setItem(i, 1, sourceText = new QTableWidgetItem(srcRegionName));
        sourceText->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->tableWidget->setItem(i, 2, destText = new QTableWidgetItem(destRegionName));
        destText->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->tableWidget->setItem(i, 3, typeText = new QTableWidgetItem(supplyType));
        typeText->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->tableWidget->setItem(i, 4, quantityText = new QTableWidgetItem());
        quantityText->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        quantityText->setData(Qt::DisplayRole, quantity);
        ui->tableWidget->setItem(i, 5, createdText = new QTableWidgetItem(dateCreated));
        createdText->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->tableWidget->setItem(i, 6, shippedText = new QTableWidgetItem(dateShipped));
        shippedText->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->tableWidget->setItem(i, 7, receivedText = new QTableWidgetItem(dateReceived));
        receivedText->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        ui->tableWidget->setItem(i, 8, cancelledText = new QTableWidgetItem(dateCancelled));
        cancelledText->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);

        //If received
        if (status == 2) {
            ui->tableWidget->setItem(i, 9, statusText = new QTableWidgetItem("Received"));
            statusText->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
        }
        //If cancelled
        else if (status == 3) {
            ui->tableWidget->setItem(i, 9, statusText = new QTableWidgetItem("Cancelled"));
            statusText->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
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
            signalMapper->setMapping(Box, QString("%1-%2-%3-%4-%5-%6").arg(shipmentId).arg(shipmentDetailId).arg(quantity).arg(srcRegionId).arg(destRegionId).arg(supplyId));
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
            signalMapper->setMapping(Box, QString("%1-%2-%3-%4-%5-%6").arg(shipmentId).arg(shipmentDetailId).arg(quantity).arg(srcRegionId).arg(destRegionId).arg(supplyId));
        }
    }
    ui->tableWidget->setSortingEnabled(true);
    ui->tableWidget->resizeRowsToContents();

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(changeShipmentStatus(QString)));
}
    delete dh;
}


void ManageTheShipmentsWindow::changeShipmentStatus(QString idState) {
    //Map the edit buttons to the case id number
    QString messageNotify = "";
    QStringList someIds = idState.split("-");
    QString idStr = "";
    someIds.size();
    int id = someIds[0].toInt();
    int detailId = someIds[1].toInt();
    int shipmentQuantity = someIds[2].toInt();
    int srcRegionId = someIds[3].toInt();
    int destRegionId = someIds[4].toInt();
    int supplyTypeId = someIds[5].toInt();
    QSignalMapper *signalMapper = new QSignalMapper(this);
    QString shipmentState;
    bool cancelled = false;

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

        //Notification box
        messageNotify = "Shipment #";
        messageNotify.append(idStr.setNum(id));
        messageNotify.append(" has been cancelled.");
        msgBox.setText(messageNotify);
        msgBox.exec();
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

        /*
        QList<Shipment> ship = dh->getShipments();
        for(int i = 0; i < ship.size(); i++) {
            qDebug() << ship[i].getReceivedDate();
        }
        */

        //Add to destination region inventory
        //First check to see if there are any identical regions AND supplytypes
        bool updateDestInventory = false;
        QList<Inventory> inventoryList = dh->getInventory();
        for (int i = 0; i < inventoryList.size(); i++) {
            if (inventoryList[i].getRegionId() == destRegionId && inventoryList[i].getSupplyType() == supplyTypeId) {
                int updateQuantity = inventoryList[i].getQuantity() + shipmentQuantity;
                //Update Inventory with the new quantity
                dh->updateInventory(inventoryList[i].getId(), updateQuantity);
                updateDestInventory = true;
                break;
            }
        }

        if (updateDestInventory == false) {
            dh->saveInventory(destRegionId, supplyTypeId, shipmentQuantity);
        }



        delete dh;

        //Notification box
        messageNotify = "Shipment #";
        messageNotify.append(idStr.setNum(id));
        messageNotify.append(" has been received and added to the inventory.");
        msgBox.setText(messageNotify);
        msgBox.exec();
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

        //CHECK THIS!!!!!
        //Substract from source region inventory
        bool updateSrcInventory = false;
        QList<Inventory> srcInventoryList = dh->getInventory();
        for (int i = 0; i < srcInventoryList.size(); i++) {
            if (srcInventoryList[i].getRegionId() == srcRegionId && srcInventoryList[i].getSupplyType() == supplyTypeId) {
                 //if the shipmentQuantity is greater than the srcRegions quantity,
                //change the shipmentQuantity in the destination regions to a lesser amount
                //and the srcRegions to zero
                //Otherwise, just substract
                //qDebug() << "src inventory: " << srcInventoryList[i].getQuantity();
                //qDebug() << "shipment Quantity :" << shipmentQuantity;
                if (srcInventoryList[i].getQuantity() == 0) {
                    //Cancel the shipment
                    dh->updateShipment(id, detailId, shipmentQuantity, "", "", QDate::currentDate().toString("yyyy-MM-dd"), "");
                    cancelled = true;
                    break;
                }
                else if (srcInventoryList[i].getQuantity() < shipmentQuantity) {
                    int updateQuantity = srcInventoryList[i].getQuantity();
                    shipmentQuantity = updateQuantity;
                    QString quantStr;
                    //Substract the updated quantity from the source regions inventory
                    dh->updateInventory(srcInventoryList[i].getId(), 0);
                    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(quantStr.setNum(shipmentQuantity)));
                    updateSrcInventory = true;
                    break;
                }
                else {
                    int updateQuantity = srcInventoryList[i].getQuantity() - shipmentQuantity;
                    shipmentQuantity = updateQuantity;
                    //Substract the updated quantity from the source regions inventory
                    dh->updateInventory(srcInventoryList[i].getId(), updateQuantity);
                    updateSrcInventory = true;
                    break;
                }
            }
        }

        if (cancelled) {
            ui->tableWidget->setItem(row, 8, new QTableWidgetItem(QDate::currentDate().toString("yyyy-MM-dd")));
            ui->tableWidget->removeCellWidget(row, 9);
            ui->tableWidget->setItem(row, 9, new QTableWidgetItem("Cancelled"));

            connect(Box, SIGNAL(currentIndexChanged(int)), signalMapper, SLOT(map()));

            signalMapper->setMapping(Box, QString("%1-%2-%3-%4-%5-%6").arg(id).arg(detailId).arg(shipmentQuantity).arg(srcRegionId).arg(destRegionId).arg(supplyTypeId));
            connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(changeShipmentStatus(QString)));

            messageNotify = "Shipment #";
            messageNotify.append(idStr.setNum(id));
            messageNotify.append(" has been cancelled. Source region out of stock.");
            msgBox.setText(messageNotify);
            msgBox.exec();
        }
        else {
            if (updateSrcInventory == false) {
                //qDebug() << "error, this source inventory should exist";
            }

            //Update the Shipment in the database
            //Update Shipments
            //Required inputs: shipment id number , shipmentdetail id number and any one of ShippedDate, ReceivedDate or CancelledDate.
            //NOTE: Any dates you're not updating must be passed in as empty strings.
            //If you pass in a shippedDate string, make sure you pass in a quantityShipped number (greater than 0), otherwise, the quantityShipped number should be 0
            //Optional inputs: notes (this can be empty string)
            //qDebug() << shipmentQuantity;
            dh->updateShipment(id, detailId, shipmentQuantity, QDate::currentDate().toString("yyyy-MM-dd"), "", "", "");
            delete dh;

            connect(Box, SIGNAL(currentIndexChanged(int)), signalMapper, SLOT(map()));
            //row, id, shippingstate for Shipment
            signalMapper->setMapping(Box, QString("%1-%2-%3-%4-%5-%6").arg(id).arg(detailId).arg(shipmentQuantity).arg(srcRegionId).arg(destRegionId).arg(supplyTypeId));
            connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(changeShipmentStatus(QString)));

            //Notification box
            messageNotify = "Shipment #";
            messageNotify.append(idStr.setNum(id));
            messageNotify.append(" has been shipped.");
            msgBox.setText(messageNotify);
            msgBox.exec();
        }
    }

}

void ManageTheShipmentsWindow::ManageTheShipmentsWindowSubmitButtonHandler() {
    CreateShipmentsWindow *createShipmentsWindow = new CreateShipmentsWindow;
    createShipmentsWindow->show();
    createShipmentsWindow->isModal();
    createShipmentsWindow->fromManager(1);
    ManageTheShipmentsWindow::close();
}

void ManageTheShipmentsWindow::ManageTheShipmentsWindowCancelButtonHandler() {
    ManageTheShipmentsWindow::close();
}

ManageTheShipmentsWindow::~ManageTheShipmentsWindow()
{
    delete ui;
}
