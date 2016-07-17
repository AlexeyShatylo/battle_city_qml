#ifndef GAME_H
#define GAME_H

#include <QObject>
#include "shape.h"
#include <QList>

class Game : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList tankList READ tankList WRITE setTankList NOTIFY tankListChanged)
    Q_PROPERTY(QList tileList READ tileList WRITE setTileList NOTIFY tileListChanged)
public:
    explicit Game(QObject *parent = 0);
    void initTanks();
private:
    QList<Shape*> m_tankList;
    QList<Shape*> m_tileList;
signals:

public slots:
};

#endif // GAME_H
