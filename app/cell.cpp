#include <iostream>

#include "cell.h"

Cell::Cell(const QString& text, const QPixmap& imgFragment, unsigned i, unsigned j, QTaquin& qTaquin, QWidget* parent)
    : QPushButton(text, parent)
    , taquin(&qTaquin)
    , m_i(i)
    , m_j(j)
    , m_imgFragment(imgFragment)
{
    QPushButton::setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setMinimumSize(400 / taquin->chosenSize(), 400 / taquin->chosenSize());
    behavior();
}

bool Cell::operator==(const Cell& cell) const
{
    return (m_i == cell.m_i) && (m_j == cell.m_j);
}

void Cell::setImgFragment(const QPixmap& pm)
{
    m_imgFragment = pm;
}

void Cell::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_imgFragment);
    painter.setPen(Qt::gray);
    painter.setFont(QFont("Tahoma", 24));
    painter.drawText(rect(), Qt::AlignCenter, this->text());
}

void Cell::behavior()
{
    connect(this, &Cell::clicked, this, [&]() { taquin->moveCellBoard(m_i, m_j); });
}
