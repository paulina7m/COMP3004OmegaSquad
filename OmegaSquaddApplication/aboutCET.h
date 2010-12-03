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

signals:
    void dialogToBeClosed();

private:
    Ui::AboutCETDialog *ui;

private slots:
    void closeDialog();


};

#endif // ABOUTCET_H
