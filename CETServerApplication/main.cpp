#include <QtGui/QApplication>
#include "cetserver.h"
#include "DatabaseHandler.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CETServer w;
    w.show();
    return a.exec();
}
