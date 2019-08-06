#include "cell.h"

const int IMAGE_SIZE = 400;
const int FONT_SIZE = 24;
const QString FONT_FAMILLY = "Tahoma";

Cell::Cell(const QString& text, const QPixmap& imgFragment, unsigned i, unsigned j, QTaquin& qTaquin, QWidget* parent)
    : QPushButton(text, parent)
    , taquin(&qTaquin)
    , m_i(i)
    , m_j(j)
    , m_imgFragment(imgFragment)
{
    arrangement();
    behavior();
}

void Cell::setBackgroundImg(const QPixmap& pm)
{
    m_imgFragment = pm;
}

void Cell::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, m_imgFragment);
    painter.setPen(Qt::white);
    painter.setFont(QFont(FONT_FAMILLY, FONT_SIZE));
    painter.drawText(rect(), Qt::AlignCenter, this->text());
}

void Cell::arrangement()
{
    QPushButton::setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setMinimumSize(IMAGE_SIZE / taquin->chosenSize(), IMAGE_SIZE / taquin->chosenSize());
}

void Cell::behavior()
{
    connect(this, &Cell::clicked, this, [&]() {
        if (!taquin->isOver()) {
            taquin->moveCellBoard(m_i, m_j);
        }
    });
}
