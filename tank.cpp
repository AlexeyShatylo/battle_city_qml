#include "tank.h"

tank::tank(QObject *parent) : QObject(parent)
{

}

qreal tank::yCoord() const
{
    return m_yCoord;
}

void tank::setYCoord(const qreal &yCoord)
{
    if(m_yCoord != yCoord) {
        m_yCoord = yCoord;
        emit yCoordChanged(yCoord);
    }
}

qreal tank::xCoord() const
{
    return m_xCoord;
}

int tank::type() const
{
    return m_type;
}

void tank::setType(int type)
{
    m_type = type;
}

void tank::setXCoord(const qreal &xCoord)
{
    if(m_xCoord != xCoord) {
        m_xCoord = xCoord;
        emit xCoordChanged(xCoord);
    }
}
