#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>

#include "taquin.h"
#include "view.h"

/**
 * @brief The Controller class allows to orchestrate user interactions/views view with the Taquin model.
 */
class Controller {

public:
    /**
     * @brief Controller allows to create a controller that will orchestrate user interactions/views view with the Taquin model.
     * @param taquin the Taquin which will have to be linked to the view.
     * @param view the view that will have to be linked to the Taquin.
     */
    Controller(Taquin& taquin, View& view);

    /**
     * @brief startGame allows to start the game.
     */
    void startGame();

    /**
     * @brief mainGameFlow represents the main game flow.
     * The game loop from its initialization to its end.
     */
    void mainGameFlow();

private:
    /**
     * @brief m_taquin the Taquin which will have to be linked to the view.
     */
    Taquin* m_taquin;

    /**
     * @brief m_view the view that will have to be linked to the Taquin.
     */
    View* m_view;
};

#endif // CONTROLLER_H
