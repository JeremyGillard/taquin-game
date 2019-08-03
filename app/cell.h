#ifndef CELL_H
#define CELL_H

#include <QPushButton>

#include "qtaquin.h"

class Cell : public QPushButton {
    Q_OBJECT

public:
    Cell(const QString& text, unsigned i, unsigned j, QTaquin& qTaquin, QWidget* parent = nullptr);
    bool operator==(const Cell& cell) const;

signals:

public slots:

private:
    QTaquin* taquin;

    unsigned m_i;
    unsigned m_j;

    void behavior();
};

#endif // CELL_H
