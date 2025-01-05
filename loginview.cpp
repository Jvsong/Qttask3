#include "loginview.h"
#include "ui_loginview.h"
#include "idatabase.h"
#include "register.h"

LoginView::LoginView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginView)
{
    ui->setupUi(this);
}

LoginView::~LoginView()
{
    delete ui;
}

void LoginView::on_btSignIn_clicked()
{
    QString status = IDatabase::getInstance().userLogin(ui->inputusername->text(),
                                       ui->inputpassword->text());

    if(status == "loginOk")
        emit loginSuccess();
}


void LoginView::on_btSignUp_clicked()
{
    emit goRegister();
}

