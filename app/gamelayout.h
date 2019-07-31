#ifndef GAMELAYOUT_H
#define GAMELAYOUT_H

#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#include "cell.h"
#include "qtaquin.h"

class GameLayout : public QWidget {
    Q_OBJECT
public:
    explicit GameLayout(QTaquin& qTaquin, QWidget* parent = nullptr);

signals:

public slots:
    void initBoard();
    void updateBoard();

private:
    QTaquin* taquin;

    QGridLayout* board;
    QVBoxLayout* layout;

    QLabel* progressLbl;

    std::pair<unsigned, unsigned> zeroCoord;

    void removeCells();
};

#endif // GAMELAYOUT_H
