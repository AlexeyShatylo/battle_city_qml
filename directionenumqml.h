#ifndef DIRECTIONENUMQML_H
#define DIRECTIONENUMQML_H

#include <QObject>

class DirectionEnumQml : public QObject
{
    Q_OBJECT
public:
    DirectionEnumQml(QObject *parent = 0);
    ~DirectionEnumQml(){}
    enum Direction {Up = 0, Right = 1, Down = 2, Left = 3};
    Q_ENUM(Direction)

private:
};

#endif // DIRECTIONENUMQML_H
