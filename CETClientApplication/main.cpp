#include <QtCore/QCoreApplication>
#include "DataHandler.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DataHandler *dh = new DataHandler();
    qDebug() << "Creating DataHandler";
    QList<Province> temp = dh->getProvinces();
    qDebug() << "Getting a list of provinces";
    for (int i = 0; i < temp.size(); i++) {
        qDebug() << "Objects";
        qDebug() << temp[i].getName();
    }

    return a.exec();
}
