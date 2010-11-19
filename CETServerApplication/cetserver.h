#ifndef CETSERVER_H
#define CETSERVER_H

#include <QMainWindow>

namespace Ui {
    class CETServer;
}

class CETServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit CETServer(QWidget *parent = 0);
    ~CETServer();

private:
    Ui::CETServer *ui;
};

#endif // CETSERVER_H
