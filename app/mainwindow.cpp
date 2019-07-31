#include "mainwindow.h"
#include "endlayout.h"
#include "gamelayout.h"
#include "introductionlayout.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    taquin = new QTaquin;

    setFixedSize(450, 600);
    centralWidget = new QWidget();
    layout = new QStackedLayout();
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    iLayout = new IntroductionLayout(*taquin);
    gLayout = new GameLayout(*taquin);
    eLayout = new EndLayout;

    layout->addWidget(iLayout);
    layout->addWidget(gLayout);
    layout->addWidget(eLayout);

    connect(iLayout, &IntroductionLayout::gameIsInitialized, this, &MainWindow::startGame);
    connect(iLayout, &IntroductionLayout::gameIsInitialized, gLayout, &GameLayout::initBoard);
    connect(taquin, &QTaquin::gameFinished, this, &MainWindow::endGame);
}

MainWindow::~MainWindow()
{
}

void MainWindow::startGame()
{
    layout->setCurrentIndex(1);
}

void MainWindow::endGame()
{
    layout->setCurrentIndex(2);
}
