#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{
    setWindowHeigth(676);
    setWindowHeigth(676);
    qsrand(QTime::currentTime().msec());
    globalTimer = new QTimer(this);
    init();
    connect(globalTimer, SIGNAL(timeout()),this,SLOT(startGame()));
    globalTimer->start(100);

}
void Game::init() {
    initTiles();
    initGameContainer();
}

void Game::initGameContainer ()
{
    for(int i = 0; i < m_tileList.size(); i++) {
        if (m_tileList[i]->type() != ShapeType::Empty) {
            m_gameItemsContainer.append(m_tileList.at(i));
        }
    }
    Shape* base = new Shape;
    base->setYCoord(624);
    base->setXCoord(312);
    base->setType(ShapeType::Base);
    m_gameItemsContainer.append(base);

    Shape* userTank = new Shape;
    userTank->setYCoord(624);
    userTank->setXCoord(221);
    userTank->setType(ShapeType::PlayerTank);
    m_gameItemsContainer.append(userTank);

    Shape* aiTank= new Shape;
    aiTank->setType(ShapeType::AiTank);
    aiTank->setYCoord(0);
    aiTank->setXCoord(0);

    m_gameItemsContainer.append(aiTank);


}

QList<Shape *> Game::getGameItemsContainer() const
{
    return m_gameItemsContainer;
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
    return false;
}

bool Game::isMovePossible(Shape* tmp, int moveDir) {
    tmp->setDirection(moveDir);
    if (moveDir == Direction::Up && tmp->yCoord() > 0 )
    {
        for (int i = 0; i < m_gameItemsContainer.size(); i++) {
            if (m_gameItemsContainer[i]->yCoord() == tmp->yCoord() + step) {
                return false;
            }
        }
        return true;
    }
    if (moveDir == Direction::Right && tmp->xCoord() <  676 - 52)
    {
        for (int i = 0; i < m_tileList.size(); i++) {
            if ((m_tileList.at(i)->type() == ShapeType::Empty ) && (m_tileList.at(i)->xCoord()) == (tmp->xCoord() + 52 + step)) {
                break;
            }else {
                return true;
            }
        }
    }
    if (moveDir == Direction::Left && tmp->xCoord() < 0)
    {
        for (int i = 0; i < m_gameItemsContainer.size(); i++) {
            if ((m_gameItemsContainer[i]->xCoord()) == (tmp->xCoord() - step)) {
                return false;
            }
        }
        return true;
    }
    if (moveDir == Direction::Down && tmp->yCoord() < 676 - 52)
    {
        for (int i = 0; i < m_gameItemsContainer.size(); i++) {
            if ((m_gameItemsContainer[i]->yCoord()) == (tmp->yCoord() + step)) {
                return false;
            }
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
    Shape* currentTank;
    for (int i = 0; i < m_gameItemsContainer.size(); i++) {
        if ((ShapeType::AiTank == m_gameItemsContainer.at(i)->type())) {
            bool sOm = shotOrMove();
            currentTank = m_gameItemsContainer.at(i);
            if (sOm == Behavior::Movement) {
                int rm = randomMove();
                move(currentTank, rm);
            }
            if (sOm == Behavior::Shoot) {
                shoot(currentTank);
            }
        }
    }
}
bool Game::move(Shape* tmp, int moveDir) {
    bool isPossible  = isMovePossible(tmp,moveDir);
    if(isPossible) {
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
    bullet->setDirection(shooter->direction());
    if (bullet->direction() == Direction::Up || bullet->direction() == Direction::Down) {

        bullet->setXCoord( shooter->xCoord() + 26 );
        bullet->setYCoord(shooter->yCoord());
    }

    if (bullet->direction() == Direction::Right || bullet->direction() == Direction::Left) {
        bullet->setXCoord(shooter->xCoord() + 52);
        bullet->setYCoord(shooter->yCoord() + 26);
    }
    m_gameItemsContainer.append(bullet);
    return bullet;
}

bool Game::initTiles()
{
    mapLoaded();
    for (int i = 0; i < m_map.size(); i++) {
        Shape* tile = new Shape(this);
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
