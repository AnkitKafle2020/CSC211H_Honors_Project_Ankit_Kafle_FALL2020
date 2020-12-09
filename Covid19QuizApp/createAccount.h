#ifndef CREATEACCOUNT_H
#define CREATEACCOUNT_H

#include <QDialog>
#include<QSql>
#include <QSqlQuery>
#include<QSqlError>
//#include<QtDebug>
#include<QMessageBox>

namespace Ui {
class createAccount;
}

class createAccount : public QDialog
{
    Q_OBJECT

public:
    explicit createAccount(QWidget *parent = nullptr);
    ~createAccount();

private slots:


    void on_createStudentAccountSIPushButton_clicked();

    void on_createTeacherAccountSIPushButton_clicked();


private:
    Ui::createAccount *ui;
};

#endif // CREATEACCOUNT_H
