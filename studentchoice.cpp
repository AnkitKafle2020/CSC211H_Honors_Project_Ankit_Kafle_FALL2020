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
// initialize the testselextor class
void studentChoice::on_pushButtonTest_clicked()
{

    quizUI = new testSelector;
    quizUI->showNormal();
    quizUI->setModal(true);
    quizUI ->setStuUserName(stuUserName);

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
    gradeUI->setStuName(stuUserName);
    gradeUI->databaseConfig();
    gradeUI->showNormal();
    gradeUI->setModal(true);
    gradeUI->showMaximized();
    gradeUI->exec();
}
