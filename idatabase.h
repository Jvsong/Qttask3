#ifndef IDATABASE_H
#define IDATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDataWidgetMapper>
#include <QSqlTableModel>
#include <QItemSelectionModel>


class IDatabase : public QObject
{
    Q_OBJECT
public:
    static IDatabase &getInstance()
    {
        static IDatabase instance;
        return instance;
    }

    bool connectToDatabase(const QString &host, const QString &dbName, const QString &user, const QString &password);
    QSqlQuery executeQuery(const QString &queryStr);

    QString userLogin(QString userName ,QString password);

private:
    explicit IDatabase(QObject *parent = nullptr);
    void initDatabase();
    QSqlDatabase database;

signals:

public:
    bool initPatientModel();

    int addNewPatient();
    bool searchPatient(QString filter);
    bool deleteCurrentPatient();
    bool submitPatientEdit();
    void revertPatientEdit();

    QSqlTableModel *patientTabModel;//数据模型
    QItemSelectionModel *thePatientSelection;//选择模型

};

#endif // IDATABASE_H
