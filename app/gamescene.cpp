#include <QDebug>
#include <QLabel>
#include <QLayoutItem>

#include "gamescene.h"

GameScene::GameScene(QTaquin& qTaquin, QWidget* parent)
    : QWidget(parent)
    , taquin(&qTaquin)
{
    initComponents();
    arrangement();
    behavior();
}

void GameScene::initBoard()
{
    reInit();
    unsigned boardSize = taquin->chosenSize();
    for (unsigned i = 0; i < boardSize; ++i) {
        for (unsigned j = 0; j < boardSize; ++j) {
            board->addWidget(new Cell(QString::number(taquin->getCellAt(i, j)), i, j, *taquin, boardW), static_cast<int>(i), static_cast<int>(j));
            if (taquin->getCellAt(i, j) == 0) {
                board->itemAtPosition(static_cast<int>(i), static_cast<int>(j))->widget()->hide();
            }
        }
    }
}

void GameScene::updateBoard()
{
    unsigned boardSize = taquin->chosenSize();
    for (unsigned i = 0; i < boardSize; ++i) {
        for (unsigned j = 0; j < boardSize; ++j) {
            Cell* cell = qobject_cast<Cell*>(board->itemAtPosition(static_cast<int>(i), static_cast<int>(j))->widget());
            cell->setText(QString::number(taquin->getCellAt(i, j)));
            if (cell->isHidden())
                cell->show();
            if (taquin->getCellAt(i, j) == 0) {
                board->itemAtPosition(static_cast<int>(i), static_cast<int>(j))->widget()->hide();
            }
        }
    }
    progressLbl->setText("Number of moves : " + QString::number(taquin->getNumberOfMoves()));
}

void GameScene::initComponents()
{
    board = new QGridLayout;
    boardW = new QWidget;
    layout = new QVBoxLayout;
    progressLbl = new QLabel("Number of moves : 0");
}

void GameScene::arrangement()
{
    setLayout(layout);
    boardW->setLayout(board);
    layout->addWidget(boardW);
    layout->addWidget(progressLbl);
}

void GameScene::reInit()
{
    if (boardW != nullptr) {
        delete board;
        delete boardW;
        delete layout;
        delete progressLbl;
        initComponents();
        arrangement();
    }
}

void GameScene::behavior()
{
    connect(taquin, &QTaquin::boardChanged, this, &GameScene::updateBoard);
}
