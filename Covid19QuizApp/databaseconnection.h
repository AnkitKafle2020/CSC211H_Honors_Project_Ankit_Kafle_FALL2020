#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H
#include<QSql>
#include <QSqlQuery>
#include<QSqlError>

class databaseConnection
{
public:
    databaseConnection();
    void connectToDatabase();
};

#endif // DATABASECONNECTION_H
