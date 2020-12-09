#ifndef TEACHERCLASS_H
#define TEACHERCLASS_H

#include <QDialog>
#include<QSql>
#include <QSqlQuery>
#include<QSqlError>
//#include<QtDebug>
#include<QMessageBox>
#include"setquiz.h"
#include<QSqlQueryModel>

namespace Ui {
class teacherClass;
}

class teacherClass : public QDialog
{
    Q_OBJECT

public:
    explicit teacherClass(QWidget *parent = nullptr);
    ~teacherClass();

private slots:
    void on_pushButton_clicked();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::teacherClass *ui;

private:
    setQuiz *setQuizUI;
    QString teacherUN;

public:
    void setTeacherUserName(QString);
};

#endif // TEACHERCLASS_H
