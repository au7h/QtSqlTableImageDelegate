#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QObject>
#include <QSqlDatabase>
#include <QSqlTableModel>

class DbManager : public QObject
{
    Q_OBJECT
public:
    DbManager(QObject *parent = nullptr);
    //destruktor
    ~DbManager();
    void InitDb(QString dbType, QString dbHostName, QString dbLogin, QString dbPass, QString dbName);
    bool dbOpen();
    bool dbClose();
    void dbSelectAll(QString tableName);
    QSqlTableModel* getTableModel();

public slots:

private:
    QSqlDatabase db;
    QSqlTableModel* model;
};

#endif // DBMANAGER_H
