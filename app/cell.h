#ifndef CELL_H
#define CELL_H

#include <QPainter>
#include <QPushButton>

#include "qtaquin.h"

class Cell : public QPushButton {
    Q_OBJECT

public:
    Cell(const QString& text, const QPixmap& imgFragment, unsigned i, unsigned j, QTaquin& qTaquin, QWidget* parent = nullptr);
    bool operator==(const Cell& cell) const;
    void setImgFragment(const QPixmap& pm);

signals:

public slots:
    void paintEvent(QPaintEvent*);

private:
    QTaquin* taquin;

    unsigned m_i;
    unsigned m_j;

    QPixmap m_imgFragment;

    void behavior();
};

#endif // CELL_H
