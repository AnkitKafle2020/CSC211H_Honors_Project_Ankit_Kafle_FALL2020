#include "setquiz.h"
#include "ui_setquiz.h"

//this class is used to set the quiz by the teacher

setQuiz::setQuiz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setQuiz)
{
    ui->setupUi(this); 
}


setQuiz::~setQuiz()
{
    delete ui;
}
//recording the quiz name and teacherName on database
void setQuiz::on_pushButton_clicked()
{

    QSqlDatabase mdb_setQuiz = QSqlDatabase::database();
    mdb_setQuiz.open();
    QSqlQuery qry(mdb_setQuiz);

    qry.prepare("INSERT INTO availableQuiz (teacherUserName,quizName)"
                "VALUES(:teacherUserName,:quizName);");

    qry.bindValue(":teacherUserName", teaceherUserName);
    qry.bindValue(":quizName",tableName);
    qry.exec();

    this->close();
}


void setQuiz::setTableName(QString name)
{
    tableName = name;
}
// set teacher name
void setQuiz::setTeacherUserName(QString name)
{
    teaceherUserName = name;
}
// the following function is used to record the quesiton form the ui
void setQuiz::on_pushButton_101_clicked()
{
    QString tquestion, tdbname;
    tdbname = tableName;

    tquestion = ui->plainTextEdit101->toPlainText();
    QSqlDatabase mdb_setAns1 = QSqlDatabase::database();
    QSqlQuery qry(mdb_setAns1);
    QString question,tanswer ="";
    if(ui->checkBox_111->checkState())
    {
        tanswer = "a";
    }
    if(ui->checkBox_112->checkState())
    {
        tanswer = "b";
    }
    if(ui->checkBox_113->checkState())
    {
        tanswer = "c";
    }
    if(ui->checkBox_114->checkState())
    {
        tanswer = "d";
    }
    if(mdb_setAns1.open())
    {
        //qDebug()<<tanswer;
        //qDebug()<<tquestion;
        //qDebug()<<tdbname;
        qry.prepare("INSERT INTO "+tdbname+"(question,answer)"
                    "VALUES(:question,:answer);");

       qry.bindValue(":question",tquestion);
       qry.bindValue(":answer",tanswer);
       qry.exec();
    }
    else
    {
        QMessageBox::information(this,"User Input","Database not open");
    }

    ui->pushButton_101->setStyleSheet("QPushButton{ background-color: green }");
}


void setQuiz::on_pushButton102_clicked()
{

    QString tquestion, tdbname;
    tdbname = tableName;

    tquestion = ui->plainTextEdit102->toPlainText();
    QSqlDatabase mdb_setAns2 = QSqlDatabase::database();
    mdb_setAns2.open();
    QSqlQuery qry(mdb_setAns2);
    QString question,tanswer ="";
    if(ui->checkBox_121->checkState())
    {
        tanswer = "a";
    }
    if(ui->checkBox_122->checkState())
    {
        tanswer = "b";
    }
    if(ui->checkBox_123->checkState())
    {
        tanswer = "c";
    }
    if(ui->checkBox_124->checkState())
    {
        tanswer = "d";
    }
    if(mdb_setAns2.open())
    {
       // qDebug()<<tanswer;
        //qDebug()<<tquestion;
        //qDebug()<<tdbname;
        qry.prepare("INSERT INTO "+tdbname+"(question,answer)"
                    "VALUES(:question,:answer);");

       qry.bindValue(":question",tquestion);
       qry.bindValue(":answer",tanswer);
       qry.exec();
    }
    else
    {
        QMessageBox::information(this,"User Input","Database not open");
    }


  ui->pushButton102->setStyleSheet("QPushButton{ background-color: green }");
}

void setQuiz::on_pushButton103_clicked()
{
    QString tquestion, tdbname;
    tdbname = tableName;

    tquestion = ui->plainTextEdit_103->toPlainText();
    QSqlDatabase mdb_setAns3 = QSqlDatabase::database();

    mdb_setAns3.open();
    QSqlQuery qry(mdb_setAns3);
    QString question,tanswer ="";
    if(ui->checkBox_131->checkState())
    {
        tanswer = "a";
    }
    if(ui->checkBox_132->checkState())
    {
        tanswer = "b";
    }
    if(ui->checkBox_133->checkState())
    {
        tanswer = "c";
    }
    if(ui->checkBox_134->checkState())
    {
        tanswer = "d";
    }
    if(mdb_setAns3.open())
    {
        //qDebug()<<tanswer;
        //qDebug()<<tquestion;
        //qDebug()<<tdbname;
        qry.prepare("INSERT INTO "+tdbname+"(question,answer)"
                    "VALUES(:question,:answer);");

       qry.bindValue(":question",tquestion);
       qry.bindValue(":answer",tanswer);
       qry.exec();
    }
    else
    {
        QMessageBox::information(this,"User Input","Database not open");
    }

    ui->pushButton103->setStyleSheet("QPushButton{ background-color: green }");
}

