#ifndef TAQUIN_H
#define TAQUIN_H

#include <memory>
#include <vector>

#include "board.h"

class Taquin {
public:
    Taquin();
    void initBoard(unsigned size);
    void start(unsigned difficultyLevel);
    void moveCellBoard(unsigned i, unsigned j);
    bool isOver() const;
    unsigned chosenSize() const;
    unsigned getCellAt(unsigned i, unsigned j) const;
    unsigned getNumberOfMoves() const;
    std::vector<std::pair<unsigned, unsigned>> getMovesOptions() const;

private:
    std::unique_ptr<Board> m_board;
    unsigned m_chosenSize;
    unsigned m_numberOfMoves;
};

#endif // TAQUIN_H
