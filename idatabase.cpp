#include "idatabase.h"

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

bool IDatabase::initPatientModel()
{
    patientTabModel = new QSqlTableModel(this,database);
    patientTabModel->setTable("patient");
    patientTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    patientTabModel->setSort(patientTabModel->fieldIndex("name"),Qt::AscendingOrder);

    if(!(patientTabModel->select())){
        return false;
    }

    thePatientSelection = new QItemSelectionModel(patientTabModel);
    return true;
}


IDatabase::IDatabase(QObject *parent) : QObject{parent}
{
    initDatabase();
}

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

QSqlQuery IDatabase::executeQuery(const QString &queryStr)
{
    QSqlQuery query;
    if (!query.exec(queryStr)) {
        qDebug() << "Query failed:" << query.lastError().text();
    }
    return query;
}

QString IDatabase::userLogin(QString userName, QString password)
{
    QSqlQuery query;
    query.prepare("select username,password from user where username = :USER");
    query.bindValue(":USER",userName);
    query.exec();
    qDebug() << query.lastQuery() << query.first();

    if(query.first() && query.value("username").isValid()){
        QString passwd = query.value("password").toString();
        if(passwd == password){
            qDebug() << "loginOk";
            return "loginOk";
        }else{
            qDebug() << "wrongPassword";
            return "wrongPassword";
        }
    }
    else{
        qDebug()<<"no such user";
        return "wrongPassword";
    }
    query.first();

    return "LoginFail";
}
