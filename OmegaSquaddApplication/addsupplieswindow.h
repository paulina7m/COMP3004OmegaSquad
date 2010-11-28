#ifndef ADDSUPPLIESWINDOW_H
#define ADDSUPPLIESWINDOW_H

#include <QDialog>

namespace Ui {
    class AddSuppliesWindow;
}

class AddSuppliesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddSuppliesWindow(QWidget *parent = 0);
    ~AddSuppliesWindow();

private:
    Ui::AddSuppliesWindow *ui;
};

#endif // ADDSUPPLIESWINDOW_H
