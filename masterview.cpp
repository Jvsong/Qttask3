#include "masterview.h"
#include "ui_masterview.h"
#include <QDebug>
#include "idatabase.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);

    goLoginView();

    IDatabase::getInstance();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goLoginView()
{
    qDebug() << "gologinView";
    loginView = new LoginView(this);

    pushWidgetToStackView(loginView);

    connect(loginView,SIGNAL(loginSuccess()),this,SLOT(goWelcomeView()));
}

void MainWindow::goWelcomeView()
{
    qDebug() << "welcomeView";
    welcomeview = new WelcomeView(this);

    pushWidgetToStackView(welcomeview);

    connect(welcomeview,SIGNAL(goDoctorView()),this,SLOT(goDoctorView()));
    connect(welcomeview,SIGNAL(goDepartmentView()),this,SLOT(goDepartmentView()));
    connect(welcomeview,SIGNAL(goPatientView()),this,SLOT(goPatientView()));
}

void MainWindow::goDoctorView()
{
    qDebug() << "goDoctorView";
    doctorView = new DoctorView(this);
    pushWidgetToStackView(doctorView);
}

void MainWindow::goDepartmentView()
{
    qDebug() << "goDepartmentView";
    departmentView = new DepartmentView(this);
    pushWidgetToStackView(departmentView);
}

void MainWindow::goPatientView()
{
    qDebug() << "goPatientView";
    patientView = new PatientView(this);
    pushWidgetToStackView(patientView);

    connect(patientView,SIGNAL(goPatientEditView()),this,SLOT(goPatientEditView()));
}


void MainWindow::goPatientEditView()
{
    qDebug() << "goPatientEditView";
    patientEditView = new PatientEditView(this);
    pushWidgetToStackView(patientEditView);
}

void MainWindow::goPreviousView()
{
    int count = ui->stackedWidget->count();

    if(count > 1){
        ui->stackedWidget->setCurrentIndex(count - 2);
        ui->title->setText(ui->stackedWidget->currentWidget()->windowTitle());

        QWidget *widget = ui->stackedWidget->widget(count - 1);
        ui->stackedWidget->removeWidget(widget);
        delete widget;
    }
}

void MainWindow::pushWidgetToStackView(QWidget *widget)
{
    ui->stackedWidget->addWidget(widget);
    int count = ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(count-1);
    ui->title->setText(widget->windowTitle());
}

void MainWindow::on_btback_clicked()
{
    goPreviousView();
}


void MainWindow::on_stackedWidget_currentChanged(int arg1)
{
    int count = ui->stackedWidget->count();
    if(count > 0)
        ui->btback->setEnabled(true);
    else
        ui->btback->setEnabled(false);

    QString title = ui->stackedWidget->currentWidget()->windowTitle();

    if(title == "欢迎"){
        ui->btlogout->setEnabled(true);
        ui->btback->setEnabled(false);
    }else
        ui->btlogout->setEnabled(false);
}


void MainWindow::on_btlogout_clicked()
{
    goPreviousView();
}

