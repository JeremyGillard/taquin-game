#ifndef INTRODUCTIONLAYOUT_H
#define INTRODUCTIONLAYOUT_H

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "qtaquin.h"

/**
 * @brief The IntroductionScene class allows to represent the first page of the game
 * allowing the user to choose the size of the board for the next game and its difficulty.
 */
class IntroductionScene : public QWidget {

    Q_OBJECT

public:
    /**
     * @brief IntroductionScene allows to create the first page of the game.
     * @param qTaquin the model to display.
     * @param parent who will be in charge of its destruction.
     */
    explicit IntroductionScene(QTaquin& qTaquin, QWidget* parent = nullptr);

signals:
    /**
     * @brief gameIsInitialized is used to prevent that user data is selected
     * and that the game has been initiated, thus launching the game
     * and changing the page from the main window to the game page.
     */
    void gameIsInitialized();

public slots:
    /**
     * @brief initGame init the game with user Data.
     */
    void initGame();

private:
    QTaquin* taquin;
    QLabel* initSizeBoardLbl;
    QComboBox* initSizeBoardCbb;
    QLabel* initDifficultyLbl;
    QComboBox* initDifficultyCbb;
    QLabel* title;
    QPushButton* startBtn;

    QGridLayout* userInformationLayout;
    QVBoxLayout* mainLayout;

    /**
     * @brief initComponents initializes the components of the window.
     */
    void initComponents();

    /**
     * @brief arrangement correctly arranges the elements of the window.
     */
    void arrangement();

    /**
     * @brief behavior determines the behavior of the elements contained in the window.
     */
    void behavior();

    /**
     * @brief initUserInformationLayout arranges the elements of user inputs.
     */
    void initUserInformationLayout();
};

#endif // INTRODUCTIONLAYOUT_H
