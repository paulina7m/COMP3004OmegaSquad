#include "managetheshipmentswindow.h"
#include "ui_managetheshipmentswindow.h"
#include "createshipmentswindow.h"
#include <QComboBox>

ManageTheShipmentsWindow::ManageTheShipmentsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageTheShipmentsWindow)
{
    ui->setupUi(this);


    /*
    //This calls the database, doesn't work yet
    dh = new DataHandler();
    //Get a list of case reports
    QList<Shipment> shipmentList = dh->getShipments();
    QList<ShipmentDetail> shipmentDetailList = dh->getShipmentDetails();
    QList<SupplyType> supplyList = dh->getSupplyTypes();
    QList<Region1> Region1List = dh->getRegions();


    //Map the edit buttons to the case id number
    QSignalMapper *mapper = new QSignalMapper();

    //CHECK THIS
    //Set the number rows and columns of the table
    ui->tableWidget->setRowCount(shipmentDetailList.size());
    ui->tableWidget->setColumnCount(9);
    QString srcRegionName;
    QString destRegionName;
    QString supplyType;
    QString dateCreated;
    QString dateShipped;
    QString dateReceived;
    QString dateCancelled;
    int status;
    QString statusStr;
    QString quantityStr;
    int quantity;


    ui->tableWidget->setRowCount(shipmentDetailList.size());
    ui->tableWidget->setColumnCount(9);

    for (int i = 0; i < shipmentDetailList.size(); i++) {
        //Get the src/dest Region1 name
        for (int l = 0; l < shipmentList.size(); l++) {
            if (shipmentDetailList[i].getShipmentId() == shipmentList[l].getId()) {
                dateCreated = shipmentList[l].getCreatedDate();
                dateReceived = shipmentList[l].getReceivedDate();
                dateShipped = shipmentList[l].getShippedDate();
                dateCancelled = shipmentList[l].getCancelledDate();
                //shipmentStateStr(int enumValue) {
                //ENUMERATED VALUE, CHANGE TO STRING
                status = shipmentList[l].getShippedDate().toInt();
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
                for (int j = 0; j < Region1List.size(); j++) {
                    if (shipmentList[l].getSrcRegion() == RegionList[j].getId()) {
                           srcRegionName = Region1List[j].getName();
                    }
                    if (shipmentList[l].getDestRegion() == RegionList[j].getId()) {
                           destRegionName = RegionList[j].getName();
                    }
                }
            }
        }


        for (int k = 0; k < supplyList.size(); k++) {
            if (shipmentDetailList[i].getSupplyType() == supplyList[k].getId()) {
                supplyType = supplyList[k].getName();
            }
        }

        quantity = shipmentDetailList[i].getQuantityRequested();


        QComboBox *Box = new QComboBox(this);
        connect(Box, SIGNAL(currentIndexChanged(int)), mapper, SLOT(map()));
        mapper->setMapping(Box, shipmentDetailList[i].getShipmentId());
        QStringList shipStateList;
        shipStateList.push_front("Created");
        shipStateList.push_front("Shipped");
        shipStateList.push_front("Received");
        shipStateList.push_front("Cancelled");

        Box->addItems(shipStateList);

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(srcRegionName));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(destRegionName));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(supplyType));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(quantity));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(dateCreated));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(dateShipped));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(dateReceived));
        ui->tableWidget->setItem(i, 7, new QTableWidgetItem(dateCancelled));
        Box->setCurrentIndex(status);
        ui->tableWidget->setCellWidget(i, 8, Box);
    }
    ui->tableWidget->setSortingEnabled(true);

    connect(mapper, SIGNAL(mapped(const QString &)), this, SIGNAL(changeShipmentStatus(id)));
    */

    QSignalMapper *signalMapper = new QSignalMapper(this);
    //Set the number rows and columns of the table
    ui->tableWidget->setRowCount(4);
    QString quantity;
    ui->tableWidget->setColumnCount(9);
    for (int i = 0; i < 4; i++) {
        int index = 2;
        int row = i;
        int col = 0;

        QComboBox *Box = new QComboBox(this);
        QStringList shipStateList;
        shipStateList.push_front("Created");
        shipStateList.push_front("Shipped");
        shipStateList.push_front("Received");
        shipStateList.push_front("Cancelled");
        Box->addItems(shipStateList);

        ui->tableWidget->setItem(row, col++, new QTableWidgetItem("item 1"));
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem("item 2"));
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem("item 3"));
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem("item 4"));
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem("item 5"));
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem("item 6"));
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem("item 7"));
        ui->tableWidget->setItem(row, col++, new QTableWidgetItem("item 8"));
        ui->tableWidget->setCellWidget(row, col++, Box);
        connect(Box, SIGNAL(currentIndexChanged(int)), signalMapper, SLOT(map()));
        signalMapper->setMapping(Box, QString("%1-%2-%3").arg(row).arg(index).arg(Box->currentIndex()));

        Box->setCurrentIndex(index);

    }
    ui->tableWidget->setSortingEnabled(true);

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(changeShipmentStatus(QString)));

}


void ManageTheShipmentsWindow::changeShipmentStatus(QString idState) {
    //qDebug() << idState;
    QStringList idAndState = idState.split("-");
    int row = idAndState[0].toInt();
    int id = idAndState[1].toInt();
    int state = idAndState[2].toInt();

    qDebug() << "Row: " << row;
    qDebug() << "Id: " << id;
    qDebug() << "Shipment State: " << state;

    if (state == 2) {
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem("item CHANGED"));
    }

    //Save the new state with the given id

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
