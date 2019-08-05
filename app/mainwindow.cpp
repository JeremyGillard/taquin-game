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
        switchPageIndex = 0;
    } else {
        ++switchPageIndex;
    }
}

void MainWindow::initComponents()
{
    setWindowTitle("Taquin");
    setFixedSize(450, 550);
    centralWidget = new QWidget(this);
    centralWidget->setObjectName("mainWindow");
    taquin = new QTaquin;
    layout = new QStackedLayout;
    iScene = new IntroductionScene(*taquin);
    gScene = new GameScene(*taquin);
    QFile styleFile(":/stylesheets/style");
    styleFile.open(QFile::ReadOnly);
    QString style(styleFile.readAll());
    qApp->setStyle(QStyleFactory::keys().at(2));
    qApp->setStyleSheet(style);
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
    connect(gScene, &GameScene::restartGame, this, &MainWindow::switchPage);
}
