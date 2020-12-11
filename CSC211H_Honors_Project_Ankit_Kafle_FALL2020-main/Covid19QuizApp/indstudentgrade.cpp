#include "indstudentgrade.h"
#include "ui_indstudentgrade.h"

IndstudentGrade::IndstudentGrade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IndstudentGrade)
{
    ui->setupUi(this);
   // databaseConfig();
}

IndstudentGrade::~IndstudentGrade()
{
    delete ui;
}

void IndstudentGrade::on_buttonBox_accepted()
{
    this->close();
}

void IndstudentGrade::setStuName(QString name)
{
    studentUserName = name;
}

void IndstudentGrade::databaseConfig()
{

    QSqlDatabase mdb_getgrade = QSqlDatabase::database();
    mdb_getgrade.open();
    QSqlQueryModel *presentData = new QSqlQueryModel;
    QSqlQuery qry(mdb_getgrade);
    qry.prepare("SELECT *FROM studentGradeReport WHERE stuUserName = '"+studentUserName+"'");
    qry.exec();
    presentData->setQuery(qry);
    ui->tableView->setModel(presentData);

}

