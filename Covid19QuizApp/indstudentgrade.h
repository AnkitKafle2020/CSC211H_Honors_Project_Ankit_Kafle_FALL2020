#ifndef INDSTUDENTGRADE_H
#define INDSTUDENTGRADE_H

#include <QDialog>
#include<QSql>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlError>
//#include<QtDebug>
#include<QMessageBox>

namespace Ui {
class IndstudentGrade;
}

class IndstudentGrade : public QDialog
{
    Q_OBJECT

public:
    explicit IndstudentGrade(QWidget *parent = nullptr);
    ~IndstudentGrade();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::IndstudentGrade *ui;
public:
    void databaseConfig();
    void setStuName(QString);
private:
    QString studentUserName;

};

#endif // INDSTUDENTGRADE_H
