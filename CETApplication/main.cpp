#include <QtGui/QApplication>
#include "mainwindow.h"

#include "CaseReport.h"
#include <QDate>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    QDate caseDate(2010, 11, 11);
    CaseReport newReport(1, 2, caseDate, 3, 100);
    qDebug() << "Quantity is: " << newReport.getQuantity();
    qDebug() << "Date of report is: " << newReport.getDateOfReport();

    return a.exec();
}
