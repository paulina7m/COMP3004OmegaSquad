#include <QtGui/QApplication>
#include "testwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestWindow w;
    w.show();

    return a.exec();
}
