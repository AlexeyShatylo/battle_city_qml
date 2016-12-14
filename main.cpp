#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlComponent>
#include "shape.h"
#include "game.h"
#include "directionenumqml.h"
#include "shapetypeenumqml.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine appEngine;

    qmlRegisterType<Shape>("shape", 1, 0, "MyObject");
    qmlRegisterType<Game>("shape", 1, 0, "MyGame");
    qmlRegisterType<DirectionEnumQml>("shape",1,0,"Direction");
    qmlRegisterType<ShapeTypeEnumQml>("shape",1,0,"ShapeType");
    appEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
