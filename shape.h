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

    Q_PROPERTY(int xCoord READ xCoord WRITE setXCoord NOTIFY xCoordChanged)
    Q_PROPERTY(int yCoord READ yCoord WRITE setYCoord NOTIFY yCoordChanged)
    Q_PROPERTY(int type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(int direction READ direction WRITE setDirection NOTIFY directionChanged)
    Q_PROPERTY(int hp READ hp WRITE setHp NOTIFY hpChanged)

public:
    explicit Shape(QObject *parent = 0);

    Q_INVOKABLE void setYCoord(const int &yCoord);
    Q_INVOKABLE void setXCoord(const int &xCoord);
    void setType(int type);
    void setSource(const QString &source);
    void setDirection(int direction);
    void setHp(int hp);

    int yCoord() const;
    int xCoord() const;
    int hp() const;
    int type() const;
    QString source() const;
    int direction() const;

private:

    int m_type;
    int m_xCoord;
    int m_yCoord;
    QString m_source;
    int m_direction;
    int m_hp;

signals:
    void xCoordChanged(int x);
    void yCoordChanged(int y);
    void typeChanged(int type);
    void sourceChanged(QString src);
    void directionChanged(int dir);
    void hpChanged(int health);
public slots:
};

#endif // SHAPE_H
