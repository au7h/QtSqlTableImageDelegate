#include "dbmanager.h"

DbManager::DbManager(QObject *parent) : QObject (parent){}

DbManager::~DbManager(){ delete model; }

void DbManager::InitDb(QString dbType, QString dbHostName, QString dbLogin, QString dbPass, QString dbName)
{
    db = QSqlDatabase::addDatabase(dbType);
    db.setHostName(dbHostName);
    db.setUserName(dbLogin);
    db.setPassword(dbPass);
    db.setDatabaseName(dbName);
}

bool DbManager::dbOpen()
{
    if(db.open()) return true;
    else return false;
}

bool DbManager::dbClose()
{
    if(db.open()){
        db.close();
        return true;
    } else {
        return false;
    }
}

void DbManager::dbSelectAll(QString tableName){
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    model->select();
}

 QSqlTableModel* DbManager::getTableModel()
 {
     return model;
 }
