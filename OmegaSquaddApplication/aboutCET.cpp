#include "aboutCET.h"
#include "ui_aboutCET.h"

AboutCETDialog::AboutCETDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AboutCETDialog) {
    ui->setupUi(this);
    QObject::connect(ui->okButton,SIGNAL(clicked()),this,SLOT(closeDialog()));
}

void AboutCETDialog::closeDialog(){
    emit dialogToBeClosed();
}

AboutCETDialog::~AboutCETDialog()
{
    delete ui;
}
