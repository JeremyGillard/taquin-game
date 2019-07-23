#ifndef VIEW_H
#define VIEW_H

#include <memory>

#include "taquin.h"

class View {
public:
    View(Taquin& taquin);
    void welcomeMessage();
    unsigned sizeBoardQuestion();
    unsigned difficultyQuestion();
    std::pair<unsigned, unsigned> moveQuestion();
    void displayBoard() const;
    void endMessage(unsigned numberOfMoves) const;

private:
    Taquin* m_taquin;
};

#endif // VIEW_H
