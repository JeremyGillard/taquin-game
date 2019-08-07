#include "gamescene.h"

GameScene::GameScene(QTaquin& qTaquin, QWidget* parent)
    : QWidget(parent)
    , taquin(&qTaquin)
    , numberVisible(true)
{
    initComponents();
    arrangement();
    behavior();
    srand(unsigned(time(nullptr)));
    loadImages();
}

void GameScene::initBoard()
{
    clearComponents();
    pickRandomImage();
    createImgFragments();
    unsigned boardSize = taquin->chosenSize();
    for (unsigned i = 0; i < boardSize; ++i) {
        for (unsigned j = 0; j < boardSize; ++j) {
            int cellNumber = static_cast<int>(taquin->getCellAt(i, j));
            boardLayout->addWidget(new Cell(QString::number(cellNumber), imgFragments.at(cellNumber), i, j, *taquin, boardWidget),
                static_cast<int>(i), static_cast<int>(j));
            if (taquin->getCellAt(i, j) == 0) {
                boardLayout->itemAtPosition(static_cast<int>(i), static_cast<int>(j))->widget()->hide();
            }
        }
    }
}

void GameScene::updateBoard()
{
    unsigned boardSize = taquin->chosenSize();
    for (unsigned i = 0; i < boardSize; ++i) {
        for (unsigned j = 0; j < boardSize; ++j) {
            int cellNumber = static_cast<int>(taquin->getCellAt(i, j));
            Cell* cell = qobject_cast<Cell*>(boardLayout->itemAtPosition(static_cast<int>(i), static_cast<int>(j))->widget());
            cell->setBackgroundImg(imgFragments.at(cellNumber));
            cell->repaint();
            cell->setText(QString::number(cellNumber));
            if (cell->isHidden()) {
                cell->show();
            }
            if (!taquin->isOver() && taquin->getCellAt(i, j) == 0) {
                boardLayout->itemAtPosition(static_cast<int>(i), static_cast<int>(j))->widget()->hide();
            }
            if (taquin->isOver() || !numberVisible) {
                cell->setText("");
            }
        }
    }
    progressLbl->setText("Number of moves : " + QString::number(taquin->getNumberOfMoves()));
}

void GameScene::finalBoard()
{
    updateBoard();
}

void GameScene::newGame()
{
    if (!taquin->isOver()) {
        int response = QMessageBox::question(this, "New game confirm?",
            "Are you sure you want to start a new game without having finished the current one?",
            QMessageBox ::Yes | QMessageBox::No);
        if (response == QMessageBox::Yes) {
            emit newGameConfirmation();
        }
    } else {
        emit newGameConfirmation();
    }
}

void GameScene::newImage()
{
    pickRandomImage();
    createImgFragments();
    updateBoard();
}

void GameScene::showNumbers()
{
    if (numberVisible) {
        numberVisible = false;
    } else {
        numberVisible = true;
    }
    updateBoard();
}

void GameScene::initComponents()
{
    boardLayout = new QGridLayout;
    boardLayout->setSpacing(0);
    boardWidget = new QWidget;
    mainLayout = new QVBoxLayout;
    mainLayout->setAlignment(Qt::AlignCenter);
    progressLbl = new QLabel("Number of moves : 0");
    newGameBtn = new QPushButton("New Game");
    progressLbl->setAlignment(Qt::AlignCenter);
}

void GameScene::arrangement()
{
    setLayout(mainLayout);
    boardWidget->setLayout(boardLayout);
    boardWidget->setObjectName("board");
    mainLayout->addWidget(boardWidget);
    mainLayout->addWidget(progressLbl);
    mainLayout->addWidget(newGameBtn);
    mainLayout->setSpacing(15);
}

void GameScene::behavior()
{
    connect(taquin, &QTaquin::boardChanged, this, &GameScene::updateBoard);
    connect(newGameBtn, &QPushButton::clicked, this, &GameScene::newGame);
}

void GameScene::clearComponents()
{
    progressLbl->setText("Number of moves : 0");
    QLayoutItem* child;
    while ((child = boardLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
}

void GameScene::createImgFragments()
{
    if (imgFragments.size() != 0) {
        imgFragments.clear();
    }
    int boardSize = static_cast<int>(taquin->chosenSize());
    int fragmentSize = currentImg->height() / boardSize;

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            int size1 = i * fragmentSize;
            int size2 = j * fragmentSize;
            imgFragments.push_back(currentImg->copy(size2, size1, fragmentSize, fragmentSize));
        }
    }
    imgFragments.push_front(imgFragments.takeLast());
}

void GameScene::loadImages()
{
    for (int i = 0; i < 9; ++i) {
        imgGalery.push_back(QPixmap(":/img/img" + QString::number(i)));
    }
}

void GameScene::pickRandomImage()
{
    unsigned chosenImg = rand() % 9;
    currentImg = imgGalery.begin() + chosenImg;
}
