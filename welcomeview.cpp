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


void WelcomeView::on_btDepartmentView_clicked()
{
    emit goDepartmentView();
}


void WelcomeView::on_btDoctorView_clicked()
{
    emit goDoctorView();
}


void WelcomeView::on_btPatientView_clicked()
{
    emit goPatientView();
}

