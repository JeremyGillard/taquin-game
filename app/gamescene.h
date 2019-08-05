#ifndef GAMELAYOUT_H
#define GAMELAYOUT_H

#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QList>
#include <QPixmap>
#include <QVBoxLayout>
#include <QWidget>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <thread>

#include "cell.h"
#include "qtaquin.h"

class GameScene : public QWidget {
    Q_OBJECT
public:
    explicit GameScene(QTaquin& qTaquin, QWidget* parent = nullptr);

signals:
    void finalBoardDisplayed();
    void restartGame();

public slots:
    void initBoard();
    void updateBoard();
    void finalBoard();

private:
    QTaquin* taquin;
    QLabel* progressLbl;
    QWidget* boardW;
    QPushButton* restartBtn;
    QList<QPixmap> imgFragments;
    QPixmap currentImg;

    QGridLayout* board;
    QVBoxLayout* layout;

    void initComponents();
    void arrangement();
    void clearComponents();
    void behavior();
    void showNumbers();
    void createImgFragments();
    void loadRandomImg();
};

#endif // GAMELAYOUT_H
