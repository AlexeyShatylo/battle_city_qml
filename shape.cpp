#include "shape.h"

Shape::Shape(QObject *parent) : QObject(parent)
{
createMap();
}

qreal Shape::yCoord() const
{
    return m_yCoord;
}

qreal Shape::xCoord() const
{
    return m_xCoord;
}

QString Shape::source() const
{
    return m_source;
}

int Shape::type() const
{
    return m_type;
}

int Shape::direction() const
{
    return m_direction;
}

int Shape::hp() const
{
    return m_hp;
}

void Shape::setHp(int hp)
{
    m_hp = hp;
}

void Shape::setYCoord(const qreal &yCoord)
{
    if (m_yCoord != yCoord) {
        m_yCoord = yCoord;
        emit yCoordChanged(yCoord);
    }
}

void Shape::setDirection(int direction)
{
    if (m_direction != direction) {

        m_direction = direction;
        emit directionChanged(direction);
    }
}

void Shape::setSource(const QString &source)
{
    if (m_source != source) {
        m_source = source;
        emit sourceChanged(source);
    }
}

void Shape::setType(int type)
{
    m_type = type;
}

void Shape::setXCoord(const qreal &xCoord)
{
    if (m_xCoord != xCoord) {
        m_xCoord = xCoord;
        emit xCoordChanged(xCoord);
    }
}
