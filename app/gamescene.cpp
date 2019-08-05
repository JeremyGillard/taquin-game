#include "gamescene.h"

GameScene::GameScene(QTaquin& qTaquin, QWidget* parent)
    : QWidget(parent)
    , taquin(&qTaquin)
{
    initComponents();
    arrangement();
    restartBtn = new QPushButton("Restart");
    behavior();
    srand(unsigned(time(nullptr)));
    loadRandomImg();
}

void GameScene::initBoard()
{
    clearComponents();
    createImgFragments();
    unsigned boardSize = taquin->chosenSize();
    for (unsigned i = 0; i < boardSize; ++i) {
        for (unsigned j = 0; j < boardSize; ++j) {
            int cellNumber = static_cast<int>(taquin->getCellAt(i, j));
            board->addWidget(new Cell(QString::number(cellNumber), imgFragments.at(cellNumber), i, j, *taquin, boardW), static_cast<int>(i), static_cast<int>(j));
            if (taquin->getCellAt(i, j) == 0) {
                board->itemAtPosition(static_cast<int>(i), static_cast<int>(j))->widget()->hide();
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
            Cell* cell = qobject_cast<Cell*>(board->itemAtPosition(static_cast<int>(i), static_cast<int>(j))->widget());
            cell->setImgFragment(imgFragments.at(cellNumber));
            cell->setText(QString::number(cellNumber));
            if (cell->isHidden()) {
                cell->show();
            }
            if (!taquin->isOver() && taquin->getCellAt(i, j) == 0) {
                board->itemAtPosition(static_cast<int>(i), static_cast<int>(j))->widget()->hide();
            }
            if (taquin->isOver()) {
                cell->setText("");
            }
        }
    }
    progressLbl->setText("Number of moves : " + QString::number(taquin->getNumberOfMoves()));
}

void GameScene::finalBoard()
{
    updateBoard();
    layout->addWidget(restartBtn);
}

void GameScene::initComponents()
{
    board = new QGridLayout;
    board->setSpacing(0);
    boardW = new QWidget;
    layout = new QVBoxLayout;
    layout->setAlignment(Qt::AlignCenter);
    progressLbl = new QLabel("Number of moves : 0");
    progressLbl->setAlignment(Qt::AlignCenter);
}

void GameScene::arrangement()
{
    setLayout(layout);
    boardW->setLayout(board);
    boardW->setObjectName("board");
    layout->addWidget(boardW);
    layout->addWidget(progressLbl);
    layout->setSpacing(15);
}

void GameScene::clearComponents()
{
    if (boardW != nullptr) {
        delete board;
        delete boardW;
        delete layout;
        delete progressLbl;
        initComponents();
        arrangement();
    }
}

void GameScene::behavior()
{
    connect(taquin, &QTaquin::boardChanged, this, &GameScene::updateBoard);
    connect(restartBtn, &QPushButton::clicked, this, &GameScene::restartGame);
}

void GameScene::showNumbers()
{
}

void GameScene::createImgFragments()
{
    if (imgFragments.size() != 0) {
        imgFragments.clear();
    }
    loadRandomImg();
    int boardSize = static_cast<int>(taquin->chosenSize());
    int fragmentSize = currentImg.height() / boardSize;

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            int size1 = i * fragmentSize;
            int size2 = j * fragmentSize;
            imgFragments.push_back(currentImg.copy(size2, size1, fragmentSize, fragmentSize));
        }
    }
    imgFragments.push_front(imgFragments.takeLast());
}

void GameScene::loadRandomImg()
{
    unsigned chosenImg = rand() % 4;
    currentImg = QPixmap(":/img/img" + QString::number(chosenImg));
}
