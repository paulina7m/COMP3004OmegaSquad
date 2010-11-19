#ifndef CETSERVER_H
#define CETSERVER_H

#include <QMainWindow>
#include "DatabaseHandler.h"

namespace Ui {
    class CETServer;
}

class CETServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit CETServer(QWidget *parent = 0);
    ~CETServer();

/*UI Handlers*/
public slots:
    //Start server button
    void startServerButtonHandler();
    //Stop server button
    void stopServerButtonHandler();
    //Output the command and reply status
    void commandStatus(QString);

private:
    Ui::CETServer *ui;
    DatabaseHandler *sqLite;

private slots:
    void on_actionExit_triggered();
};

#endif // CETSERVER_H
