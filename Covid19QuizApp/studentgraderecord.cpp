#include "studentgraderecord.h"
#include "ui_studentgraderecord.h"

studentGradeRecord::studentGradeRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentGradeRecord)
{
    ui->setupUi(this);
}

studentGradeRecord::~studentGradeRecord()
{
    delete ui;
}

void studentGradeRecord::on_buttonBox_accepted()
{
    this->close();
}
