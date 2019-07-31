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
    eLayout = new EndLayout(*taquin);

    layout->addWidget(iLayout);
    layout->addWidget(gLayout);
    layout->addWidget(eLayout);

    connect(iLayout, &IntroductionLayout::gameIsInitialized, this, &MainWindow::startGame);
    connect(iLayout, &IntroductionLayout::gameIsInitialized, gLayout, &GameLayout::initBoard);
    connect(taquin, &QTaquin::gameFinished, this, &MainWindow::endGame);

    initMenuBar();
    menuBar()->hide();
}

MainWindow::~MainWindow()
{
}

void MainWindow::startGame()
{
    layout->setCurrentIndex(1);
    menuBar()->show();
}

void MainWindow::endGame()
{
    layout->setCurrentIndex(2);
    menuBar()->hide();
}

void MainWindow::restartGame()
{
    delete taquin;
    taquin = new QTaquin;
    layout->setCurrentIndex(0);
}

void MainWindow::initMenuBar()
{
    QMenu* menuTaquin = menuBar()->addMenu("Taquin");

    QAction* actionNew = new QAction("New Game", this);
    connect(actionNew, &QAction::triggered, this, &MainWindow::restartGame);
    QAction* actionQuit = new QAction("Quit", this);
    connect(actionQuit, &QAction::triggered, qApp, &QApplication::quit);
    menuTaquin->addAction(actionNew);
    menuTaquin->addAction(actionQuit);

    QMenu* menuView = menuBar()->addMenu("View");
    QAction* actionNumberVisibility = new QAction("Show Number", this);
    QAction* actionImageVisibility = new QAction("Show Image", this);
    QAction* actionChangeImage = new QAction("Change Image", this);
    menuView->addAction(actionNumberVisibility);
    actionNumberVisibility->setCheckable(true);
    actionImageVisibility->setCheckable(true);
    menuView->addAction(actionImageVisibility);
    menuView->addAction(actionChangeImage);

    QMenu* menuAbout = menuBar()->addMenu("About");

    QAction* actionRules = new QAction("Rules", this);
    QAction* actionTheory = new QAction("Theory", this);
    menuAbout->addAction(actionRules);
    menuAbout->addAction(actionTheory);

    actionNumberVisibility->setChecked(true);
    actionChangeImage->setEnabled(false);
    connect(actionImageVisibility, &QAction::toggled, actionChangeImage, &QAction::setEnabled);
}
