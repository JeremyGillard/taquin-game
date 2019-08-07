#include "board.h"

Board::Board(unsigned size)
    : m_size(size)
{
    m_board.reserve(m_size);
    for (unsigned i = 0; i < m_size; ++i) {
        m_board.push_back(std::vector<unsigned>(m_size, 0));
        unsigned gap = i * m_size;
        for (unsigned j = 0; j < m_size; ++j) {
            m_board.at(i).at(j) = gap + j + 1;
            if (m_board.at(i).at(j) == m_size * m_size) {
                m_board.at(i).at(j) = 0;
                m_zeroPosition = std::pair<unsigned, unsigned>(i, j);
            }
        }
    }
    srand(unsigned(time(nullptr)));
}

std::pair<unsigned, unsigned> Board::getZeroPosition() const
{
    return m_zeroPosition;
}

std::vector<std::pair<unsigned, unsigned>> Board::getAvailableMovements() const
{
    std::vector<std::pair<unsigned, unsigned>> availableMovements;
    std::pair<unsigned, unsigned> p = m_zeroPosition;
    if (p.first > 0) {
        availableMovements.push_back(std::pair<unsigned, unsigned>(p.first - 1, p.second));
    }
    if (p.first < m_board.size() - 1) {
        availableMovements.push_back(std::pair<unsigned, unsigned>(p.first + 1, p.second));
    }
    if (p.second > 0) {
        availableMovements.push_back(std::pair<unsigned, unsigned>(p.first, p.second - 1));
    }
    if (p.second < m_board.size() - 1) {
        availableMovements.push_back(std::pair<unsigned, unsigned>(p.first, p.second + 1));
    }

    return availableMovements;
}

bool Board::areCoordinatesOk(unsigned i, unsigned j) const
{
    std::vector<std::pair<unsigned, unsigned>> availableMovements = getAvailableMovements();
    return std::find(availableMovements.begin(), availableMovements.end(), std::pair<unsigned, unsigned>(i, j)) != availableMovements.end();
}

bool Board::operator==(const Board& board) const
{
    if (board.size() != m_size)
        return false;
    for (unsigned i = 0; i < board.size(); ++i) {
        for (unsigned j = 0; j < board.size(); ++j) {
            if (m_board.at(i).at(j) != board.m_board.at(i).at(j))
                return false;
        }
    }
    return true;
}

unsigned Board::getCellAt(unsigned i, unsigned j) const
{
    return m_board.at(i).at(j);
}

bool Board::moveCell(unsigned i, unsigned j)
{
    if (areCoordinatesOk(i, j)) {
        std::swap(m_board.at(i).at(j), m_board.at(m_zeroPosition.first).at(m_zeroPosition.second));
        m_zeroPosition.first = i;
        m_zeroPosition.second = j;
        return true;
    }
    return false;
}

void Board::shuffle(unsigned mixNumber)
{
    std::vector<std::pair<unsigned, unsigned>> availableMovements;
    std::vector<std::pair<unsigned, unsigned>> previousMovements;
    previousMovements.reserve(3);
    previousMovements.push_back(getAvailableMovements().at(0));
    for (unsigned i = 0; i < mixNumber; ++i) {
        unsigned randomNumber = unsigned(rand()) % getAvailableMovements().size();
        std::pair<unsigned, unsigned> randomMovement = getAvailableMovements().at(randomNumber);
        while (std::find(previousMovements.begin(), previousMovements.end(), randomMovement) != previousMovements.end()) {
            randomNumber = unsigned(rand()) % getAvailableMovements().size();
            randomMovement = getAvailableMovements().at(randomNumber);
        }
        moveCell(randomMovement.first, randomMovement.second);
        previousMovements.push_back(randomMovement);
        if (previousMovements.size() == 3) {
            previousMovements.clear();
        }
    }
}

unsigned Board::size() const
{
    return m_size;
}
