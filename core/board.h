#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
    Board(unsigned size);
    unsigned size() const;
    std::pair<unsigned, unsigned> getZeroPosition() const;
    std::vector<std::pair<unsigned, unsigned>> getAvailableMovements() const;
    bool areCoordinatesOk(unsigned i, unsigned j) const;
    bool operator==(const Board& board) const;
    unsigned getCellAt(unsigned i, unsigned j) const;

    bool moveCell(unsigned i, unsigned j);
    void shuffle(unsigned mixNumber);

private:
    unsigned m_size;
    std::pair<unsigned, unsigned> m_zeroPosition;
    std::vector<std::vector<unsigned>> m_board;
};

#endif // BOARD_H
