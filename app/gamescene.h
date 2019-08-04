#ifndef GAMELAYOUT_H
#define GAMELAYOUT_H

#include <QGridLayout>
#include <QLabel>
#include <QList>
#include <QPixmap>
#include <QVBoxLayout>
#include <QWidget>
#include <cstdlib>
#include <ctime>

#include "cell.h"
#include "qtaquin.h"

class GameScene : public QWidget {
    Q_OBJECT
public:
    explicit GameScene(QTaquin& qTaquin, QWidget* parent = nullptr);

signals:

public slots:
    void initBoard();
    void updateBoard();

private:
    QTaquin* taquin;

    QGridLayout* board;
    QVBoxLayout* layout;

    QLabel* progressLbl;
    QWidget* boardW;

    void initComponents();
    void arrangement();
    void reInit();
    void behavior();

    QList<QPixmap> imgFragments;

    void createImgFragments();
    QPixmap loadRandomImg();
};

#endif // GAMELAYOUT_H
