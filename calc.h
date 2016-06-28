#ifndef CALC_H
#define CALC_H

#include <QObject>
#include <stdio.h>
#include <QFile>
//#include <QMessageBox>
#define FILE1 "/sys/class/calc/fnum"
#define FILE2 "/sys/class/calc/snum"
#define FILE3 "/sys/class/calc/operation"
#define FILE4 "/sys/class/calc/result"

class Calc : public QObject
{
    Q_OBJECT

public:
    Calc();
    ~Calc();
    char  res[5];
    const char *num1, *num2, *oper;
    QString buffer;

public slots:
    void calcul(QString n1, QString n2, QString op);
    Q_INVOKABLE QString getRes();

};

#endif // CALC_H
