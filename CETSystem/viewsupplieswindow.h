#ifndef VIEWSUPPLIESWINDOW_H
#define VIEWSUPPLIESWINDOW_H

#include <QMainWindow>

namespace Ui {
    class ViewSuppliesWindow;
}

class ViewSuppliesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewSuppliesWindow(QWidget *parent = 0);
    ~ViewSuppliesWindow();

private:
    Ui::ViewSuppliesWindow *ui;
};

#endif // VIEWSUPPLIESWINDOW_H
