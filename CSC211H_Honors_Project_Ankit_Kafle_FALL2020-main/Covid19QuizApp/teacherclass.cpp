#include "teacherclass.h"
#include "ui_teacherclass.h"

teacherClass::teacherClass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacherClass)
{
    ui->setupUi(this);
    //setQuizUI= new setQuiz(this);

}

teacherClass::~teacherClass()
{
    delete ui;
}

void teacherClass::setTeacherUserName(QString name)
{
   teacherUN = name;
}
//update the quiz name in database
void teacherClass::on_pushButton_clicked()
{

    QString quizTableName , quizTableNameCheck;
    bool nameNotAvailable = false;
    bool nullName= false;

    quizTableName = ui->quizNamelineEdit->text();
    if(quizTableName == NULL) //checking quiz for duplicate Name
    {
        nullName = true;
    }

    QSqlDatabase mdb_teacher = QSqlDatabase::database();
    //mdb_teacher.open();

    QSqlQuery qry_checkQuizName(mdb_teacher);

    qry_checkQuizName.prepare("SELECT quizName FROM availableQuiz");
    qry_checkQuizName.exec();
    while (qry_checkQuizName.next())
    {
       quizTableNameCheck = qry_checkQuizName.value(0).toString();
       //qDebug()<<quizTableNameCheck;

       if(quizTableNameCheck == quizTableName)
       {
          nameNotAvailable = true;
          break;
       }
    }


    if(!nameNotAvailable && !nullName)
    {

        QSqlQuery qry_createTable(mdb_teacher);

        qry_createTable.exec("CREATE TABLE "+quizTableName+"("
            "question TEXT,"
           "answer TEXT);");

        setQuizUI= new setQuiz;
        setQuizUI->setTableName(quizTableName);
        setQuizUI->setTeacherUserName(teacherUN);
        setQuizUI->setModal(true);
        setQuizUI->showMaximized();
        this->close();
        setQuizUI->exec();

    }
    else
    {
        QMessageBox::warning(this, "Quiz Name Info","Quiz Name Not Available \n Please use another name");
    }

}
//show the student and their grades for various test

void teacherClass::on_tabWidget_currentChanged(int index)
{
    index = 0;
    QSqlDatabase mdb_getgrade = QSqlDatabase::database();
    mdb_getgrade.open();
    QSqlQueryModel *presentData = new QSqlQueryModel;
    QSqlQuery qry(mdb_getgrade);
    qry.prepare("SELECT *FROM studentGradeReport");
    qry.exec();
    presentData->setQuery(qry);
    ui->tableView->setModel(presentData);
}


