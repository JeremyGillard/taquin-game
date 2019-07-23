#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>

#include "taquin.h"
#include "view.h"

class Controller {
public:
    Controller(Taquin& taquin, View& view);
    void startGame();
    void mainGameFlow();

private:
    Taquin* m_taquin;
    View* m_view;
};

#endif // CONTROLLER_H
