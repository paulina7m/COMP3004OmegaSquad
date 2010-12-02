#include "aboutCET.h"
#include "ui_aboutCET.h"

AboutCETDialog::AboutCETDialog(QWidget *parent) : QDialog(parent), ui(new Ui::AboutCETDialog) {
    ui->setupUi(this);
}

void AboutCETDialog::closeHandler() {
    AboutCETDialog::close();
}

AboutCETDialog::~AboutCETDialog()
{
    delete ui;
}
