#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "calc.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Calc>("CalcClass", 1, 0, "Calculator");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
