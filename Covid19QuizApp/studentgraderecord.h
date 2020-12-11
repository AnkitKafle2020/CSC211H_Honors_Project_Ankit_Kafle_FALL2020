#ifndef STUDENTGRADERECORD_H
#define STUDENTGRADERECORD_H

#include <QDialog>

namespace Ui {
class studentGradeRecord;
}

class studentGradeRecord : public QDialog
{
    Q_OBJECT

public:
    explicit studentGradeRecord(QWidget *parent = nullptr);
    ~studentGradeRecord();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::studentGradeRecord *ui;
};

#endif // STUDENTGRADERECORD_H
