#include "mainwindow.h"
#include "endscene.h"
#include "gamescene.h"
#include "introductionscene.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    taquin = new QTaquin;

    setFixedSize(450, 550);
    centralWidget = new QWidget();
    layout = new QStackedLayout();
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    iScene = new IntroductionScene(*taquin);
    gScene = new GameScene(*taquin);
    eScene = new EndScene(*taquin);

    layout->addWidget(iScene);
    layout->addWidget(gScene);
    layout->addWidget(eScene);

    connect(iScene, &IntroductionScene::gameIsInitialized, this, &MainWindow::startGame);
    connect(iScene, &IntroductionScene::gameIsInitialized, gScene, &GameScene::initBoard);
    connect(taquin, &QTaquin::gameFinished, this, &MainWindow::endGame);
    connect(taquin, &QTaquin::gameFinished, eScene, &EndScene::updateScore);
    connect(eScene->restartButton(), &QPushButton::clicked, this, &MainWindow::restartGame);

    //initMenuBar();
    //menuBar()->hide();
}

MainWindow::~MainWindow()
{
}

void MainWindow::startGame()
{
    layout->setCurrentIndex(1);
    //menuBar()->show();
}

void MainWindow::endGame()
{
    layout->setCurrentIndex(2);
    //menuBar()->hide();
}

void MainWindow::restartGame()
{
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
