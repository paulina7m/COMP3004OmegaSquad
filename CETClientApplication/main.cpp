#include <QtCore/QCoreApplication>
#include "DataHandler.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DataHandler *dh = new DataHandler();
    qDebug() << "Creating DataHandler";
    QList<Region> temp = dh->getRegions();
    qDebug() << "Getting a list of cases";
    for (int i = 0; i < temp.size(); i++) {
        qDebug() << "Objects";
        qDebug() << temp[i].getName();
    }

    return a.exec();
}
