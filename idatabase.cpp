#include "idatabase.h"
#include <QSqlRecord>
#include <QUuid>
#include <QDateTime>

// 初始化数据库
void IDatabase::initDatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    QString aFile = "E:/Qt6/Qt/database/lab4a.db";
    database.setDatabaseName(aFile);

    if (!database.open()) {
        qDebug() << "Failed to open database:" << database.lastError().text();
    } else {
        qDebug() << "Database opened successfully";
    }
}

// 初始化 Patient 数据模型
bool IDatabase::initPatientModel()
{
    patientTabModel = new QSqlTableModel(this, database);
    patientTabModel->setTable("patient");
    patientTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    patientTabModel->setSort(patientTabModel->fieldIndex("name"), Qt::AscendingOrder);

    if (!patientTabModel->select()) {
        return false;
    }

    thePatientSelection = new QItemSelectionModel(patientTabModel);
    return true;
}

// 添加新 Patient
int IDatabase::addNewPatient()
{
    patientTabModel->insertRow(patientTabModel->rowCount(), QModelIndex());
    QModelIndex curIndex = patientTabModel->index(patientTabModel->rowCount() - 1, 1);

    int curRecNo = curIndex.row();
    QSqlRecord curRec = patientTabModel->record(curRecNo); // 获取当前记录
    curRec.setValue("CREATEDTIMESTAMP", QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    curRec.setValue("ID", QUuid::createUuid().toString(QUuid::WithoutBraces));

    patientTabModel->setRecord(curRecNo, curRec);

    return curIndex.row();
}

// 搜索 Patient
bool IDatabase::searchPatient(QString filter)
{
    patientTabModel->setFilter(filter);
    return patientTabModel->select();
}

// 删除当前 Patient
bool IDatabase::deleteCurrentPatient()
{
    QModelIndex curIndex = thePatientSelection->currentIndex();
    patientTabModel->removeRow(curIndex.row());
    patientTabModel->submitAll();
    patientTabModel->select();
}

// 提交编辑 Patient
bool IDatabase::submitPatientEdit()
{
    return patientTabModel->submitAll();
}

// 撤销编辑 Patient
void IDatabase::revertPatientEdit()
{
    patientTabModel->revertAll();
}

// 初始化 Doctor 数据模型
bool IDatabase::initDoctorModel()
{
    doctorTabModel = new QSqlTableModel(this, database);
    doctorTabModel->setTable("doctor");
    doctorTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    doctorTabModel->setSort(doctorTabModel->fieldIndex("name"), Qt::AscendingOrder);

    if (!doctorTabModel->select()) {
        return false;
    }

    theDoctorSelection = new QItemSelectionModel(doctorTabModel);
    return true;
}

// 添加新 Doctor
int IDatabase::addNewDoctor()
{
    doctorTabModel->insertRow(doctorTabModel->rowCount(), QModelIndex());
    QModelIndex curIndex = doctorTabModel->index(doctorTabModel->rowCount() - 1, 1);

    int curRecNo = curIndex.row();
    QSqlRecord curRec = doctorTabModel->record(curRecNo); // 获取当前记录
    curRec.setValue("ID", QUuid::createUuid().toString(QUuid::WithoutBraces));
    doctorTabModel->setRecord(curRecNo, curRec);

    return curIndex.row();
}

// 搜索 Doctor
bool IDatabase::searchDoctor(QString filter)
{
    doctorTabModel->setFilter(filter);
    return doctorTabModel->select();
}

// 删除当前 Doctor
bool IDatabase::deleteCurrentDoctor()
{
    QModelIndex curIndex = theDoctorSelection->currentIndex();
    doctorTabModel->removeRow(curIndex.row());
    doctorTabModel->submitAll();
    doctorTabModel->select();
}

// 提交编辑 Doctor
bool IDatabase::submitDoctorEdit()
{
    return doctorTabModel->submitAll();
}

// 撤销编辑 Doctor
void IDatabase::revertDoctorEdit()
{
    doctorTabModel->revertAll();
}

// 构造函数
IDatabase::IDatabase(QObject *parent) : QObject{parent}
{
    initDatabase();
}

// 连接数据库
bool IDatabase::connectToDatabase(const QString &host, const QString &dbName, const QString &user, const QString &password)
{
    database.setHostName(host);
    database.setDatabaseName(dbName);
    database.setUserName(user);
    database.setPassword(password);

    if (!database.open()) {
        qDebug() << "Connection failed:" << database.lastError().text();
        return false;
    }
    qDebug() << "Connected to database successfully";
    return true;
}

// 执行查询
QSqlQuery IDatabase::executeQuery(const QString &queryStr)
{
    QSqlQuery query;
    if (!query.exec(queryStr)) {
        qDebug() << "Query failed:" << query.lastError().text();
    }
    return query;
}

// 用户登录验证
QString IDatabase::userLogin(QString userName, QString password)
{
    QSqlQuery query;
    query.prepare("select username,password from user where username = :USER");
    query.bindValue(":USER", userName);
    query.exec();
    qDebug() << query.lastQuery() << query.first();

    if (query.first() && query.value("username").isValid()) {
        QString passwd = query.value("password").toString();
        if (passwd == password) {
            qDebug() << "loginOk";
            return "loginOk";
        } else {
            qDebug() << "wrongPassword";
            return "wrongPassword";
        }
    } else {
        qDebug() << "no such user";
        return "wrongPassword";
    }
    query.first();

    return "LoginFail";
}




// 初始化 Department 数据模型
bool IDatabase::initDepartmentModel()
{
    departmentTabModel = new QSqlTableModel(this, database);
    departmentTabModel->setTable("department");
    departmentTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    departmentTabModel->setSort(departmentTabModel->fieldIndex("name"), Qt::AscendingOrder);

    if (!departmentTabModel->select()) {
        return false;
    }

    theDepartmentSelection = new QItemSelectionModel(departmentTabModel);
    return true;
}

// 添加新 Department
int IDatabase::addNewDepartment()
{
    departmentTabModel->insertRow(departmentTabModel->rowCount(), QModelIndex());
    QModelIndex curIndex = departmentTabModel->index(departmentTabModel->rowCount() - 1, 1);

    int curRecNo = curIndex.row();
    QSqlRecord curRec = departmentTabModel->record(curRecNo); // 获取当前记录
    curRec.setValue("ID", QUuid::createUuid().toString(QUuid::WithoutBraces));

    departmentTabModel->setRecord(curRecNo, curRec);

    return curIndex.row();
}

// 搜索 Department
bool IDatabase::searchDepartment(QString filter)
{
    departmentTabModel->setFilter(filter);
    return departmentTabModel->select();
}

// 删除当前 Department
bool IDatabase::deleteCurrentDepartment()
{
    QModelIndex curIndex = theDepartmentSelection->currentIndex();
    departmentTabModel->removeRow(curIndex.row());
    departmentTabModel->submitAll();
    departmentTabModel->select();
}

// 提交编辑 Department
bool IDatabase::submitDepartmentEdit()
{
    return departmentTabModel->submitAll();
}

// 撤销编辑 Department
void IDatabase::revertDepartmentEdit()
{
    departmentTabModel->revertAll();
}
