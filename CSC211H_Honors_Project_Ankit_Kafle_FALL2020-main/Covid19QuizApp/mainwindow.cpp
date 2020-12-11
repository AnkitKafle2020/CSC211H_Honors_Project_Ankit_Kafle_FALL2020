
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectToDatabase();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// student login funciton
void MainWindow::on_stuLoginPushButton_clicked()
{
    try {
        studentLogin();
    }  catch (QString message) {
        QMessageBox::warning(this, "Password",message);
    }
}

// teacher login fucntion
void MainWindow::on_teacherLoginPushButton_clicked()
{
    try {
        teacherLogin();
    }  catch (QString message) {
        QMessageBox::warning(this, "Password",message);
    }
}

void MainWindow::teacherLogin()
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
            QString errorMessage ="Password or UserName not match";

            while (query.next()) {
            QString name = query.value(0).toString();
            QString pass = query.value(1).toString();


            if(userName == name && password ==pass && password != NULL && userName != NULL)
            {
                //calling the teacher class if user name and password mathches
                 passwordMatch = true;
                ui->teacherUserNameLineEdit->clear();
                ui->teacherPasswordLineEdit->clear();
               // this->close();
                teachUI = new teacherClass();
                teachUI->setModal(true);
                teachUI->setTeacherUserName(userName);
                teachUI->exec();
            }
        }


        if(!passwordMatch)
        {
            throw errorMessage;
        }
}

void MainWindow::on_actionclose_triggered()
{
    QApplication::quit();
}

void MainWindow::studentLogin()
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

   std::vector<QString> studenUName;

//comparing the value with database to check username and password
QString errorMessage ="Password or UserName not match";

int i= 0;
    while (query.next()) {
        QString name = query.value(0).toString();
        studenUName.push_back(name);
        QString pass = query.value(1).toString();

        if(userName == studenUName[i] && password ==pass && password != NULL && userName != NULL)
        {
            passwordMatch = true;
            ui->stuUserNameSILineEdit->clear();
            ui->stuPasswordSILineEdit->clear();
            studentChoiceUI = new studentChoice;
            studentChoiceUI->showNormal();
            studentChoiceUI->setModal(true);
            studentChoiceUI->setStuUserName(userName);
            studentChoiceUI->exec();
        }
        /*
        if(userName == name && password ==pass && password != NULL && userName != NULL)
        {
            passwordMatch = true;
            ui->stuUserNameSILineEdit->clear();
            ui->stuPasswordSILineEdit->clear();
            studentChoiceUI = new studentChoice;
            studentChoiceUI->showNormal();
            studentChoiceUI->setModal(true);
            studentChoiceUI->setStuUserName(userName);
            studentChoiceUI->exec();
        }
        */



    i++;
    }

    if(!passwordMatch)
    {
        throw errorMessage;
    }
}

void MainWindow::on_createNewAccountPushButton_clicked()
{
    //call create accountCreate class if user chooses

    accountCreateUI = new createAccount(this);
    accountCreateUI->setModal(true);
    accountCreateUI->exec();
}
