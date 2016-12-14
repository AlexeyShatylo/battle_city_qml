#ifndef SHAPETYPEENUMQML_H
#define SHAPETYPEENUMQML_H

#include <QObject>

class ShapeTypeEnumQml : public QObject
{
    Q_OBJECT
public:
    enum ShapeType {Empty = 0, Brick, Concrete, Sand, Water, Ice, Forest, AiTank, Bullet, PlayerTank, Base};
    ShapeTypeEnumQml(QObject *parent = 0);
    ~ShapeTypeEnumQml(){}
    Q_ENUM(ShapeType)
signals:

public slots:
};

#endif // SHAPETYPEENUMQML_H
