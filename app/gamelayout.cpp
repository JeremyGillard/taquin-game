#include <QDebug>
#include <QLabel>
#include <QLayoutItem>

#include "gamelayout.h"

GameLayout::GameLayout(QTaquin& qTaquin, QWidget* parent)
    : QWidget(parent)
    , taquin(&qTaquin)
{
    board = new QGridLayout;
    setLayout(board);

    connect(taquin, &QTaquin::boardChanged, this, &GameLayout::updateBoard);
}

void GameLayout::initBoard()
{
    unsigned boardSize = taquin->chosenSize();
    for (unsigned i = 0; i < boardSize; ++i) {
        for (unsigned j = 0; j < boardSize; ++j) {
            board->addWidget(new Cell(QString::number(taquin->getCellAt(i, j)), i, j, *taquin), static_cast<int>(i), static_cast<int>(j));
            if (taquin->getCellAt(i, j) == 0) {
                board->itemAtPosition(i, j)->widget()->hide();
                zeroCoord = std::make_pair(i, j);
            }
        }
    }
}

void GameLayout::updateBoard()
{
    unsigned boardSize = taquin->chosenSize();
    for (unsigned i = 0; i < boardSize; ++i) {
        for (unsigned j = 0; j < boardSize; ++j) {
            Cell* cell = qobject_cast<Cell*>(board->itemAtPosition(i, j)->widget());
            cell->setText(QString::number(taquin->getCellAt(i, j)));
            if (cell->isHidden())
                cell->show();
            if (taquin->getCellAt(i, j) == 0) {
                board->itemAtPosition(i, j)->widget()->hide();
                zeroCoord = std::make_pair(i, j);
            }
        }
    }
}
