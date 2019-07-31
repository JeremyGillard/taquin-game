#include "introductionlayout.h"

IntroductionLayout::IntroductionLayout(QTaquin& qTaquin, QWidget* parent)
    : QWidget(parent)
    , taquin(&qTaquin)
{
    initComponents();
    initUserInformationLayout();
    initMainLayout();
    initBehavior();
}

void IntroductionLayout::initGame()
{
    taquin->initBoard(static_cast<unsigned>(initSizeBoardCbb->currentData().toInt()));
    taquin->start(static_cast<unsigned>(initDifficultyCbb->currentData().toInt()));
    emit gameIsInitialized();
}

void IntroductionLayout::initComponents()
{
    initSizeBoardLbl = new QLabel("Size of the board");
    initSizeBoardCbb = new QComboBox();
    for (unsigned i = 3; i < 6; ++i)
        initSizeBoardCbb->addItem(QString::number(i), i);
    initDifficultyLbl = new QLabel("Difficulty level");
    initDifficultyCbb = new QComboBox();
    for (unsigned i = 1; i < 11; ++i)
        initDifficultyCbb->addItem(QString::number(i), i);

    title = new QLabel("Taquin");
    startBtn = new QPushButton("Start");
}

void IntroductionLayout::initUserInformationLayout()
{
    userInformationLayout = new QGridLayout;
    userInformationLayout->addWidget(initSizeBoardLbl, 0, 0);
    userInformationLayout->addWidget(initSizeBoardCbb, 0, 1);
    userInformationLayout->addWidget(initDifficultyLbl, 1, 0);
    userInformationLayout->addWidget(initDifficultyCbb, 1, 1);
}

void IntroductionLayout::initMainLayout()
{
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(title);
    mainLayout->addLayout(userInformationLayout);
    mainLayout->addWidget(startBtn);
    setLayout(mainLayout);
}

void IntroductionLayout::initBehavior()
{
    connect(startBtn, &QPushButton::clicked, this, &IntroductionLayout::initGame);
}
