#ifndef CONNDB_H
#define CONNDB_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    if(!db.open()) return false;
    QSqlQuery query;
    query.exec("create table gait (id integer primary key autoincrement, name text, author text);");

    return true;
}

#endif // CONNDB_H
