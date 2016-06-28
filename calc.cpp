#include "calc.h"

Calc::Calc()
{

}

Calc::~Calc()
{

}

QString Calc::getRes()
{
    return buffer;
}

void Calc::calcul(QString n1, QString n2, QString op)
{
    QFile num1f(FILE1);
    num1f.open(QIODevice::WriteOnly);
    QFile num2f(FILE2);
    num2f.open(QIODevice::WriteOnly);
    QFile operf(FILE3);
    operf.open(QIODevice::WriteOnly);
    QFile resf(FILE4);
    resf.open(QIODevice::ReadOnly);

    num1 = n1.toStdString().c_str();
    num2 = n2.toStdString().c_str();
    oper = op.toStdString().c_str();

    num1f.write(num1, strlen(num1));
    num2f.write(num2, strlen(num2));
    operf.write(oper, strlen(oper));

    num1f.close();
    num2f.close();
    operf.close();

    resf.read(res, sizeof(res));
    buffer = QString(res);
    memset(res, 0, strlen(res));
    resf.close();
}
