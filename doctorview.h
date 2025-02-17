#ifndef DOCTORVIEW_H
#define DOCTORVIEW_H

#include <QWidget>

namespace Ui {
class DoctorView;
}

class DoctorView : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorView(QWidget *parent = nullptr);
    ~DoctorView();

public slots:

private slots:
    void on_btAdd_clicked();
    void on_btEdit_clicked();
    void on_btDelete_clicked();
    void on_btSearch_clicked();

signals:
    void goDoctorEditView(int idx);

private:
    Ui::DoctorView *ui;
};

#endif // DOCTORVIEW_H
