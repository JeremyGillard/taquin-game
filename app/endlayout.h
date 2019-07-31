#ifndef ENDLAYOUT_H
#define ENDLAYOUT_H

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "qtaquin.h"

class EndLayout : public QWidget {
    Q_OBJECT
public:
    explicit EndLayout(QTaquin& qTaquin, QWidget* parent = nullptr);

signals:

public slots:

private:
    QTaquin* taquin;

    QVBoxLayout* layout;

    QLabel* endLbl;
    QPushButton* restartBtn;
};

#endif // ENDLAYOUT_H
