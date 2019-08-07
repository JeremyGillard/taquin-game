#include "introductionscene.h"

IntroductionScene::IntroductionScene(QTaquin& qTaquin, QWidget* parent)
    : QWidget(parent)
    , taquin(&qTaquin)
{
    initComponents();
    arrangement();
    behavior();
}

void IntroductionScene::initGame()
{
    taquin->initBoard(static_cast<unsigned>(initSizeBoardCbb->currentData().toInt()));
    taquin->start(static_cast<unsigned>(initDifficultyCbb->currentData().toInt()));
    emit gameIsInitialized();
}

void IntroductionScene::initComponents()
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
    title->setObjectName("title");
    startBtn = new QPushButton("Start");
    startBtn->setProperty("evilButton", true);

    userInformationLayout = new QGridLayout;
    mainLayout = new QVBoxLayout;
}

void IntroductionScene::arrangement()
{
    initUserInformationLayout();
    mainLayout->addWidget(title);
    mainLayout->addLayout(userInformationLayout);
    mainLayout->addWidget(startBtn);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->setSpacing(20);
    setLayout(mainLayout);
}

void IntroductionScene::behavior()
{
    connect(startBtn, &QPushButton::clicked, this, &IntroductionScene::initGame);
}

void IntroductionScene::initUserInformationLayout()
{
    userInformationLayout->addWidget(initSizeBoardLbl, 0, 0);
    userInformationLayout->addWidget(initSizeBoardCbb, 0, 1);
    userInformationLayout->addWidget(initDifficultyLbl, 1, 0);
    userInformationLayout->addWidget(initDifficultyCbb, 1, 1);
}
