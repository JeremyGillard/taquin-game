#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , switchPageIndex(1)
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

    layout->addWidget(iScene);
    layout->addWidget(gScene);

    connect(iScene, &IntroductionScene::gameIsInitialized, this, &MainWindow::switchPage);
    connect(iScene, &IntroductionScene::gameIsInitialized, gScene, &GameScene::initBoard);
    connect(taquin, &QTaquin::gameFinished, gScene, &GameScene::finalBoard);
    connect(gScene, &GameScene::restartGame, this, &MainWindow::switchPage);

    QFile styleFile(":/stylesheets/style");
    styleFile.open(QFile::ReadOnly);
    QString style(styleFile.readAll());
    qApp->setStyle(QStyleFactory::keys().at(2));
    qApp->setStyleSheet(style);
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
