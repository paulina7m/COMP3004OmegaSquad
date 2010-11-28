#ifndef VIEWDISEASEWINDOW_H
#define VIEWDISEASEWINDOW_H

#include <QMainWindow>

namespace Ui {
    class ViewDiseaseWindow;
}

class ViewDiseaseWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ViewDiseaseWindow(QWidget *parent = 0);
    ~ViewDiseaseWindow();

private:
    Ui::ViewDiseaseWindow *ui;
};

#endif // VIEWDISEASEWINDOW_H
