#ifndef ADDDISEASEWINDOW_H
#define ADDDISEASEWINDOW_H

#include <QMainWindow>

namespace Ui {
    class AddDiseaseWindow;
}

class AddDiseaseWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddDiseaseWindow(QWidget *parent = 0);
    ~AddDiseaseWindow();

private:
    Ui::AddDiseaseWindow *ui;
};

#endif // ADDDISEASEWINDOW_H
