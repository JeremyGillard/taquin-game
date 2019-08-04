#ifndef ENDLAYOUT_H
#define ENDLAYOUT_H

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "qtaquin.h"

class EndScene : public QWidget {
    Q_OBJECT
public:
    explicit EndScene(QTaquin& qTaquin, QWidget* parent = nullptr);
    const QPushButton* restartButton() const;

signals:

public slots:
    void updateScore();

private:
    QTaquin* taquin;
    QLabel* endLbl;
    QLabel* resultLbl;
    QPushButton* restartBtn;

    QVBoxLayout* layout;

    void initComponents();
    void arrangement();
};

#endif // ENDLAYOUT_H
