#ifndef VIEWTHESUPPLIESWINDOW_H
#define VIEWTHESUPPLIESWINDOW_H

#include <QDialog>

namespace Ui {
    class ViewTheSuppliesWindow;
}

class ViewTheSuppliesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ViewTheSuppliesWindow(QWidget *parent = 0);
    ~ViewTheSuppliesWindow();

private:
    Ui::ViewTheSuppliesWindow *ui;
};

#endif // VIEWTHESUPPLIESWINDOW_H
