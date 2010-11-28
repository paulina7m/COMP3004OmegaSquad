#ifndef VIEWTHEDISEASESWINDOW_H
#define VIEWTHEDISEASESWINDOW_H

#include <QDialog>

namespace Ui {
    class ViewTheDiseasesWindow;
}

class ViewTheDiseasesWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ViewTheDiseasesWindow(QWidget *parent = 0);
    ~ViewTheDiseasesWindow();

private:
    Ui::ViewTheDiseasesWindow *ui;
};

#endif // VIEWTHEDISEASESWINDOW_H
