#include "mainwindow.h"
#include "endscene.h"
#include "gamescene.h"
#include "introductionscene.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    taquin = new QTaquin;

    setWindowTitle("Taquin");
    setFixedSize(450, 550);
    centralWidget = new QWidget();
    centralWidget->setObjectName("mainWindow");
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
    connect(taquin, &QTaquin::gameFinished, gScene, &GameScene::finalBoard);
    connect(taquin, &QTaquin::gameFinished, eScene, &EndScene::updateScore);
    connect(gScene, &GameScene::finalBoardDisplayed, this, &MainWindow::endGame);
    connect(eScene->restartButton(), &QPushButton::clicked, this, &MainWindow::restartGame);

    QFile styleFile(":/stylesheets/style");
    styleFile.open(QFile::ReadOnly);
    QString style(styleFile.readAll());
    qApp->setStyle(QStyleFactory::keys().at(2));
    qApp->setStyleSheet(style);
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
    //std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    layout->setCurrentIndex(2);
}

void MainWindow::restartGame()
{
    layout->setCurrentIndex(0);
}
