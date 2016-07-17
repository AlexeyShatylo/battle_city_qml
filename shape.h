#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QList>
#include <QFile>
#include <QDebug>
enum ShapeType {Empty = 0, Brick, Concrete, Sand, Water, Ice, Forest, AiTank, Bullet, PlayerTank, Base};
enum Direction {Up = 0, Right, Down, Left};

class Shape : public QObject
{
    Q_OBJECT

    Q_PROPERTY(qreal xCoord READ xCoord WRITE setXCoord NOTIFY xCoordChanged)
    Q_PROPERTY(qreal yCoord READ yCoord WRITE setYCoord NOTIFY yCoordChanged)
    Q_PROPERTY(int type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(int direction READ direction WRITE setDirection NOTIFY directionChanged)
    Q_PROPERTY(int hp READ hp WRITE setHp NOTIFY hpChanged)

public:
    explicit Shape(QObject *parent = 0);

    void setYCoord(const qreal &yCoord);
    void setXCoord(const qreal &xCoord);
    void setType(int type);
    void setSource(const QString &source);
    void setDirection(int direction);
    void setHp(int hp);

    int type() const;
    qreal yCoord() const;
    qreal xCoord() const;
    QString source() const;
    int direction() const;

    void createMap();
    void createItem(qreal x, qreal y, int tp, QString src, int dir, int health);
    int hp() const;

private:

    int m_type;
    qreal m_xCoord;
    qreal m_yCoord;
    QString m_source;
    int m_direction;
    int m_hp;

signals:
    void xCoordChanged(qreal x);
    void yCoordChanged(qreal y);
    void typeChanged(int type);
    void sourceChanged(QString src);
    void directionChanged(int dir);
    void hpChanged(int health);
public slots:
};

#endif // SHAPE_H
