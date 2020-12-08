#include "studentQuizclass.h"
#include "ui_studentQuizclass.h"

//This class shows quiz , record the user answer and point in the database

studentClass::studentClass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentClass)
{

    ui->setupUi(this);
    //setUP();

}
//setup the quiz by reading the question form the database
void studentClass::setUP()
{

    QSqlDatabase mdb_quizSetup = QSqlDatabase::database();
    mdb_quizSetup.open();
    QString nameofquiz =quizName;
    QSqlQuery qry_check(mdb_quizSetup);
    int i ;
    QString availableQuiz;
    qry_check.prepare("SELECT rowid, question FROM "+nameofquiz+"");
    qry_check.exec();
    //availableQuiz = qry_check.value(1).toString();
    i = qry_check.value(0).Int;
    int j=1;
    while(qry_check.next() && j <=10)
    {
        availableQuiz = qry_check.value(1).toString();
        if(j == 1)
        {
            ui->textBrowser1->setText(availableQuiz);
        }
        if(j == 2)
        {
            ui->textBrowser2->setText(availableQuiz);
        }
        if(j == 3)
        {
            ui->textBrowser3->setText(availableQuiz);
        }
        if(j == 4)
        {
            ui->textBrowser4->setText(availableQuiz);
        }
        if(j == 5)
        {
            ui->textBrowser5->setText(availableQuiz);
        }
        if(j ==6)
        {
            ui->textBrowser6->setText(availableQuiz);
        }
        if(j == 7)
        {
            ui->textBrowser7->setText(availableQuiz);
        }
        if(j == 8)
        {
            ui->textBrowser8->setText(availableQuiz);
        }
        if(j == 9)
        {
            ui->textBrowser9->setText(availableQuiz);
        }
        if(j == 10)
        {
            ui->textBrowser10->setText(availableQuiz);
        }
      //  qDebug()<<availableQuiz;
        j++;
        //ui->textBrowser1->setText(availableQuiz);
    }
    //mdb.close();
}


studentClass::~studentClass()
{
    delete ui;
}


void studentClass::setQuizName(QString name)
{
   quizName = name;
}


void studentClass::setStuUserName(QString name)
{
    stuUserName = name;
}


// record the user innput, compare with ans in database and give a point

