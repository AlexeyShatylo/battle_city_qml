#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{
    setWindowHeigth(676);
    setWindowHeigth(676);
    qsrand(QTime::currentTime().msec());
    globalTimer = new QTimer(this);
    init();
    connect(globalTimer, SIGNAL(timeout()),this,SLOT(startGame()));
    globalTimer->start(50);

}
void Game::init() {
    initTiles();
    initGameContainer();
}

void Game::initGameContainer ()
{
    for(int i = 0; i < m_tileList.size(); i++) {
        m_gameItemsContainer.append(m_tileList.at(i));
    }
    Shape* base = new Shape;
    base->setYCoord(624);
    base->setXCoord(312);
    base->setType(ShapeType::Base);
    base->setHeight(52);
    base->setWidth(52);
    m_gameItemsContainer.append(base);

    Shape* userTank = new Shape;
    userTank->setYCoord(624);
    userTank->setXCoord(221);
    userTank->setType(ShapeType::PlayerTank);
    userTank->setHeight(52);
    userTank->setWidth(52);
    m_gameItemsContainer.append(userTank);

    Shape* aiTank= new Shape;
    aiTank->setType(ShapeType::AiTank);
    aiTank->setYCoord(0);
    aiTank->setXCoord(0);
    aiTank->setHeight(52);
    aiTank->setWidth(52);
    m_gameItemsContainer.append(aiTank);


}

QList<Shape *> Game::getGameItemsContainer() const
{
    return m_gameItemsContainer;
}

bool Game::mapLoaded ()
{
    QFile fl("../battle_city_qml/levels/level1_tile.txt");
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
    return false;
}

bool Game::isMovePossible(Shape* tmp, int moveDir) {
    //ok
    tmp->setDirection(moveDir);
    if (moveDir == Direction::Up) {
        if(tmp->yCoord() >= 0 && tmp->yCoord() <= 676) {
            for (int i = 0; i < m_gameItemsContainer.size(); i++) {
                if ((m_gameItemsContainer.at(i)->type() == ShapeType::Empty )
                        && (m_gameItemsContainer.at(i)->shapeRect().contains(tmp->xCoord(), tmp->yCoord() - step, false))) {
                    return true;
                }
            }
        }else {
            return false;
        }
    }
    if (moveDir == Direction::Down) {
        if(tmp->yCoord() >= 0 && tmp->yCoord() <= 676) {
            for (int i = 0; i < m_gameItemsContainer.size(); i++) {
                if ((m_gameItemsContainer.at(i)->type() == ShapeType::Empty)
                        && (m_gameItemsContainer.at(i)->shapeRect().contains(tmp->xCoord(), tmp->yCoord() + step, false))) {
                    return true;
                }
            }
        }else {
            return false;
        }
    }
    if (moveDir == Direction::Left) {
        if(tmp->xCoord() >= 0 && tmp->xCoord() <= 676) {
            for (int i = 0; i < m_gameItemsContainer.size(); i++) {
                if ((m_gameItemsContainer.at(i)->type() == ShapeType::Empty )
                        && (m_gameItemsContainer.at(i)->shapeRect().contains(tmp->xCoord() - step, tmp->yCoord(), false))) {
                    return true;
                }
            }
        }else {
            return false;
        }
    }

    if (moveDir == Direction::Right) {
        if(tmp->xCoord() >= 0 && tmp->xCoord() <= 676) {
            for (int i = 0; i < m_gameItemsContainer.size(); i++) {
                if ((m_gameItemsContainer.at(i)->type() == ShapeType::Empty )
                        && (m_gameItemsContainer.at(i)->shapeRect().contains(tmp->xCoord() + step, tmp->yCoord(), false))) {
                    return true;
                }
            }
        }else {
            return false;
        }
    }
    return false;
}

int Game::randomMove(){

    int tmp = qrand() % 4;
    return tmp;
}

int Game::shotOrMove(){
    int tmp = qrand() % 2;
    return tmp;
}

void Game::startGame()
{
    Shape* currentObject;
    for (int i = 0; i < m_gameItemsContainer.size(); i++) {
        if ((ShapeType::AiTank == m_gameItemsContainer.at(i)->type())) {
            bool sOm = shotOrMove();
            currentObject = m_gameItemsContainer.at(i);
            if (sOm == Behavior::Movement) {
                move(currentObject, randomMove());
            }
            if (sOm == Behavior::Shoot) {
                shoot(currentObject);
            }
        }
        if (ShapeType::Bullet == m_gameItemsContainer.at(i)->type()) {
            move(m_gameItemsContainer.at(i), m_gameItemsContainer.at(i)->direction());
        }
    }
}
bool Game::move(Shape* tmp, int moveDir) {
    if(isMovePossible(tmp,moveDir)){

        switch (moveDir) {
        case Direction::Up:
            tmp->setYCoord(tmp->yCoord() - step);
            break;
        case Direction::Down:
            tmp->setYCoord(tmp->yCoord() + step);
            break;
        case Direction::Left:
            tmp->setXCoord(tmp->xCoord() - step);
            break;
        case Direction::Right:
            tmp->setXCoord(tmp->xCoord() + step);
            break;
        default:
            break;
        }
        return true;
    }
    return false;
}
Shape* Game::shoot(Shape* shooter) {
    Shape* bullet = new Shape();
    bullet->setType(ShapeType::Bullet);
    bullet->setWidth(tileWidth);
    bullet->setHeight(tileHeigth);
    bullet->setDirection(shooter->direction());
    bullet->setXCoord( shooter->shapeRect().center().x());
    bullet->setYCoord(shooter->shapeRect().center().y());
    m_gameItemsContainer.append(bullet);

    return bullet;
}

bool Game::initTiles()
{
    mapLoaded();
    for (int i = 0; i < m_map.size(); i++) {
        Shape* tile = new Shape(this);
        tile->setType(m_map[i].digitValue());
        tile->setHeight(26);
        tile->setWidth(26);
        m_tileList.append(tile);

    }
    for (int i = 0; i < (m_tileList.size() / tileWidth); i++) {
        for(int j = 0; j < (m_tileList.size() / tileWidth); j++) {
            m_tileList[ i * m_tileList.size() / tileWidth + j]->setXCoord(tileWidth * j);
        }
    }
    int level = 0;
    for (int i = 0; i < m_tileList.size(); i++) {
        m_tileList[i]->setYCoord(level * tileHeigth);
        if (i > 0 && (i + 1) % tileHeigth == 0) {
            level += 1 ;
        }
    }
    for (int i = 0; i < m_tileList.size(); i++ ) {
        m_tileList.at(i)->setShapeRect(QRect(m_tileList.at(i)->xCoord(),m_tileList.at(i)->yCoord(),m_tileList.at(i)->width(),m_tileList.at(i)->height()));
    }
    return true;
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
Shape* Game::getItem(int index)
{
    return m_gameItemsContainer[index];
}
int Game::getQty() const
{
    return m_gameItemsContainer.size();
}
