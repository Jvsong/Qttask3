#include "patienteditview.h"
#include "ui_patienteditview.h"
#include <QSqlTableModel>
#include "idatabase.h"
#include <QDataWidgetMapper>


PatientEditView::PatientEditView(QWidget *parent,int index)
    : QWidget(parent)
    , ui(new Ui::PatientEditView)
{
    ui->setupUi(this);

    // 初始化 QDataWidgetMapper
    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().patientTabModel;
    dataMapper->setModel(IDatabase::getInstance().patientTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    // 映射字段与控件
    dataMapper->addMapping(ui->dbEditID, tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->dbEditName, tabModel->fieldIndex("NAME"));
    dataMapper->addMapping(ui->dbEditIDCard, tabModel->fieldIndex("ID_CARD"));
    dataMapper->addMapping(ui->dbSpinHeight, tabModel->fieldIndex("HEIGHT"));
    dataMapper->addMapping(ui->dbWeight, tabModel->fieldIndex("WEIGHT"));
    dataMapper->addMapping(ui->dbEditMobile, tabModel->fieldIndex("MOBILEPHONE"));
    dataMapper->addMapping(ui->dbDateEdit, tabModel->fieldIndex("DATAEDIT"));
    dataMapper->addMapping(ui->dbComboSex, tabModel->fieldIndex("SEX"));
    dataMapper->addMapping(ui->dbCreatedTimestamp, tabModel->fieldIndex("CREATEDTIMESTAMP"));

    // 设置当前索引
    dataMapper->setCurrentIndex(index);


}

PatientEditView::~PatientEditView()
{
    delete ui;
}

void PatientEditView::on_pushButton_clicked()
{
    IDatabase::getInstance().submitPatientEdit();

    emit goPreviousView();
}


void PatientEditView::on_pushButton_2_clicked()
{
    IDatabase::getInstance().revertPatientEdit();

    emit goPreviousView();
}

