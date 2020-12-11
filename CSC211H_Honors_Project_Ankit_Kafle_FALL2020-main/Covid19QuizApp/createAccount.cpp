#include "createAccount.h"
#include "ui_createAccount.h"
//This class is used to crate the account for teacher and students if they dont already have an account

createAccount::createAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createAccount)
{
    ui->setupUi(this);
}

createAccount::~createAccount()
{
    delete ui;
}

void createAccount::on_createStudentAccountSIPushButton_clicked()
{
    QString stuName, stuEmail, stuUserName, stuPassword;
    stuName = ui->stuNameSIlineEdit->text();
    stuEmail =ui->stuEmailSIlineEdit->text();
    stuUserName= ui->stuUserNameSIlineEdit->text();
    stuPassword = ui->stuPasswordSILineEdit->text();

    bool checkNullData= false ;
    if(stuName ==NULL && stuEmail == NULL && stuUserName == NULL && stuPassword==NULL)
    {
        checkNullData = true;
        QMessageBox::information(this,"User Input","Please enter the value");
    }
// calling database for new connection
    QSqlDatabase mdb_CSA = QSqlDatabase::database();

//initializing the query for database access
    QSqlQuery qry(mdb_CSA);
    QSqlQuery qry_check(mdb_CSA);

    qry_check.prepare("SELECT userName, email FROM studentLoginInfo");

    qry.prepare("INSERT INTO studentLoginInfo ( studentName,email,userName, password)"
                "VALUES(:studentName,:email,:userName,:password);");
    qry.bindValue(":studentName",stuName );
    qry.bindValue(":email", stuEmail);
    qry.bindValue(":userName",stuUserName);
    qry.bindValue(":password", stuPassword);
    qry_check.exec();
    bool duplicate = false;

    // checking the username and email for duplication
    while(qry_check.next() && !checkNullData)
    {
        QString name = qry_check.value(0).toString();
        QString email = qry_check.value(1).toString();
        if(name == stuUserName || email == stuEmail)
        {
            QMessageBox::information(this,"Login Info","Email or Username not Available");
            duplicate = true;
            ui->stuNameSIlineEdit->clear();
            ui->stuEmailSIlineEdit->clear();
            ui->stuUserNameSIlineEdit->clear();
            ui->stuPasswordSILineEdit->clear();
        }
    }
    if(!duplicate && !checkNullData)
    {
       qry.exec();
       this->close();
    }
}


void createAccount::on_createTeacherAccountSIPushButton_clicked()
{

    QString teacherName, teacherEmail, teacherUserName, teacherPassword;
// getting the value form userinput using ui element
    teacherName = ui->teacherNameSIlineEdit->text();
    teacherEmail =ui->teacherEmailSIlineEdit->text();
    teacherUserName= ui->teacherUserNameSIlineEdit->text();
    teacherPassword = ui->teacherPasswordSILineEdit->text();

    bool checkNullData= false ;
    if(teacherName ==NULL && teacherEmail == NULL && teacherUserName == NULL && teacherPassword==NULL)
    {
        checkNullData = true;
        QMessageBox::information(this,"User Input","Please enter the value");
    }

    QSqlDatabase mdb_CTA = QSqlDatabase::database();

    QSqlQuery qry(mdb_CTA);
    QSqlQuery qry_check(mdb_CTA);
// writting username and password in the database

    qry_check.prepare("SELECT userName, email FROM teacherLoginInfo");
    qry.prepare("INSERT INTO teacherLoginInfo ( teacherName,email,userName, password)"
                "VALUES(:teacherName,:email,:userName,:password)");

    qry.bindValue(":teacherName",teacherName );
    qry.bindValue(":email", teacherEmail);
    qry.bindValue(":userName",teacherUserName);
    qry.bindValue(":password", teacherPassword);

    qry_check.exec();
    bool duplicate = false;
    while(qry_check.next() && !checkNullData)
    {
        QString name = qry_check.value(0).toString();
        QString email = qry_check.value(1).toString();
        if(name == teacherUserName ||  email == teacherEmail)
        {
            QMessageBox::information(this,"Login Inof","Email or Username not Available");
            duplicate = true;
            ui->teacherNameSIlineEdit->clear();
            ui->teacherEmailSIlineEdit->clear();
            ui->teacherUserNameSIlineEdit->clear();
            ui->teacherPasswordSILineEdit->clear();
        }
    }
    if(!duplicate && !checkNullData)
    {
        qry.exec();
        this->close();
    }
}


