#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "shape.h"
#include <QList>
#include <QFile>
class Game : public QObject
{
    Q_OBJECT
//    Q_PROPERTY(QList tankList READ tankList WRITE setTankList NOTIFY tankListChanged)
//    Q_PROPERTY(QList tileList READ tileList WRITE setTileList NOTIFY tileListChanged)
    Q_PROPERTY(int windowWidth READ windowWidth WRITE setWindowWidth NOTIFY windowWidthChanged)
    Q_PROPERTY(int windowHeigth READ windowHeigth WRITE setWindowHeigth NOTIFY windowsHeigthChanged)
public:
    explicit Game(QObject *parent = 0);
    void initTanks();
    void initTiles();
    bool checkMovement();
//    Q_INVOKABLE void gameStart();
//    Q_INVOKABLE void move();
    int windowWidth() const;
    void setWindowWidth(int windowWidth);

    int windowHeigth() const;
    void setWindowHeigth(int windowHeigth);

private:
    QList<Shape*> m_tankList;
    QList<Shape*> m_tileList;
    int m_windowWidth;
    int m_windowHeigth;
signals:
//    void gameOver();
//    void gameStart();
    void windowWidthChanged();
    void windowsHeigthChanged();
public slots:
};

#endif // GAME_H