void studentClass::on_pushButton_clicked()
{
    QString qName;
    QString stName;

    qName =  stuUserName;
    stName = quizName;

    QSqlDatabase mdb_recordGrade = QSqlDatabase::database(); //making new database connection to store student name and quiz name
    mdb_recordGrade.open();
    QSqlQuery qry_check(mdb_recordGrade);
    qry_check.prepare("INSERT INTO studentQuizLog(stuUserName,quizName)"
                "VALUES(:stuUserName,:quizName);");

    qry_check.bindValue(":stuUserName", qName);
    qry_check.bindValue(":quizName",stName);
    qry_check.exec();

    QSqlQuery qry(mdb_recordGrade); // record student ans and info
    qry.prepare("INSERT INTO stuTestGradeRecord(stuUserName,quizName, ans1, ans2, ans3,ans4,ans5,ans6,ans7,ans8,ans9,ans10)"
                "VALUES(:stuUserName,:quizName,:ans1,:ans2,:ans3,:ans4,:ans5,:ans6,:ans7,:ans8,:ans9,:ans10);");

    QString a1=" ",a2=" ",a3=" ",a4=" ",a5=" ",a6=" ",a7=" ",a8=" ",a9=" ",a10=" ";

    if(ui->checkBox_11->checkState())
    {
        a1="a";
    }
    if(ui->checkBox_12->checkState())
    {
        a1="b";
    }
    if(ui->checkBox_13->checkState())
    {
        a1 ="c";
    }
    if(ui->checkBox_14->checkState())
    {
        a1 ="d";
    }
    ///Question 2

    if(ui->checkBox_21->checkState())
    {
        a2="a";
    }
    if(ui->checkBox_22->checkState())
    {
        a2="b";
    }
    if(ui->checkBox_23->checkState())
    {
        a3 ="c";
    }
    if(ui->checkBox_24->checkState())
    {
        a4 ="d";
    }

    //Question3
    if(ui->checkBox_31->checkState())
    {
        a3="a";
    }
    if(ui->checkBox_32->checkState())
    {
        a3="b";
    }
    if(ui->checkBox_33->checkState())
    {
        a3 ="c";
    }
    if(ui->checkBox_34->checkState())
    {
        a3 ="d";
    }

    //Question 4

    if(ui->checkBox_41->checkState())
    {
        a4="a";
    }
    if(ui->checkBox_42->checkState())
    {
        a4="b";
    }
    if(ui->checkBox_43->checkState())
    {
        a1 ="c";
    }
    if(ui->checkBox_44->checkState())
    {
        a4 ="d";
    }
//Question 5

    if(ui->checkBox_51->checkState())
    {
        a5="a";
    }
    if(ui->checkBox_52->checkState())
    {
        a5="b";
    }
    if(ui->checkBox_53->checkState())
    {
        a5 ="c";
    }
    if(ui->checkBox_54->checkState())
    {
        a5 ="d";
    }

    //Question 6
    if(ui->checkBox_61->checkState())
    {
        a6="a";
    }
    if(ui->checkBox_62->checkState())
    {
        a6="b";
    }
    if(ui->checkBox_63->checkState())
    {
        a6 ="c";
    }
    if(ui->checkBox_64->checkState())
    {
        a6 ="d";
    }

    //Question 7
    if(ui->checkBox_71->checkState())
    {
        a7="a";
    }
    if(ui->checkBox_72->checkState())
    {
        a7="b";
    }
    if(ui->checkBox_73->checkState())
    {
        a7 ="c";
    }
    if(ui->checkBox_74->checkState())
    {
        a7 ="d";
    }

    //Question 8

    if(ui->checkBox_81->checkState())
    {
        a8="a";
    }
    if(ui->checkBox_82->checkState())
    {
        a8="b";
    }
    if(ui->checkBox_83->checkState())
    {
        a8 ="c";
    }
    if(ui->checkBox_84->checkState())
    {
        a8 ="d";
    }


//Question 9
    if(ui->checkBox_91->checkState())
    {
        a9="a";
    }
    if(ui->checkBox_92->checkState())
    {
        a9="b";
    }
    if(ui->checkBox_93->checkState())
    {
        a9 ="c";
    }
    if(ui->checkBox_94->checkState())
    {
        a9 ="d";
    }

    //Question 10

    if(ui->checkBox_101->checkState())
    {
        a10="a";
    }
    if(ui->checkBox_102->checkState())
    {
        a10="b";
    }
    if(ui->checkBox_103->checkState())
    {
        a10 ="c";
    }
    if(ui->checkBox_104->checkState())
    {
        a10 ="d";
    }

qry.bindValue(":stuUserName", qName);
qry.bindValue(":quizName",stName);
qry.bindValue(":ans1",a1);
qry.bindValue(":ans2",a2);
qry.bindValue(":ans3",a3);
qry.bindValue(":ans4",a4);
qry.bindValue(":ans5",a5);
qry.bindValue(":ans6",a6);
qry.bindValue(":ans7",a7);
qry.bindValue(":ans8",a8);
qry.bindValue(":ans9",a9);
qry.bindValue(":ans10",a10);
qry.exec();


QSqlQuery qry_openStuQuiz(mdb_recordGrade);
QSqlQuery qry_openQuizAnswer(mdb_recordGrade);
QSqlQuery qry_stuLogininfo(mdb_recordGrade);

QString name;
qry_stuLogininfo.prepare("SELECT studentName FROM studentLoginInfo WHERE userName ='"+stuUserName+"'");
qry_stuLogininfo.exec();
while(qry_stuLogininfo.next())
{
    name = qry_stuLogininfo.value(0).toString();
}
//record student answer
qry_openStuQuiz.prepare("SELECT quizName, ans1, ans2, ans3,ans4,ans5,ans6,ans7,ans8,ans9,ans10 FROM stuTestGradeRecord WHERE stuUserName='"+stuUserName+"' AND quizName = '"+quizName+"'");
qry_openStuQuiz.exec();

int point =0;
qry_openStuQuiz.first(); //compare stu ans wiht answer in database
    qry_openQuizAnswer.prepare("SELECT answer FROM "+quizName+"");
    qry_openQuizAnswer.exec();
    QString value;
    int i = 1;

    while(qry_openQuizAnswer.next())
    {
        //qDebug()<<qry_openQuizAnswer.value(0).toString();
        //qDebug()<<qry_openStuQuiz.value(i).toString();

        value = qry_openQuizAnswer.value(0).toString();
        if(value == qry_openStuQuiz.value(i).toString() &&  qry_openStuQuiz.value(i).toString()!= "")
        {
            point++;
        }
        i++;
    }
   // qDebug()<<point;

//write into database
QSqlQuery qry_openStuQuizForGrading;
qry_openStuQuizForGrading.prepare("INSERT INTO studentGradeReport(studentName,stuUserName,testName, points)"
                       "VALUES(:studentName,:stuUserName,:testName, :points);");

qry_openStuQuizForGrading.bindValue(":studentName", name);
qry_openStuQuizForGrading.bindValue(":stuUserName",stuUserName);
qry_openStuQuizForGrading.bindValue(":testName", quizName);
qry_openStuQuizForGrading.bindValue(":points", point);
qry_openStuQuizForGrading.exec();


this->close();
}
