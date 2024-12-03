#include "masterview.h"
#include "ui_masterview.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    goLoginView();
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

void MainWindow::goPatiebtView()
{
    qDebug() << "goPatiebtView";
    patientView = new PatientView(this);

    pushWidgetToStackView(patientView);
}

void MainWindow::goPatientEdictView()
{
    qDebug() << "goPatientEdictView";
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

