#ifndef CELL_H
#define CELL_H

#include <QPainter>
#include <QPushButton>

#include "qtaquin.h"

/**
 * @brief The Cell class represent a cell of the board of the game Taquin.
 */
class Cell : public QPushButton {

    Q_OBJECT

public:
    /**
     * @brief Cell create a cell with a text, a background image fragment, an i and j coordinates, an a Taquin model.
     * @param text the text that will be displayed on the cell.
     * @param imgFragment the image that will be displayed on the cell
     * @param i the i coordinate.
     * @param j the j coordinate.
     * @param qTaquin the model whose cell represents a fragment of the game board.
     * @param parent parent who will be in charge of its destruction.
     */
    Cell(const QString& text, const QPixmap& imgFragment, unsigned i, unsigned j, QTaquin& qTaquin, QWidget* parent = nullptr);

    /**
     * @brief setBackgroundImg allows to change the background image of the cell.
     * @param pm the new image to set to the background.
     */
    void setBackgroundImg(const QPixmap& pm);

public slots:
    /**
     * @brief paintEvent allows to customize the appearance of the cell.
     */
    void paintEvent(QPaintEvent*);

private:
    /**
     * @brief taquin the model whose cell represents a fragment of the game board.
     */
    QTaquin* taquin;

    /**
     * @brief m_i the i coordinate of the cell.
     */
    unsigned m_i;

    /**
     * @brief m_j the j coordinate of the cell.
     */
    unsigned m_j;

    /**
     * @brief m_imgFragment the image fragment that will be displayed on the cell.
     */
    QPixmap m_imgFragment;

    /**
     * @brief arrangement correctly arranges the elements of the window.
     */
    void arrangement();

    /**
     * @brief behavior determines the behavior of the elements contained in the window.
     */
    void behavior();
};

#endif // CELL_H
