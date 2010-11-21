#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QWebElement>
#include "googlemap.h"

//Spencer has added a comment

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void initializeMap();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
