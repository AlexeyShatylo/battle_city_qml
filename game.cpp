#include "game.h"

Game::Game(QObject *parent) : QObject(parent)
{

}

void Game::initTanks()
{

}

void Game::initTiles()
{


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
