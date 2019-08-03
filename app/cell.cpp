#include <iostream>

#include "cell.h"

Cell::Cell(const QString& text, unsigned i, unsigned j, QTaquin& qTaquin, QWidget* parent)
    : QPushButton(text, parent)
    , taquin(&qTaquin)
    , m_i(i)
    , m_j(j)
{
    QPushButton::setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    behavior();
}

bool Cell::operator==(const Cell& cell) const
{
    return (m_i == cell.m_i) && (m_j == cell.m_j);
}

void Cell::behavior()
{
    connect(this, &Cell::clicked, this, [&]() { taquin->moveCellBoard(m_i, m_j); });
}
