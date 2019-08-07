#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , switchPageIndex(1)
{
    initComponents();
    arrangement();
    behavior();
}

MainWindow::~MainWindow()
{
}

void MainWindow::switchPage()
{
    layout->setCurrentIndex(switchPageIndex);
    if (switchPageIndex) {
        menuBar()->show();
        switchPageIndex = 0;
    } else {
        menuBar()->hide();
        ++switchPageIndex;
    }
}

void MainWindow::initComponents()
{
    setWindowTitle("Taquin");
    setFixedSize(500, 600);
    centralWidget = new QWidget(this);
    centralWidget->setObjectName("mainWindow");
    taquin = new QTaquin(this);
    layout = new QStackedLayout;
    iScene = new IntroductionScene(*taquin, this);
    gScene = new GameScene(*taquin, this);
    QFile styleFile(":/stylesheets/style");
    styleFile.open(QFile::ReadOnly);
    QString style(styleFile.readAll());
    qApp->setStyle(QStyleFactory::keys().at(2));
    qApp->setStyleSheet(style);
    initMenuBar();
}

void MainWindow::arrangement()
{
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    layout->addWidget(iScene);
    layout->addWidget(gScene);
}

void MainWindow::behavior()
{
    connect(iScene, &IntroductionScene::gameIsInitialized, this, &MainWindow::switchPage);
    connect(iScene, &IntroductionScene::gameIsInitialized, gScene, &GameScene::initBoard);
    connect(taquin, &QTaquin::gameFinished, gScene, &GameScene::finalBoard);
    connect(gScene, &GameScene::newGameConfirmation, this, &MainWindow::switchPage);
    connect(actionNewGame, &QAction::triggered, gScene, &GameScene::newGame);
    connect(actionQuit, &QAction::triggered, qApp, &QApplication::quit);
    connect(actionNewImage, &QAction::triggered, gScene, &GameScene::newImage);
    connect(actionShowNumbers, &QAction::triggered, gScene, &GameScene::showNumbers);
}

void MainWindow::initMenuBar()
{
    QMenu* menuTaquin = menuBar()->addMenu("Taquin");
    actionNewGame = new QAction("New Game", this);
    actionQuit = new QAction("Quit", this);
    menuTaquin->addAction(actionNewGame);
    menuTaquin->addAction(actionQuit);

    QMenu* menuView = menuBar()->addMenu("View");
    actionNewImage = new QAction("New Image", this);
    actionShowNumbers = new QAction("Show Numbers", this);
    actionShowNumbers->setCheckable(true);
    actionShowNumbers->setChecked(true);
    menuView->addAction(actionNewImage);
    menuView->addAction(actionShowNumbers);
    menuBar()->hide();
}
