
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialize the database connection, making it defult connection
    //QT stores database connection as static variable, so all the classes in
    //The project will inherit the database connection
    //Form next time we only need to call for new connection, but not add new database
    QSqlDatabase mdb = QSqlDatabase::addDatabase("QSQLITE");
    mdb.setDatabaseName("C:/Users/Ankit/Desktop/covid19QuizApp.db");

}

MainWindow::~MainWindow()
{
    delete ui;
}

// student login funciton
void MainWindow::on_stuLoginPushButton_clicked()
{
    QSqlDatabase mdb_slogin = QSqlDatabase::database();
    bool mdbOpen = mdb_slogin.open();
    mdb_slogin.open();
    if(!mdbOpen)
    {
        QMessageBox::warning(this, "Connection","Connection to DataBase failed");
    }

    QString userName , password;
    QSqlQuery query(mdb_slogin);

    userName = ui->stuUserNameSILineEdit->text();
    password = ui->stuPasswordSILineEdit->text();
    query.exec("SELECT userName, password FROM studentLoginInfo");
    bool passwordMatch = false;

//comparing the value with database to check username and password
    while (query.next()) {
        QString name = query.value(0).toString();
        QString pass = query.value(1).toString();

        if(userName == name && password ==pass && password != NULL && userName != NULL)
        {
            passwordMatch = true;

            //this->close();

            studentChoiceUI = new studentChoice;
            studentChoiceUI->showNormal();
            studentChoiceUI->setModal(true);
            studentChoiceUI->setStuUserName(userName);
            studentChoiceUI->exec();
        }
    }

    if(!passwordMatch)
    {
        QMessageBox::warning(this, "Password","Password or UserName not match");
    }
}

void MainWindow::on_actionclose_triggered()
{
    QApplication::quit();
}

// teacher login fucntion
void MainWindow::on_teacherLoginPushButton_clicked()
{
//calling the database connection
    QSqlDatabase mdb_tlogin = QSqlDatabase::database();
    mdb_tlogin.open();
    if(!mdb_tlogin.open())
    {
        QMessageBox::warning(this, "Connection","Connection to DataBase failed");
        return;
    }

    QString userName , password;
    QSqlQuery query(mdb_tlogin);
    userName = ui->teacherUserNameLineEdit->text();
    password = ui->teacherPasswordLineEdit->text();
    query.exec("SELECT userName, password FROM teacherLoginInfo");
    bool passwordMatch = false;

    while (query.next()) {
        QString name = query.value(0).toString();
        QString pass = query.value(1).toString();
        if(userName == name && password ==pass && password != NULL && userName != NULL)
        {
            //calling the teacher class if user name and password mathches
            passwordMatch = true;
           // this->close();
            teachUI = new teacherClass();
            teachUI->setModal(true);
            teachUI->setTeacherUserName(userName);
            teachUI->exec();
        }
    }

    if(!passwordMatch)
    {
        QMessageBox::warning(this, "Password","Password or UserName not match");
    }

}


void MainWindow::on_createNewAccountPushButton_clicked()
{
    //call create accountCreate class if user chooses

    accountCreateUI = new createAccount(this);
    accountCreateUI->setModal(true);
    accountCreateUI->exec();
}
