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

void testSelector::databaseConfig()
{
    QSqlDatabase mdbsec = QSqlDatabase::database();//("QSQLITE", "tenth");
    //mdbsec.setDatabaseName("C:/Users/Ankit/Desktop/covid19QuizApp.db");
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
    qry_check.prepare("SELECT  quizName FROM availableQuiz");
    qry_check.exec();
    while(qry_check.next())
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
