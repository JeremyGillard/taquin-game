#include "taquin.h"

Taquin::Taquin()
{
}

void Taquin::initBoard(unsigned size)
{
    m_numberOfMoves = 0;
    m_chosenSize = size;
    m_board = std::make_unique<Board>(size);
}

void Taquin::start(unsigned difficultyLevel)
{
    m_board->shuffle(difficultyLevel * 10);
}

void Taquin::moveCellBoard(unsigned i, unsigned j)
{
    m_board->moveCell(i, j);
    m_numberOfMoves++;
}

bool Taquin::isOver() const
{
    Board board(m_board->size());
    return *m_board == board;
}

unsigned Taquin::chosenSize() const
{
    return m_chosenSize;
}

unsigned Taquin::getCellAt(unsigned i, unsigned j) const
{
    return (*m_board).getCellAt(i, j);
}

unsigned Taquin::getNumberOfMoves() const
{
    return m_numberOfMoves;
}

std::vector<std::pair<unsigned, unsigned>> Taquin::getMovesOptions() const
{
    return m_board->getAvailableMovements();
}
