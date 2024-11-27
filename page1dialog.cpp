#include "page1dialog.h"
#include "ui_page1dialog.h"

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
