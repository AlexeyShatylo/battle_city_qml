#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "shape.h"
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QString>

class Game : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Shape*> tankList READ tankList)
    Q_PROPERTY(Shape* tile READ tile WRITE setTile NOTIFY tileChanged)
    Q_PROPERTY(QList<Shape*> tileList READ tileList)
    Q_PROPERTY(int windowWidth READ windowWidth WRITE setWindowWidth NOTIFY windowWidthChanged)
    Q_PROPERTY(int windowHeigth READ windowHeigth WRITE setWindowHeigth NOTIFY windowsHeigthChanged)
    Q_PROPERTY(int qty READ getQty )
public:
    explicit Game(QObject *parent = 0);
    void initTanks();
    bool initTiles();
    bool checkMovement();
//    Q_INVOKABLE void gameStart();
//    Q_INVOKABLE void move();
    int windowWidth() const;
    void setWindowWidth(int windowWidth);

    int windowHeigth() const;
    void setWindowHeigth(int windowHeigth);

    QList<Shape *> tankList() const;
    QList<Shape *> tileList() const;

    Q_INVOKABLE Shape *getTile(int index);
    void setTile(Shape *tile);

    Shape *tile();
    bool mapLoaded();
    int getQty() const;

private:
    QList<Shape*> m_tankList;
    QList<Shape*> m_tileList;
    Shape* m_tile;
    QString m_map;
    int m_windowWidth;
    int m_windowHeigth;
signals:
    void gameOver();
    void gameStarted();
    void windowWidthChanged();
    void windowsHeigthChanged();
    void tileChanged();
    void created();
public slots:
};

#endif // GAME_H
