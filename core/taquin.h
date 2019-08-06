#ifndef TAQUIN_H
#define TAQUIN_H

#include <memory>
#include <vector>

#include "board.h"

/**
 * @brief The Taquin class represents the model/façade of the game.
 *  It is through this class that all the actions of the game are done.
 */
class Taquin {

public:
    /**
     * @brief Taquin allows you to create the game Taquin.
     */
    Taquin();

    /**
     * @brief initBoard allows to init the board of the game with a certain size.
     * @param size the size of the board.
     */
    void initBoard(unsigned size);

    /**
     * @brief start allows to start the game by initializing the mixing of the board
     * with a certain degree of difficulty reflecting the number of cells moved during the shuffle.
     * @param difficultyLevel the difficulty reflecting the number of cells moved during the shuffle.
     */
    void start(unsigned difficultyLevel);

    /**
     * @brief allows you to move a cell on the game board within the limits of the available movements
     * @param i i coordinate of the cell to move.
     * @param j j coordinate of the cell to move.
     */
    void moveCellBoard(unsigned i, unsigned j);

    /**
     * @brief isOver returns true if the game is finish. That is, when the board returns to an unshuffled position.
     * @return true if the game is finish.
     */
    bool isOver() const;

    /**
     * @brief chosenSize returns the chosen size when the game board is initialized.
     */
    unsigned chosenSize() const;

    /**
     * @brief getCellAt return the number at the position (i, j)
     * @param i i coordinate of the cell.
     * @param j j coordinate of the cell.
     */
    unsigned getCellAt(unsigned i, unsigned j) const;

    /**
     * @brief getNumberOfMoves returns the number of moves executed since the beginning of the game until the game is over.
     */
    unsigned getNumberOfMoves() const;

    /**
     * @brief getMovesOptions returns the different movement options available at each move.
     * @return the different movement options available at each move.
     */
    std::vector<std::pair<unsigned, unsigned>> getMovesOptions() const;

private:
    /**
     * @brief m_board represents the board of the game.
     */
    std::unique_ptr<Board> m_board;

    /**
     * @brief m_chosenSize represents the chosen size when the game board is initialized.
     */
    unsigned m_chosenSize;

    /**
     * @brief m_numberOfMoves number of moves executed since the beginning of the game until the game is over.
     */
    unsigned m_numberOfMoves;
};

#endif // TAQUIN_H