void setQuiz::on_pushButton104_clicked()
{
    QString tquestion, tdbname;
    tdbname = tableName;

    tquestion = ui->plainTextEdit_104->toPlainText();
    QSqlDatabase mdb_setAns4 = QSqlDatabase::database();
    mdb_setAns4.open();
    QSqlQuery qry(mdb_setAns4);
    QString question,tanswer ="";
    if(ui->checkBox_141->checkState())
    {
        tanswer = "a";
    }
    if(ui->checkBox_142->checkState())
    {
        tanswer = "b";
    }
    if(ui->checkBox_143->checkState())
    {
        tanswer = "c";
    }
    if(ui->checkBox_144->checkState())
    {
        tanswer = "d";
    }
    if(mdb_setAns4.open())
    {
       // qDebug()<<tanswer;
        //qDebug()<<tquestion;
        //qDebug()<<tdbname;
        qry.prepare("INSERT INTO "+tdbname+"(question,answer)"
                    "VALUES(:question,:answer);");

       qry.bindValue(":question",tquestion);
       qry.bindValue(":answer",tanswer);
       qry.exec();
    }
    else
    {
        QMessageBox::information(this,"User Input","Database not open");
    }
  ui->pushButton104->setStyleSheet("QPushButton{ background-color: green }");
}

void setQuiz::on_pushButton105_clicked()
{
    QString tquestion, tdbname;
    tdbname = tableName;

    tquestion = ui->plainTextEdit_105->toPlainText();

    QSqlDatabase mdb_setAns5 = QSqlDatabase::database();
    mdb_setAns5.open();
    QSqlQuery qry(mdb_setAns5);
    QString question,tanswer ="";
    if(ui->checkBox_151->checkState())
    {
        tanswer = "a";
    }
    if(ui->checkBox_152->checkState())
    {
        tanswer = "b";
    }
    if(ui->checkBox_153->checkState())
    {
        tanswer = "c";
    }
    if(ui->checkBox_154->checkState())
    {
        tanswer = "d";
    }
    if(mdb_setAns5.open())
    {
       // qDebug()<<tanswer;
        //qDebug()<<tquestion;
        //qDebug()<<tdbname;
        qry.prepare("INSERT INTO "+tdbname+"(question,answer)"
                    "VALUES(:question,:answer);");

       qry.bindValue(":question",tquestion);
       qry.bindValue(":answer",tanswer);
       qry.exec();
    }
    else
    {
        QMessageBox::information(this,"User Input","Database not open");
    }
     ui->pushButton105->setStyleSheet("QPushButton{ background-color: green }");
}


void setQuiz::on_pushButton106_clicked()
{
    //ui->pushButton106->setStyleSheet("QPushButton{ background-color: green }");
    QString tquestion, tdbname;
    tdbname = tableName;

    tquestion = ui->plainTextEdit_106->toPlainText();

    QSqlDatabase mdb_setAns6 = QSqlDatabase::database();
    mdb_setAns6.open();
    QSqlQuery qry(mdb_setAns6);
    QString question="",tanswer ="";
    if(ui->checkBox_161->checkState())
    {
        tanswer = "a";
    }
    if(ui->checkBox_162->checkState())
    {
        tanswer = "b";
    }
    if(ui->checkBox_163->checkState())
    {
        tanswer = "c";
    }
    if(ui->checkBox_164->checkState())
    {
        tanswer = "d";
    }
    if(mdb_setAns6.open())
    {
        //qDebug()<<tanswer;
        //qDebug()<<tquestion;
        //qDebug()<<tdbname;
        qry.prepare("INSERT INTO "+tdbname+"(question,answer)"
                    "VALUES(:question,:answer);");

       qry.bindValue(":question",tquestion);
       qry.bindValue(":answer",tanswer);
       qry.exec();
    }
    else
    {
        QMessageBox::information(this,"User Input","Database not open");
    }

     ui->pushButton106->setStyleSheet("QPushButton{ background-color: green }");
}


