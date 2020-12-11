#ifndef SETQUIZ_H
#define SETQUIZ_H

#include <QDialog>
#include<QSql>
#include <QSqlQuery>
#include<QSqlError>
//#include<QtDebug>
#include<QMessageBox>


namespace Ui {
class setQuiz;
}

class setQuiz :public QDialog
{
    Q_OBJECT

public:
    explicit setQuiz(QWidget *parent = nullptr);
    ~setQuiz();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_101_clicked();

    void on_pushButton102_clicked();

    void on_pushButton103_clicked();

    void on_pushButton104_clicked();

    void on_pushButton105_clicked();

    void on_pushButton106_clicked();

    void on_pushButton110_clicked();

    void on_pushButton107_clicked();

    void on_pushButton108_clicked();

    void on_pushButton109_clicked();

private:
    Ui::setQuiz *ui;

    QString tableName;
    QString teaceherUserName;
public:
   // void recordTestInDB(QString);
    void setTableName(QString);
    void setTeacherUserName(QString);
};

#endif // SETQUIZ_H
