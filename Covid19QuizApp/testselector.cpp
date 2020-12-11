#include "testselector.h"
#include "ui_testselector.h"

testSelector::testSelector(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::testSelector)
{

    ui->setupUi(this);
    databaseConfig();
}
void testSelector::setStuUserName(QString name)
{
    stuUserName = name;
}

testSelector::~testSelector()
{
    delete ui;
}
// Configure database and show the available quiz to the students
void testSelector::databaseConfig()
{
    QSqlDatabase mdbsec = QSqlDatabase::database();
    mdbsec.open();
    QSqlQueryModel *presentData = new QSqlQueryModel;
    QSqlQuery qry(mdbsec);
    qry.prepare("SELECT *FROM availableQuiz");
    qry.exec();
    presentData->setQuery(qry);
    ui->tableView->setModel(presentData);
    mdbsec.close();

}
//initializes test for student

void testSelector::on_pushButton_clicked()
{


    QString name;
    name = ui->quizNamelineEdit->text();
    testName = name;
    bool check = false;

    QSqlDatabase mdbse = QSqlDatabase::database();
    QSqlQuery qry_check(mdbse);
    QSqlQuery qry_checkquiz(mdbse); // to check the duplication of test taken
    //mdbse.open();

    qry_checkquiz.prepare("SELECT stuUserName,quizName FROM stuTestGradeRecord");
    qry_checkquiz.exec();
     bool stop = false;
    while(qry_checkquiz.next())
    {
        QString stuName = qry_checkquiz.value(0).toString();
        QString quizName = qry_checkquiz.value(1).toString();

        if(stuName==stuUserName && quizName == name)
        {
            QMessageBox::information(this,"User Input","You have already taken this quiz");
            stop = true;
        }
    }

    qry_check.prepare("SELECT  quizName FROM availableQuiz");
    qry_check.exec();


    while(qry_check.next() && !stop)
    {
        QString teacherUserName = qry_check.value(0).toString();
        if(teacherUserName==name)
        {
            check = true;
            break;
        }

    }

    if(!check)
    {
        QMessageBox::information(this,"User Input","Quiz Not Available or Invalid Quiz name");
    }
    else
    {
        stuTestUI = new studentClass;
        stuTestUI->setModal(true);
        stuTestUI->showMaximized();
        stuTestUI->setQuizName(name);
        stuTestUI->setStuUserName(stuUserName);
        stuTestUI->setUP();
        stuTestUI->exec();
        this->close();
    }

}