void setQuiz::on_pushButton107_clicked()
{
    QString tquestion, tdbname;
    tdbname = tableName;

    tquestion = ui->plainTextEdit_107->toPlainText();
    QSqlDatabase mdb_setAns7 = QSqlDatabase::database();
    mdb_setAns7.open();
    QSqlQuery qry(mdb_setAns7);
    QString question,tanswer ="";
    if(ui->checkBox_171->checkState())
    {
        tanswer = "a";
    }
    if(ui->checkBox_172->checkState())
    {
        tanswer = "b";
    }
    if(ui->checkBox_173->checkState())
    {
        tanswer = "c";
    }
    if(ui->checkBox_174->checkState())
    {
        tanswer = "d";
    }
    if(mdb_setAns7.open())
    {
        //qDebug()<<tanswer;
        //qDebug()<<tquestion;
        //qDebug()<<tdbname;
        qry.prepare("INSERT INTO "+tdbname+"(question,answer)"
                    "VALUES(:question,:answer);");

       qry.bindValue(":question",tquestion);
       qry.bindValue(":answer",tanswer);
       qry.exec();
    }
    else
    {
        QMessageBox::information(this,"User Input","Database not open");
    }
     ui->pushButton107->setStyleSheet("QPushButton{ background-color: green }");
}
void setQuiz::on_pushButton108_clicked()
{
    QString tquestion, tdbname;
    tdbname = tableName;

    tquestion = ui->plainTextEdit_108->toPlainText();
    QSqlDatabase mdb_setAns8 = QSqlDatabase::database();
    mdb_setAns8.open();
    QSqlQuery qry(mdb_setAns8);
    QString question,tanswer ="";
    if(ui->checkBox_181->checkState())
    {
        tanswer = "a";
    }
    if(ui->checkBox_182->checkState())
    {
        tanswer = "b";
    }
    if(ui->checkBox_183->checkState())
    {
        tanswer = "c";
    }
    if(ui->checkBox_184->checkState())
    {
        tanswer = "d";
    }
    if(mdb_setAns8.open())
    {
        //qDebug()<<tanswer;
        //qDebug()<<tquestion;
        //qDebug()<<tdbname;
        qry.prepare("INSERT INTO "+tdbname+"(question,answer)"
                    "VALUES(:question,:answer);");

       qry.bindValue(":question",tquestion);
       qry.bindValue(":answer",tanswer);
       qry.exec();
    }
    else
    {
        QMessageBox::information(this,"User Input","Database not open");
    }
     ui->pushButton108->setStyleSheet("QPushButton{ background-color: green }");
}
void setQuiz::on_pushButton109_clicked()
{
    QString tquestion, tdbname;
    tdbname = tableName;

    tquestion = ui->plainTextEdit_109->toPlainText();
    QSqlDatabase mdb_setAns8 = QSqlDatabase::database();
    mdb_setAns8.open();
    QSqlQuery qry(mdb_setAns8);
    QString question,tanswer ="";
    if(ui->checkBox_191->checkState())
    {
        tanswer = "a";
    }
    if(ui->checkBox_192->checkState())
    {
        tanswer = "b";
    }
    if(ui->checkBox_123->checkState())
    {
        tanswer = "c";
    }
    if(ui->checkBox_194->checkState())
    {
        tanswer = "d";
    }
    if(mdb_setAns8.open())
    {
        //qDebug()<<tanswer;
        //qDebug()<<tquestion;
        //qDebug()<<tdbname;
        qry.prepare("INSERT INTO "+tdbname+"(question,answer)"
                    "VALUES(:question,:answer);");

       qry.bindValue(":question",tquestion);
       qry.bindValue(":answer",tanswer);
       qry.exec();
    }
    else
    {
        QMessageBox::information(this,"User Input","Database not open");
    }
     ui->pushButton109->setStyleSheet("QPushButton{ background-color: green }");
}


void setQuiz::on_pushButton110_clicked()
{
    QString tquestion, tdbname;
    tdbname = tableName;

    tquestion = ui->plainTextEdit_110->toPlainText();
    QSqlDatabase mdb_setAns10 = QSqlDatabase::database();
    mdb_setAns10.open();
    QSqlQuery qry(mdb_setAns10);
    QString question,tanswer ="";
    if(ui->checkBox_101->checkState())
    {
        tanswer = "a";
    }
    if(ui->checkBox_102->checkState())
    {
        tanswer = "b";
    }
    if(ui->checkBox_133->checkState())
    {
        tanswer = "c";
    }
    if(ui->checkBox_104->checkState())
    {
        tanswer = "d";
    }
    if(mdb_setAns10.open())
    {
        //qDebug()<<tanswer;
        //qDebug()<<tquestion;
        //qDebug()<<tdbname;
        qry.prepare("INSERT INTO "+tdbname+"(question,answer)"
                    "VALUES(:question,:answer);");

       qry.bindValue(":question",tquestion);
       qry.bindValue(":answer",tanswer);
       qry.exec();
    }
    else
    {
        QMessageBox::information(this,"User Input","Database not open");
    }
     ui->pushButton110->setStyleSheet("QPushButton{ background-color: green }");
}
