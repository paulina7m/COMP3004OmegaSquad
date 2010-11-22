#ifndef MANAGESHIPMENTSWINDOW_H
#define MANAGESHIPMENTSWINDOW_H

#include <QMainWindow>

namespace Ui {
    class ManageShipmentsWindow;
}

class ManageShipmentsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManageShipmentsWindow(QWidget *parent = 0);
    ~ManageShipmentsWindow();

private:
    Ui::ManageShipmentsWindow *ui;
};

#endif // MANAGESHIPMENTSWINDOW_H
