#include <QtGui/QApplication>
#include "mainwindow.h"

#include "CaseReport.h"
#include "DiseaseType.h"
#include "Shipment.h"
#include "Inventory.h"
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    QString caseDate = "2010-11-11";
    CaseReport newReport(1, 2, caseDate, 3, 100);
    qDebug() << "Quantity is: " << newReport.getQuantity();
    qDebug() << "Date of report is: " << newReport.getDateOfReport();

    QString nameOfDisease = "H1N1";
    DiseaseType newDisease(2, nameOfDisease, 5, 1);
    qDebug() << newDisease.getName();

    Inventory newInventory(2, 2, 2, 2);
    qDebug() << newInventory.getQuantity();

    Shipment newShipment(2, 13, 14, Shipment::Created, "A Date");
    qDebug() << newShipment.getShipmentState();
    newShipment.setShipmentState(Shipment::Cancelled);
    qDebug() << newShipment.getShipmentState();

    return a.exec();
}
