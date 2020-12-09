#include "studentchoice.h"
#include "ui_studentchoice.h"

studentChoice::studentChoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentChoice)
{
    ui->setupUi(this);
}

studentChoice::~studentChoice()
{
    delete ui;
}
// initialize the test selextor class
void studentChoice::on_pushButtonTest_clicked()
{

    quizUI = new testSelector;
    quizUI->showNormal();
    quizUI->setModal(true);
    quizUI ->setStuUserName(stuUserName); //passing student userName to testSelector, to tack who selected the test

    quizUI->exec();

}
void studentChoice::setStuUserName(QString name)
{
    stuUserName = name;
}
// opening the widget to show the individual student score
void studentChoice::on_pushButtonGrade_clicked()
{
    gradeUI = new IndstudentGrade;
    gradeUI->setStuName(stuUserName); // passing the student UserName to IndStudentGrade call
    gradeUI->databaseConfig();        // so we can select appropriate value, as student username is primary key
    gradeUI->showNormal();
    gradeUI->setModal(true);
    gradeUI->showMaximized();
    gradeUI->exec();
}
