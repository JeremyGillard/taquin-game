#ifndef INTRODUCTIONLAYOUT_H
#define INTRODUCTIONLAYOUT_H

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "qtaquin.h"

class IntroductionLayout : public QWidget {
    Q_OBJECT
public:
    explicit IntroductionLayout(QTaquin& qTaquin, QWidget* parent = nullptr);

signals:
    void gameIsInitialized();

public slots:
    void initGame();

private:
    QTaquin* taquin;

    QGridLayout* userInformationLayout;
    QVBoxLayout* mainLayout;

    QLabel* initSizeBoardLbl;
    QComboBox* initSizeBoardCbb;
    QLabel* initDifficultyLbl;
    QComboBox* initDifficultyCbb;

    QLabel* title;
    QPushButton* startBtn;

    void initComponents();
    void initUserInformationLayout();
    void initMainLayout();
    void initBehavior();
};

#endif // INTRODUCTIONLAYOUT_H
