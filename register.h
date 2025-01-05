#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include <QString>

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_Register_2_clicked();
    void on_Cancel_clicked();

signals:
    void registrationSuccess(QString username);
    void cancelRegistration();
    void goRegister();
    void goPreviousView();  // 返回上一个视图的信号

private:
    Ui::Register *ui;

    bool validateInput();
};

#endif // REGISTER_H
