#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{
    initTiles();
}

void Game::initTanks()
{

}
bool Game::mapLoaded ()
{
    QFile fl("../Battle_city_qml/levels/level1_tile.txt");
    if (!fl.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return 1;
    }
    QTextStream in (&fl);
    QString str (fl.readLine());
    m_map = str;
    if(!m_map.isEmpty()) {
        return true;
    }
}

int Game::getQty() const
{
    m_tileList.size();
}

bool Game::initTiles()
{
    mapLoaded();
    for (int i = 0; i < m_map.size(); i++) {
        Shape* tile = new Shape;
        tile->setType(m_map[i].digitValue());
        m_tileList.append(tile);
    }
    for (int i = 0; i < (m_tileList.size()/26); i++) {
        for(int j = 0; j <(m_tileList.size()/26); j++) {
            m_tileList[i*m_tileList.size()/26 + j]->setXCoord(26*j);
        }
    }
    int level = 0;
    for (int i = 0; i < m_tileList.size(); i++) {
            m_tileList[i]->setYCoord(level*26);
        if(i > 0 && (i+1) % 26 == 0) {
            level += 1 ;
        }
    }
    emit created();
}

int Game::windowWidth() const
{
    return m_windowWidth;
}

void Game::setWindowWidth(int windowWidth)
{
    m_windowWidth = windowWidth;
}

int Game::windowHeigth() const
{
    return m_windowHeigth;
}

void Game::setWindowHeigth(int windowHeigth)
{
    m_windowHeigth = windowHeigth;
}

QList<Shape *> Game::tankList() const
{
    return m_tankList;
}

QList<Shape *> Game::tileList() const
{
    return m_tileList;
}

Shape *Game::getTile(int index)
{
    return m_tileList[index];
}

Shape *Game::tile()
{
    return m_tile;
}
void Game::setTile(Shape *tile)
{
    m_tile = tile;
}
