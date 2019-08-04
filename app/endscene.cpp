#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "endscene.h"
#include "mainwindow.h"

EndScene::EndScene(QTaquin& qTaquin, QWidget* parent)
    : QWidget(parent)
    , taquin(&qTaquin)
{
    initComponents();
    arrangement();
}

void EndScene::updateScore()
{
    resultLbl->setText("You finish this taquin in " + QString::number(taquin->getNumberOfMoves()) + " moves");
}

void EndScene::initComponents()
{
    layout = new QVBoxLayout(this);
    endLbl = new QLabel("Congratulation!");
    resultLbl = new QLabel("You finish this taquin in 0 moves");
    restartBtn = new QPushButton("Restart");
}

void EndScene::arrangement()
{
    setLayout(layout);
    layout->addWidget(endLbl);
    layout->addWidget(resultLbl);
    layout->addWidget(restartBtn);
    layout->setAlignment(Qt::AlignCenter);
    layout->setSpacing(15);
}

const QPushButton* EndScene::restartButton() const
{
    return restartBtn;
}
