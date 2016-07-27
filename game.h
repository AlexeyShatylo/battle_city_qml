#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "shape.h"
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QTimer>
#include <QTime>
#include <QRect>
#include <QQmlEngine>
enum Behavior{Movement = 0, Shoot};

class Game : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Shape*> tankList READ tankList)
    Q_PROPERTY(QList<Shape*> gameItemsContainer READ getGameItemsContainer )
    Q_PROPERTY(int windowWidth READ windowWidth WRITE setWindowWidth NOTIFY windowWidthChanged)
    Q_PROPERTY(int windowHeigth READ windowHeigth WRITE setWindowHeigth NOTIFY windowsHeigthChanged)
    Q_PROPERTY(Shape* shooter READ shooter WRITE setShooter NOTIFY shooterChanged)
    Q_PROPERTY(int qty READ getQty )
private:
    int m_windowWidth;
    int m_windowHeigth;
    QList<Shape*> m_tankList;
    QList<Shape*> m_tileList;
    QList<Shape*> m_gameItemsContainer;
    Shape* m_shooter;
    QString m_map;
    QTimer* globalTimer;

public:
    explicit Game(QObject *parent = 0);

    const int step = 13;
    const int tileWidth = 26;
    const int tileHeigth = 26;
    const int tankWidth= 52;
    const int tankHeigth = 52;

    bool initTiles();
    bool checkMovement();
    bool mapLoaded();
    void initGameContainer();

    int windowHeigth() const;
    int windowWidth() const;
    int getQty() const;
    Q_INVOKABLE Shape* getTile(int index);
    Q_INVOKABLE  Shape *getItem(int index);


    QList<Shape*> getGameItemsContainer() const;
    QList<Shape*> tankList() const;
    QList<Shape*> tileList() const;

    void setWindowWidth(int windowWidth);
    void setWindowHeigth(int windowHeigth);

    Q_INVOKABLE bool move(Shape* movingShape,int moveDir);
    Q_INVOKABLE bool isMovePossible(Shape *movingShape, int moveDir);
    Q_INVOKABLE Shape *shoot(Shape *shooter);
    int shotOrMove();
    int randomMove();
    void init();

    Shape *shooter() const;
    void setShooter(Shape *shooter);

signals:
    void gameOver();
    void gameStarted();
    void windowWidthChanged(int w);
    void windowsHeigthChanged(int h);
    void shooterChanged(Shape*);

public slots:

private slots:
    void startGame();
};

#endif // GAME_H
