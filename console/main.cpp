#include <iostream>
#include <vector>

#include "controller.h"
#include "taquin.h"
#include "view.h"

int main()
{
    Taquin taquin;
    View view(taquin);
    Controller controller(taquin, view);

    controller.startGame();

    return 0;
}
