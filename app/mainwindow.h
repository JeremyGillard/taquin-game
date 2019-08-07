#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QFile>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStackedLayout>
#include <QString>
#include <QStyleFactory>
#include <QWidget>

#include "gamescene.h"
#include "introductionscene.h"
#include "qtaquin.h"

/**
 * @brief The MainWindow class is the main window of the game.
 */
class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    /**
     * @brief MainWindow allows to create the main window of the game.
     * @param parent who will be in charge of its destruction.
     */
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    /**
     * @brief switchPage allows to change the page between the initialization page of the board and the game page.
     */
    void switchPage();

private:
    /**
     * @brief taquin the game that is represented in this window.
     */
    QTaquin* taquin;

    /**
     * @brief centralWidget the central widget of the main window that contains the QStackedLayout (the different pages).
     */
    QWidget* centralWidget;

    /**
     * @brief iScene the Introductory scene allowing the player to enter the size of the game board and the difficulty of the game.
     */
    IntroductionScene* iScene;

    /**
     * @brief gScene the Game scene to display it and play the game.
     */
    GameScene* gScene;

    /**
     * @brief switchPageIndex the current page index.
     */
    int switchPageIndex;

    /**
     * @brief actionNewGame allows to start a new game.
     */
    QAction* actionNewGame;

    /**
     * @brief actionQuit allows to quit the game.
     */
    QAction* actionQuit;

    /**
     * @brief actionNewImage allows to load a new image in the background of the cells.
     */
    QAction* actionNewImage;

    /**
     * @brief actionShowNumbers allows to show or hide the number on the cells.
     */
    QAction* actionShowNumbers;

    /**
     * @brief layout the layout that contains the two pages of the game.
     */
    QStackedLayout* layout;

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
     * @brief initMenuBar allows to initialize the menu bar.
     */
    void initMenuBar();
};

#endif // MAINWINDOW_H
