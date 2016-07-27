#include "game.h"

Shape *Game::shooter() const
{
    return m_shooter;
}

void Game::setShooter(Shape *shooter)
{
    if(shooter != m_shooter){
        m_shooter = shooter;
        emit shooterChanged(shooter);
    }
}

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
        m_gameItemsContainer.append(m_tileList.at(i));
    }
    Shape* base = new Shape;
    base->setYCoord(624);
    base->setXCoord(312);
    base->setType(ShapeType::Base);
    base->setHeight(tankHeigth);
    base->setWidth(tankWidth);
    m_gameItemsContainer.append(base);

    Shape* userTank = new Shape;
    userTank->setYCoord(624);
    userTank->setXCoord(221);
    userTank->setType(ShapeType::PlayerTank);
    userTank->setHeight(tankHeigth);
    userTank->setWidth(tankWidth);
    m_gameItemsContainer.append(userTank);

    Shape* aiTank = new Shape;
    aiTank->setType(ShapeType::AiTank);
    aiTank->setYCoord(0);
    aiTank->setXCoord(0);
    aiTank->setHeight(tankHeigth);
    aiTank->setWidth(tankWidth);
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
        return 0;
    }
    QTextStream in (&fl);
    QString str (fl.readLine());
    m_map = str;

    if(!m_map.isEmpty()) {
        return true;
    }
    return false;
}

bool Game::isMovePossible(Shape* movingShape, int moveDir) {
    movingShape->setDirection(moveDir);
    if (moveDir == Direction::Up) {

        if(movingShape->yCoord() >= 0 && movingShape->yCoord() <= 676 ) {
            for (int i = 0; i < m_gameItemsContainer.size(); i++) {
                if ((m_gameItemsContainer.at(i)->type() == ShapeType::Empty)
                        && (m_gameItemsContainer.at(i)->shapeRect().contains(movingShape->xCoord(), movingShape->yCoord() - step, false))) {
                    return true;
                }

            }
        }else {
            return false;
        }
    }
    if (moveDir == Direction::Down) {
        if(movingShape->yCoord() >= 0 && movingShape->yCoord() <= 676) {
            for (int i = 0; i < m_gameItemsContainer.size(); i++) {
                if ((m_gameItemsContainer.at(i)->type() == ShapeType::Empty)
                        && (m_gameItemsContainer.at(i)->shapeRect().contains(movingShape->xCoord(), movingShape->yCoord() + step, false))) {
                    return true;
                }
                if ((movingShape->yCoord() == 0 || movingShape->yCoord() == 676) && movingShape->type() == ShapeType::Bullet ) {

                }
            }
        }else {
            return false;
        }
    }
    if (moveDir == Direction::Left) {
        if (movingShape->xCoord() >= 0 && movingShape->xCoord() <= 676) {
            for (int i = 0; i < m_gameItemsContainer.size(); i++) {
                if ((m_gameItemsContainer.at(i)->type() == ShapeType::Empty )
                        && (m_gameItemsContainer.at(i)->shapeRect().contains(movingShape->xCoord() - step, movingShape->yCoord(), false))) {
                    return true;
                }
            }
        }else {
            return false;
        }
    }

    if (moveDir == Direction::Right) {
        if(movingShape->xCoord() >= 0 && movingShape->xCoord() <= 676) {
            for (int i = 0; i < m_gameItemsContainer.size(); i++) {
                if ((m_gameItemsContainer.at(i)->type() == ShapeType::Empty )
                        && (m_gameItemsContainer.at(i)->shapeRect().contains(movingShape->xCoord() + step, movingShape->yCoord(), false))) {
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

    int rm = qrand() % 4;
    return rm;
}

int Game::shotOrMove(){
    int sOm = qrand() % 2;
    return sOm;
}

void Game::startGame()
{
    Shape* currentObject;
    for (int i = 0; i < m_gameItemsContainer.size(); i++) {
        if ((ShapeType::AiTank == m_gameItemsContainer.at(i)->type())) {
            currentObject = m_gameItemsContainer.at(i);
            if (shotOrMove() == Behavior::Movement) {
                move(currentObject, randomMove());
            }
            if (shotOrMove() == Behavior::Shoot) {
                shoot(currentObject);
            }
        }
        if (ShapeType::Bullet == m_gameItemsContainer.at(i)->type()) {
            move(m_gameItemsContainer.at(i), m_gameItemsContainer.at(i)->direction());
        }
    }
}
bool Game::move(Shape* movingShape, int moveDir) {
    bool possible = isMovePossible(movingShape,moveDir);
    if(possible){
        switch (moveDir) {
        case Direction::Up:
            movingShape->setYCoord(movingShape->yCoord() - step);
            break;
        case Direction::Down:
            movingShape->setYCoord(movingShape->yCoord() + step);
            break;
        case Direction::Left:
            movingShape->setXCoord(movingShape->xCoord() - step);
            break;
        case Direction::Right:
            movingShape->setXCoord(movingShape->xCoord() + step);
            break;
        default:
            break;
        }
        return true;
    } else /*if(movingShape->type() == ShapeType::Bullet && !possible) {
        for (int i = 0; i < m_gameItemsContainer.size(); i++) {
            if (movingShape == m_gameItemsContainer.at(i)) {
                m_gameItemsContainer.removeAt(i);
                delete movingShape;
            }
        }
    }*/
    return false;
}
Shape* Game::shoot(Shape* shooter) {
    setShooter(shooter);
    Shape* bullet = new Shape();
    bullet->setType(ShapeType::Bullet);
    bullet->setWidth(tileWidth);
    bullet->setHeight(tileHeigth);
    bullet->setDirection(m_shooter->direction());
    bullet->setXCoord(m_shooter->shapeRect().center().x());
    bullet->setYCoord(m_shooter->shapeRect().center().y());
    m_gameItemsContainer.append(bullet);
    emit m_shooter->shooting();
    QQmlEngine::setObjectOwnership(bullet,QQmlEngine::CppOwnership);
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
        m_tileList.at(i)->setShapeRect(QRect(m_tileList.at(i)->xCoord(), m_tileList.at(i)->yCoord(), m_tileList.at(i)->width(), m_tileList.at(i)->height()));
    }
    return true;
}
int Game::windowWidth() const
{
    return m_windowWidth;
}

void Game::setWindowWidth(int windowWidth)
{
    if(windowWidth != m_windowWidth){
        m_windowWidth = windowWidth;
        emit windowWidthChanged(windowWidth);
    }
}

int Game::windowHeigth() const
{
    return m_windowHeigth;
}

void Game::setWindowHeigth(int windowHeigth)
{
    if(windowHeigth != m_windowHeigth) {
        m_windowHeigth = windowHeigth;
        emit windowsHeigthChanged(windowHeigth);
    }
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

Shape* Game::getItem(int index)
{
    return m_gameItemsContainer[index];
}
int Game::getQty() const
{
    return m_gameItemsContainer.size();
}
