#ifndef STUDENTCHOICE_H
#define STUDENTCHOICE_H

#include <QDialog>
#include "testselector.h"
#include "indstudentgrade.h"

namespace Ui {
class studentChoice;
}

class studentChoice : public QDialog
{
    Q_OBJECT

public:
    explicit studentChoice(QWidget *parent = nullptr);
    ~studentChoice();

private slots:
    void on_pushButtonTest_clicked();

    void on_pushButtonGrade_clicked();

private:
    Ui::studentChoice *ui;

private:
      //studentClass *quizUI;
      testSelector *quizUI;
      IndstudentGrade *gradeUI;
      QString stuUserName;
public:
      void setStuUserName(QString);
};

#endif // STUDENTCHOICE_H
