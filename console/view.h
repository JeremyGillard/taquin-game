#ifndef VIEW_H
#define VIEW_H

#include <memory>

#include "taquin.h"

/**
 * @brief The View class allows to display the game Taquin in the standard console.
 */
class View {

public:
    /**
     * @brief View allows to create a view for the game Taquin.
     * @param taquin the teasing game to be represented.
     */
    View(Taquin& taquin);

    /**
     * @brief welcomeMessage allows to display a welcome/introduction message.
     */
    void welcomeMessage();

    /**
     * @brief sizeBoardQuestion allows to ask to the user the size wanted to apply to the board.
     */
    unsigned sizeBoardQuestion();

    /**
     * @brief difficultyQuestion allows to ask to the user the difficulty of the game.
     */
    unsigned difficultyQuestion();

    /**
     * @brief moveQuestion allows to ask to the user which movement to choose and returns it in terms of coordinates.
     * @return the move chosen in terms of coordinates.
     */
    std::pair<unsigned, unsigned> moveQuestion();

    /**
     * @brief displayBoard allows to display the board of the game.
     */
    void displayBoard() const;

    /**
     * @brief endMessage allows to diplay the an end of game message with the number of total moves played.
     * @param numberOfMoves the number of total moves played.
     */
    void endMessage(unsigned numberOfMoves) const;

private:
    /**
     * @brief m_taquin the Taquin game to be represented.
     */
    Taquin* m_taquin;
};

#endif // VIEW_H
