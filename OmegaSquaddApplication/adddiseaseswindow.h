#ifndef ADDDISEASESWINDOW_H
#define ADDDISEASESWINDOW_H

#include <QDialog>

namespace Ui {
    class AddDiseasesWindow;
}

class AddDiseasesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddDiseasesWindow(QWidget *parent = 0);
    ~AddDiseasesWindow();

private:
    Ui::AddDiseasesWindow *ui;
};

#endif // ADDDISEASESWINDOW_H
