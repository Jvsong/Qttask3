#include "welcomeview.h"
#include "ui_welcomeview.h"
#include <QDebug>

WelcomeView::WelcomeView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WelcomeView)
{
    qDebug()<<"create welcomeView";
    ui->setupUi(this);
}

WelcomeView::~WelcomeView()
{
    qDebug()<< "destory welcomeView";
    delete ui;
}

void WelcomeView::on_pushButton_clicked()
{

}

