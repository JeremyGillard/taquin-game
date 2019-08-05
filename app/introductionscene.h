#ifndef INTRODUCTIONLAYOUT_H
#define INTRODUCTIONLAYOUT_H

#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "qtaquin.h"

class IntroductionScene : public QWidget {
    Q_OBJECT
public:
    explicit IntroductionScene(QTaquin& qTaquin, QWidget* parent = nullptr);

signals:
    void gameIsInitialized();

public slots:
    void initGame();

private:
    QTaquin* taquin;
    QLabel* initSizeBoardLbl;
    QComboBox* initSizeBoardCbb;
    QLabel* initDifficultyLbl;
    QComboBox* initDifficultyCbb;
    QLabel* title;
    QPushButton* startBtn;

    QGridLayout* userInformationLayout;
    QVBoxLayout* mainLayout;

    void initComponents();
    void arrangement();
    void behavior();
    void initUserInformationLayout();
};

#endif // INTRODUCTIONLAYOUT_H
