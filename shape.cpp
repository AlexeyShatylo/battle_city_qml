#include "shape.h"

Shape::Shape(QObject *parent) : QObject(parent)
{
    m_type = 0;
    m_direction = 0;
    m_source = "";
    m_hp = 0;
    m_xCoord = 0;
    m_yCoord = 0;
    m_height = 0;
    m_width = 0;
//    m_shapeRect.setRect(m_xCoord,m_yCoord,m_width,m_height);
//    connect(this,SIGNAL(xCoordChanged(int)), this, SLOT(setShapeRect(QRect tmp(m_xCoord,m_yCoord,m_width,m_height))));
//    connect(this,SIGNAL(yCoordChanged(int)), this, Shape::setShapeRect(QRect(m_xCoord,m_yCoord,m_width,m_height)));
//    connect(this,SIGNAL(heightChanged(int)), this, Shape::setShapeRect(QRect(m_xCoord,m_yCoord,m_width,m_height)));
//    connect(this,SIGNAL(widthChanged(int)),  this, Shape::setShapeRect(QRect(m_xCoord,m_yCoord,m_width,m_height)));

}

int Shape::yCoord() const
{
    return m_yCoord;
}

int Shape::xCoord() const
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

bool Shape::traversable() const
{
    return m_traversable;
}

void Shape::setTraversable(bool traversable)
{
    if (traversable != m_traversable){
        m_traversable = traversable;
        emit traversableChanged(traversable);
    }
}

void Shape::setShapeRect(const QRect &shapeRect)
{//setRect(m_xCoord,m_yCoord,m_width,m_height);
    if (m_shapeRect != shapeRect) {
        m_shapeRect = shapeRect;
        emit shapeRectChanged();
    }
}

int Shape::shapeRectCenterX()
{
    return shapeRect().center().x();
}

int Shape::shapeRectCenterY()
{
    return shapeRect().center().y();
}

int Shape::width() const
{
    return m_width;
}

void Shape::setWidth(int width)
{
    if (m_width != width) {
        m_width = width;
        setShapeRect(QRect(m_xCoord,m_yCoord,m_width,m_height));
        emit widthChanged(width);
    }
}

int Shape::height() const
{
    return m_height;
}

void Shape::setHeight(int height)
{
    if (m_height != height) {
        m_height = height;
        setShapeRect(QRect(m_xCoord,m_yCoord,m_width,m_height));
        emit heightChanged(height);
    }
}

QRect Shape::shapeRect() const
{
    return m_shapeRect;
}

int Shape::hp() const
{
    return m_hp;
}

void Shape::setHp(int hp)
{
    m_hp = hp;
}

void Shape::setYCoord(const int &yCoord)
{
    if (m_yCoord != yCoord) {
        m_yCoord = yCoord;
        setShapeRect(QRect(m_xCoord,m_yCoord,m_width,m_height));
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

void Shape::setXCoord(const int &xCoord)
{
    if (m_xCoord != xCoord) {
        m_xCoord = xCoord;
        setShapeRect(QRect(m_xCoord,m_yCoord,m_width,m_height));
        emit xCoordChanged(xCoord);
    }
}
