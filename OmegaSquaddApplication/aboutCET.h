#ifndef ABOUTCET_H
#define ABOUTCET_H

#include <QDialog>

namespace Ui {
    class AboutCETDialog;
}

class AboutCETDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutCETDialog(QWidget *parent = 0);
    ~AboutCETDialog();


private:
    Ui::AboutCETDialog *ui;

private slots:
    void closeHandler();


};

#endif // ABOUTCET_H
