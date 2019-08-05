#ifndef QTAQUIN_H
#define QTAQUIN_H

#include <QObject>

#include "taquin.h"

class QTaquin : public QObject, public Taquin {
    Q_OBJECT
public:
    explicit QTaquin(QObject* parent = nullptr);
    void moveCellBoard(unsigned i, unsigned j);

signals:
    void boardChanged();
    void gameFinished();
};

#endif // QTAQUIN_H
