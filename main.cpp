#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlComponent>
#include "shape.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine appEngine;
    qmlRegisterType<Shape>("shape", 1, 0, "MyObject");
    appEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
