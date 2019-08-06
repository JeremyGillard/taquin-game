#ifndef QTAQUIN_H
#define QTAQUIN_H

#include <QObject>

#include "taquin.h"

/**
 * @brief The QTaquin class is a representation of the teasing game adapted to the signal/slots the qt features.
 * This class implements only a few more things than the model and simply inherits most of these methods and attributes.
 */
class QTaquin : public QObject, public Taquin {

    Q_OBJECT

public:
    /**
     * @brief QTaquin allows to create a Taquin modele with qt features.
     * @param parent the parent of the QTaquin instance.
     * The new class is deleted when its parent is deleted..
     */
    explicit QTaquin(QObject* parent = nullptr);

    /**
     * @brief allows you to move a cell on the game board within the limits of the available movements.
     * It will emit a boardChanged signal if the coordinates are validated and a gameFinished signal if the game is over.
     * @param i i coordinate of the cell to move.
     * @param j j coordinate of the cell to move.
     */
    void moveCellBoard(unsigned i, unsigned j);

signals:
    /**
     * @brief boardChanged is a signal that warns that the layout of the game board has changed.
     */
    void boardChanged();

    /**
     * @brief gameFinished is a signal emitted when the game is over.
     */
    void gameFinished();
};

#endif // QTAQUIN_H
