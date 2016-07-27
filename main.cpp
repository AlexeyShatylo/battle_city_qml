#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlComponent>
#include "shape.h"
#include "game.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine appEngine;

    qmlRegisterType<Shape>("shape", 1, 0, "MyObject");
    qmlRegisterType<Game>("shape", 1, 0, "MyGame");
    appEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
