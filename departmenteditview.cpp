#include "departmenteditview.h"
#include "ui_departmenteditview.h"
#include "idatabase.h"
#include <QSqlTableModel>

DepartmentEditView::DepartmentEditView(QWidget *parent, int index)
    : QWidget(parent)
    , ui(new Ui::DepartmentEditView)
{
    ui->setupUi(this);

    // 初始化 QDataWidgetMapper
    dataMapper = new QDataWidgetMapper(this);
    QSqlTableModel *tabModel = IDatabase::getInstance().departmentTabModel;
    dataMapper->setModel(tabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    // 映射字段与控件
    dataMapper->addMapping(ui->dbEditID, tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->dbEditName, tabModel->fieldIndex("NAME"));

    // 设置当前索引
    dataMapper->setCurrentIndex(index);
}

DepartmentEditView::~DepartmentEditView()
{
    delete ui;
}

void DepartmentEditView::on_saveButton_clicked()
{
    IDatabase::getInstance().submitDepartmentEdit();
    emit goPreviousView();
}

void DepartmentEditView::on_cancelButton_clicked()
{
    IDatabase::getInstance().revertDepartmentEdit();
    emit goPreviousView();
}
