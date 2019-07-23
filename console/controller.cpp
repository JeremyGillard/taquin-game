#include "controller.h"

Controller::Controller(Taquin& taquin, View& view)
    : m_taquin(&taquin)
    , m_view(&view)
{
}

void Controller::startGame()
{
    m_view->welcomeMessage();
    m_taquin->initBoard(m_view->sizeBoardQuestion());
    m_taquin->start(m_view->difficultyQuestion());
    mainGameFlow();
}

void Controller::mainGameFlow()
{
    while (!m_taquin->isOver()) {
        m_view->displayBoard();
        std::pair<unsigned, unsigned> chosenCoordinates = m_view->moveQuestion();
        m_taquin->moveCellBoard(chosenCoordinates.first, chosenCoordinates.second);
    }
    m_view->endMessage(m_taquin->getNumberOfMoves());
}
