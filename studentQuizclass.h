#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H

#include <QDialog>
#include<QSql>
#include <QSqlQuery>
#include<QSqlError>
//#include<QtDebug>
#include<QMessageBox>
#include<QTextBrowser>

namespace Ui {
class studentClass;
}

class studentClass : public  QDialog
{
    Q_OBJECT

public:
    explicit studentClass(QWidget *parent = nullptr);
    ~studentClass();

private slots:

    void on_pushButton_clicked();

private:
    Ui::studentClass *ui;
    QString quizName;
    QString stuUserName;

public:
    void setUP();
    void setQuizName(QString);
    void setStuUserName(QString);
    //void recordGrade();
};

#endif // STUDENTCLASS_H
