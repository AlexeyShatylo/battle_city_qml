#ifndef SHAPE_H
#define SHAPE_H

#include <QObject>
#include <QList>
#include <QFile>
#include <QDebug>
#include <QRect>
enum ShapeType {Empty = 0, Brick, Concrete, Sand, Water, Ice, Forest, AiTank, Bullet, PlayerTank, Base};
enum Direction {Up = 0, Right, Down, Left};

class Shape : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int xCoord READ xCoord WRITE setXCoord NOTIFY xCoordChanged)
    Q_PROPERTY(int yCoord READ yCoord WRITE setYCoord NOTIFY yCoordChanged)
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(int type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(int direction READ direction WRITE setDirection NOTIFY directionChanged)
    Q_PROPERTY(int hp READ hp WRITE setHp NOTIFY hpChanged)
    Q_PROPERTY(bool traversable READ traversable WRITE setTraversable NOTIFY traversableChanged)
    Q_PROPERTY(QRect shapeRect READ shapeRect WRITE setShapeRect NOTIFY shapeRectChanged)
    Q_PROPERTY(NOTIFY shooting)
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

    bool traversable() const;
    void setTraversable(bool traversable);

    QRect shapeRect() const;

    int width() const;
    void setWidth(int width);

    int height() const;
    void setHeight(int height);
    Q_INVOKABLE int shapeRectCenterX();
    Q_INVOKABLE int shapeRectCenterY();
    void setShapeRect(const QRect &shapeRect);

private:

    int m_xCoord;
    int m_yCoord;
    int m_width;
    int m_height;

    int m_type;
    QString m_source;
    int m_direction;
    int m_hp;
    bool m_traversable;

    QRect m_shapeRect;

signals:
    void xCoordChanged(int x);
    void yCoordChanged(int y);
    void widthChanged(int w);
    void heightChanged(int h);
    void shapeRectChanged();
    void typeChanged(int type);
    void sourceChanged(QString src);
    void directionChanged(int dir);
    void hpChanged(int health);
    void traversableChanged(bool tr);
    void shooting();
public slots:
    void shoot();
};

#endif // SHAPE_H
