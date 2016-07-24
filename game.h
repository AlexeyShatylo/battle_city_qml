#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "shape.h"
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QTimer>
#include <Qtime>
enum Behavior{Movement = 0, Shoot};

class Game : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Shape*> tankList READ tankList)
    Q_PROPERTY(QList<Shape*> gameItemsContainer READ getGameItemsContainer )
    Q_PROPERTY(int windowWidth READ windowWidth WRITE setWindowWidth NOTIFY windowWidthChanged)
    Q_PROPERTY(int windowHeigth READ windowHeigth WRITE setWindowHeigth NOTIFY windowsHeigthChanged)
    Q_PROPERTY(int qty READ getQty )
public:
    explicit Game(QObject *parent = 0);

    const double step = 13;

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

    void setTile(Shape* tile);

    Shape *tile();
    bool mapLoaded();
    int getQty() const;

    void initGameContainer();
    QList<Shape *> getGameItemsContainer() const;

    Q_INVOKABLE Shape* getTile(int index);
    Q_INVOKABLE  Shape *getItem(int index);
    Q_INVOKABLE bool move(Shape* tmp,int moveDir);
    Q_INVOKABLE bool isMovePossible(Shape *tmp, int moveDir);
    Q_INVOKABLE Shape *shoot(Shape *shooter);
    int shotOrMove();
    int randomMove();
    void init();
private:
    int m_windowWidth;
    int m_windowHeigth;
    QList<Shape*> m_tankList;
    QList<Shape*> m_tileList;
    QList<Shape*> m_gameItemsContainer;
    Shape* m_tile;
    QString m_map;
    QTimer* globalTimer;
signals:
    void gameOver();
    void gameStarted();
    void windowWidthChanged();
    void windowsHeigthChanged();
    void tileChanged();
    void created();
public slots:
    void startGame();
};

#endif // GAME_H
