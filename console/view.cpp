#include "view.h"

View::View(Taquin& taquin)
    : m_taquin(&taquin)
{
}

void View::welcomeMessage()
{
    std::cout << "Welcome to Taquin game !!!!\n"
              << std::endl;
    std::cout << std::setw(25) << "[Press Enter to launch]" << std::endl;
}

unsigned View::sizeBoardQuestion()
{
    std::cin.ignore();
    int sizeBoard { -1 };
    do {
        try {
            std::cout << "What size of game board do you want (3/4/5) ? : ";
            sizeBoard = nvs::lineFromKbd<int>();
        } catch (const std::exception& e) {
            std::cout << "Sorry, you have to give a number between 3 and 5, please try again" << std::endl;
        }
    } while (sizeBoard < 3 || sizeBoard > 5);
    return unsigned(sizeBoard);
}

unsigned View::difficultyQuestion()
{
    //std::cin.ignore();
    int difficulty { -1 };
    do {
        try {
            std::cout << "Which difficulty do you want to choose (1-10) ? : ";
            difficulty = nvs::lineFromKbd<int>();
        } catch (const std::exception& e) {
            std::cout << "Sorry, you have to give a number between 1 and 10, please try again" << std::endl;
        }
    } while (difficulty < 1 || difficulty > 10);
    return unsigned(difficulty);
}

std::ostream& operator<<(std::ostream& os, const std::vector<std::pair<unsigned, unsigned>>& v)
{
    os << "Availables moves: ";
    for (unsigned i = 0; i < v.size(); ++i) {
        os << std::setw(2) << v.at(i).first << std::setw(2) << v.at(i).second << " ";
    }
    os << std::endl
       << std::setw(18) << "";
    for (unsigned i = 0; i < v.size(); ++i) {
        os << std::setw(3) << i + 1 << "  ";
    }
    os << std::endl;
    return os;
}

std::pair<unsigned, unsigned> View::moveQuestion()
{
    //std::cin.ignore();
    std::vector<std::pair<unsigned, unsigned>> movesOptions = m_taquin->getMovesOptions();
    int chosenOption { -1 };
    do {
        try {
            std::cout << "Here are the cells you can move. Which one do you choose?\nEnter one of the numbers indicated below the cells coordinates (row, col)." << std::endl;
            std::cout << movesOptions;
            std::cout << "Chosen option : ";
            chosenOption = nvs::lineFromKbd<int>();
        } catch (const std::exception& e) {
            std::cout << "Sorry, you have to give a number between 1 and " << movesOptions.size() << ", please try again" << std::endl;
        }
    } while (chosenOption < 1 || chosenOption > int(movesOptions.size()));
    return movesOptions.at(unsigned(chosenOption - 1));
}

void View::displayBoard() const
{
    unsigned size = m_taquin->chosenSize();
    std::cout << std::endl;
    for (unsigned i = 0; i < size; ++i) {
        for (unsigned j = 0; j < size; ++j) {
            if (m_taquin->getCellAt(i, j) != 0) {
                std::cout << std::setw(3) << m_taquin->getCellAt(i, j);
            } else {
                std::cout << std::setw(3) << "";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void View::endMessage(unsigned numberOfMoves) const
{
    std::cout << "\nCongratulation! You finished this game in " << numberOfMoves << " Moves.\n"
              << std::endl;
}
