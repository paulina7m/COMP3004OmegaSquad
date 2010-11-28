#include <QtCore/QCoreApplication>
#include "DataHandler.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*
    DataHandler *dh = new DataHandler();
    qDebug() << "Creating DataHandler";
    QList<CaseReport> temp = dh->getCaseReports();
    qDebug() << "Getting a list of cases";
    for (int i = 0; i < temp.size(); i++) {
        qDebug() << "Objects";
        qDebug() << temp[i].getId();
        qDebug() << temp[i].getRegionId();
        qDebug() << temp[i].getDateOfReport();
        qDebug() << temp[i].getDiseaseType();
        qDebug() << temp[i].getQuantity();
    }
    */

    return a.exec();
}
