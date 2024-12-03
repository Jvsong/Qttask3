#include "masterview.h"
#include "ui_masterview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goLoginView()
{

}

void MainWindow::goWelcomeView()
{

}

void MainWindow::goDoctorView()
{

}

void MainWindow::goDepartmentView()
{

}

void MainWindow::goPatiebtView()
{

}

void MainWindow::goPatientEdictView()
{

}

void MainWindow::gePreviousView()
{

}
