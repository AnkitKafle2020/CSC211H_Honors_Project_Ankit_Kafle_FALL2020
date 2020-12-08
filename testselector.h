#ifndef TESTSELECTOR_H
#define TESTSELECTOR_H

#include <QDialog>
#include<QSql>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlError>
//#include<QtDebug>
#include<QMessageBox>

#include "studentQuizclass.h"


namespace Ui {
class testSelector;
}

class testSelector : public QDialog
{
    Q_OBJECT

public:
    explicit testSelector(QWidget *parent = nullptr);
    ~testSelector();

private:
    Ui::testSelector *ui;

private:
    QString testName="";
    QString stuUserName;
    studentClass *stuTestUI;
public:
    void databaseConfig();
    void setStuUserName(QString);

private slots:
    void on_pushButton_clicked();
};

#endif // TESTSELECTOR_H
