#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include <QMainWindow>
#include "doctoreditview.h"
#include "loginview.h"
#include "doctorview.h"
#include "welcomeView.h"
#include "departmentview.h"
#include "patienteditview.h"
#include "patientview.h"
#include "departmenteditview.h"
#include "register.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
        void goLoginView();
        void goWelcomeView();
        void goDoctorView();
        void goDepartmentView();
        void goPatientView();
        void goPatientEditView(int rowNo);
        void goPreviousView();
        void goDoctorEditView(int rowNo);
        void goDepartmentEditView(int rowNo);
        void goRegister();
        void onCancelRegistration();

    private slots:
        void on_btback_clicked();

        void on_stackedWidget_currentChanged(int arg1);

        void on_btlogout_clicked();

    private:
    void pushWidgetToStackView(QWidget *widget);

    Ui::MainWindow *ui;

    LoginView *loginView;
    DoctorView *doctorView;
    PatientEditView *patientEditView;
    PatientView *patientView;
    DepartmentView *departmentView;
    WelcomeView *welcomeview;
    DoctorEditView *doctoreditview;
    DepartmentEditView *departmenteditview;
    Register *registerWidget;

};
#endif // MASTERVIEW_H
