#include "welcome.h"
#include "ui_welcome.h"

Page1Dialog::Page1Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Page1Dialog)
{
    ui->setupUi(this);
}

Page1Dialog::~Page1Dialog()
{
    delete ui;
}
