#include <QtGui/QApplication>
#include "cetserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CETServer w;
    w.show();

    return a.exec();
}
