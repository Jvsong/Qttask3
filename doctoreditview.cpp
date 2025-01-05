#include "doctoreditview.h"
#include "ui_doctoreditview.h"
#include "idatabase.h"
#include <QSqlTableModel>
#include <QDataWidgetMapper>

DoctorEditView::DoctorEditView(QWidget *parent, int index)
    : QWidget(parent)
    , ui(new Ui::DoctorEditView) // 修改类名为 Ui::DoctorEditView
{
    ui->setupUi(this);

    // 初始化 QDataWidgetMapper
    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().doctorTabModel;
    dataMapper->setModel(tabModel); // 修复重复调用 doctorTabModel
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    // 映射字段与控件
    dataMapper->addMapping(ui->dbEditID, tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->dbEditEmployeeNo, tabModel->fieldIndex("EMPLOYEENO"));
    dataMapper->addMapping(ui->dbEditName, tabModel->fieldIndex("NAME"));
    dataMapper->addMapping(ui->dbEditDepartmentID, tabModel->fieldIndex("DEPARTMENT_ID"));

    // 设置当前索引
    dataMapper->setCurrentIndex(index);
}

DoctorEditView::~DoctorEditView()
{
    delete ui;
}

void DoctorEditView::on_pushButton_clicked()
{
    IDatabase::getInstance().submitDoctorEdit();
    emit goPreviousView();
}

void DoctorEditView::on_pushButton_2_clicked()
{
    IDatabase::getInstance().revertDoctorEdit();
    emit goPreviousView();
}
