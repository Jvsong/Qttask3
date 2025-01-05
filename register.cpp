#include "register.h"
#include "ui_register.h"
#include "idatabase.h"
#include <QMessageBox>
#include "masterview.h"

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_Register_2_clicked()
{
    if (validateInput()) {
        // 获取用户输入的用户名和密码
        QString username = ui->userName->text();
        QString password1 = ui->password1->text();

        // 尝试注册
        if (IDatabase::getInstance().addNewUser(username, password1)) {
            QMessageBox::information(this, "注册成功", "用户注册成功！");
            emit registrationSuccess(username);  // 发出成功信号
            close();  // 关闭注册窗口
        } else {
            QMessageBox::warning(this, "注册失败", "注册失败，用户名可能已存在！");
        }
    }
}

void Register::on_Cancel_clicked()
{
    emit cancelRegistration();  // 发出取消注册的信号
    close();  // 关闭当前窗口
}

bool Register::validateInput()
{
    QString username = ui->userName->text();
    QString password1 = ui->password1->text();
    QString password2 = ui->password2->text();

    if (username.isEmpty() || password1.isEmpty() || password2.isEmpty()) {
        QMessageBox::warning(this, "输入错误", "所有字段都必须填写！");
        return false;
    }

    if (password1 != password2) {
        QMessageBox::warning(this, "密码错误", "两次输入的密码不匹配！");
        return false;
    }

    return true;
}
