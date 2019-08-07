#ifndef GAMELAYOUT_H
#define GAMELAYOUT_H

#include <QGridLayout>
#include <QLabel>
#include <QList>
#include <QMessageBox>
#include <QPixmap>
#include <QVBoxLayout>
#include <QWidget>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <thread>

#include "cell.h"
#include "qtaquin.h"

/**
 * @brief The GameScene class allows to display the game board and play with it.
 */
class GameScene : public QWidget {

    Q_OBJECT

public:
    /**
     * @brief GameScene allows to create a game scene that allows the player to play with the game Taquin.
     * @param qTaquin the taquin that will be represented.
     * @param parent parent who will be in charge of its destruction.
     */
    explicit GameScene(QTaquin& qTaquin, QWidget* parent = nullptr);

signals:
    /**
     * @brief newGameConfirmation signal when a player decides to start a new game without having finished the previous one.
     */
    void newGameConfirmation();

public slots:
    /**
     * @brief initBoard allows to init the board of the game when the game is launched.
     */
    void initBoard();

    /**
     * @brief updateBoard allows you to update the game board during the game.
     */
    void updateBoard();

    /**
     * @brief finalBoard allows you to display the completed image not fragmented when the player has finished the game.
     */
    void finalBoard();

    /**
     * @brief newGame allows you to launch a new game.
     */
    void newGame();

    /**
     * @brief newImage allows to change the background image during the game.
     */
    void newImage();

    /**
     * @brief showNumbers allows to show or hide the number on cells.
     */
    void showNumbers();

private:
    /**
     * @brief taquin the model of the Taquin represented.
     */
    QTaquin* taquin;

    /**
     * @brief progressLbl the label that display de number of moves done by the player.
     */
    QLabel* progressLbl;

    /**
     * @brief boardWidget is the widget that contains the board representation (the board layout).
     */
    QWidget* boardWidget;

    /**
     * @brief newGameBtn is the button that allows the player to launch a new game.
     */
    QPushButton* newGameBtn;

    /**
     * @brief imgGalery is the image available to display in the game.
     */
    QList<QPixmap> imgGalery;

    /**
     * @brief currentImg is the current image randomly load during the game initialization.
     */
    QList<QPixmap>::iterator currentImg;

    /**
     * @brief imgFragments is the current image fragments list.
     */
    QList<QPixmap> imgFragments;

    /**
     * @brief boardLayout allows to display correctly the different cells that represent the board of the game.
     */
    QGridLayout* boardLayout;

    /**
     * @brief mainLayout is the main layout of the game scene.
     */
    QVBoxLayout* mainLayout;

    /**
     * @brief numberVisible is true if the number have to be displayed on the cells.
     */
    bool numberVisible;

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
     * @brief clearComponents allows to reset the number of move displayed on the next game scene and delete the cells of the previous game.
     */
    void clearComponents();

    /**
     * @brief createImgFragments allows to create fragments images for the cells of the board.
     */
    void createImgFragments();

    /**
     * @brief loadImages allows to load images stored in resources program.
     */
    void loadImages();

    /**
     * @brief pickRandomImage allows to pick a random image from the image gallery.
     */
    void pickRandomImage();
};

#endif // GAMELAYOUT_H
