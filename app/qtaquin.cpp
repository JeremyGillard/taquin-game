#include "qtaquin.h"

QTaquin::QTaquin(QObject* parent)
    : QObject(parent)
    , Taquin()
{
}

void QTaquin::moveCellBoard(unsigned i, unsigned j)
{
    Taquin::moveCellBoard(i, j);
    if (Taquin::isOver())
        emit gameFinished();
    emit boardChanged();
}
