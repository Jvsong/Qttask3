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
    connect(loginView, SIGNAL(goRegister()), this, SLOT(goRegister()));  // 连接信号和槽
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

    connect(doctorView, SIGNAL(goDoctorEditView(int)), this, SLOT(goDoctorEditView(int)));
}

void MainWindow::goDepartmentView()
{
    qDebug() << "goDepartmentView";
    departmentView = new DepartmentView(this);
    pushWidgetToStackView(departmentView);

    connect(departmentView,SIGNAL(goDepartmentEditView(int)),this,SLOT(goDepartmentEditView(int)));
}

void MainWindow::goPatientView()
{
    qDebug() << "goPatientView";
    patientView = new PatientView(this);
    pushWidgetToStackView(patientView);

    connect(patientView,SIGNAL(goPatientEditView(int)),this,SLOT(goPatientEditView(int)));
}

void MainWindow::goRegister()
{
    qDebug() << "goRegister";
    registerWidget = new Register(this);
    pushWidgetToStackView(registerWidget);

    connect(registerWidget,SIGNAL(goRegister(int)),this,SLOT(goRegister(int)));
    connect(registerWidget, &Register::cancelRegistration, this, &MainWindow::onCancelRegistration);
}

void MainWindow::onCancelRegistration()
{
    // 处理取消注册操作的代码
    qDebug() << "Registration cancelled.";
    goPreviousView();  // 跳回到上一界面
}

void MainWindow::goPatientEditView(int rowNo)
{
    qDebug() << "goPatientEditView";
    patientEditView = new PatientEditView(this,rowNo);
    pushWidgetToStackView(patientEditView);

    connect(patientEditView,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void MainWindow::goDoctorEditView(int rowNo)
{
    qDebug() << "goDoctorEditView";
    doctoreditview = new DoctorEditView(this,rowNo);
    pushWidgetToStackView(doctoreditview);

    connect(doctoreditview,SIGNAL(goDoctorEditView()),this,SLOT(goDoctorEditView()));
    connect(doctoreditview, SIGNAL(goPreviousView()), this, SLOT(goPreviousView()));
}

void MainWindow::goDepartmentEditView(int rowNo)
{
    qDebug() << "goDepartmentEditView";
    departmenteditview = new DepartmentEditView(this,rowNo);
    pushWidgetToStackView(departmenteditview);

    connect(departmenteditview,SIGNAL(goDepartmentEditView()),this,SLOT(goDepartmentEditView()));
    connect(departmenteditview, SIGNAL(goPreviousView()), this, SLOT(goPreviousView()));
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



