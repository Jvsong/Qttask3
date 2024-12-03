#ifndef WELCOME_H
#define WELCOME_H

#include <QDialog>

namespace Ui {
class Page1Dialog;
}

class Page1Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Page1Dialog(QWidget *parent = nullptr);
    ~Page1Dialog();

private:
    Ui::Page1Dialog *ui;
};

#endif // WELCOME_H
