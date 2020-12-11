#include "databaseconnection.h"


databaseConnection::databaseConnection()
{

}

void databaseConnection::connectToDatabase()
{
    //Initialize the database connection, making it defult connection
    //QT stores database connection as static variable, so all the classes in
    //The project will inherit the database connection
    //Form next time we only need to call for new connection, but not add new database
    QSqlDatabase mdb = QSqlDatabase::addDatabase("QSQLITE");
    mdb.setDatabaseName("C:/Users/Ankit/Desktop/covid19QuizApp.db");
}
