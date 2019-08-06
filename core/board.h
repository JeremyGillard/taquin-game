#ifndef BOARD_H
#define BOARD_H

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

/**
 * @brief The Board class is a representation of the game board with its different tiles.
 */
class Board {

public:
    /**
     * @brief Board allows to create a game board with a certain size.
     * @param size the size of the game board.
     */
    Board(unsigned size);

    /**
     * @brief size returns the size of the game board.
     */
    unsigned size() const;

    /**
     * @brief getZeroPosition returns the position 0 (in terms of coordinates) which represents
     * the empty square of the game board.
     * @return the position 0 which represents the empty square of the game board.
     */
    std::pair<unsigned, unsigned> getZeroPosition() const;

    /**
     * @brief getAvailableMovements returns the coordinates of the locations that can be moved
     * to the 0 position, in other words, the coordinates adjacent to the 0 position within
     * the limits of the game board.
     * @return the coordinates adjacent to the 0 position.
     */
    std::vector<std::pair<unsigned, unsigned>> getAvailableMovements() const;

    /**
     * @brief areCoordinatesOk checks if the coordinates entered in parameter are part
     * of the coordinates available for a cell movement.
     * @param i i coordinate to check.
     * @param j j coordinate to check.
     * @return true if the coordinates are validated.
     */
    bool areCoordinatesOk(unsigned i, unsigned j) const;

    /**
     * @brief operator == allows you to check if two game boards are identical.
     * @param board the second board to compare with.
     * @return true if both boards are equals.
     */
    bool operator==(const Board& board) const;

    /**
     * @brief getCellAt return the number at the position (i, j)
     * @param i i coordinate of the cell.
     * @param j j coordinate of the cell.
     */
    unsigned getCellAt(unsigned i, unsigned j) const;

    /**
     * @brief moveCell allows to move a cell (a number) selected at the 0 coordinates.
     * @param i i coordinate of the cell.
     * @param j j coordinate of the cell.
     * @return true if the movement has been approved and executed
     */
    bool moveCell(unsigned i, unsigned j);

    /**
     * @brief shuffle allows to shuffle the cells of the board.
     * @param mixNumber the number of cell moves.
     */
    void shuffle(unsigned mixNumber);

private:
    /**
     * @brief m_size the size of the board.
     */
    unsigned m_size;

    /**
     * @brief m_zeroPosition the position of the number 0.
     */
    std::pair<unsigned, unsigned> m_zeroPosition;

    /**
     * @brief m_board the board in terms of structure of the std lib.
     */
    std::vector<std::vector<unsigned>> m_board;
};

#endif // BOARD_H
