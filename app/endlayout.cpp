#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "endlayout.h"

EndLayout::EndLayout(QTaquin& qTaquin, QWidget* parent)
    : QWidget(parent)
    , taquin(&qTaquin)
{
    layout = new QVBoxLayout(this);
    setLayout(layout);
    endLbl = new QLabel("Congratulation!\n You finish this taquin in " + QString::number(taquin->getNumberOfMoves()) + " moves");
    layout->addWidget(endLbl);
    restartBtn = new QPushButton("Restart");
    layout->addWidget(restartBtn);
}
