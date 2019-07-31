#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedLayout>
#include <QWidget>

#include "endlayout.h"
#include "gamelayout.h"
#include "introductionlayout.h"
#include "qtaquin.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();

public slots:
    void startGame();
    void endGame();

private:
    QTaquin* taquin = nullptr;

    QWidget* centralWidget;
    QStackedLayout* layout;

    IntroductionLayout* iLayout;
    GameLayout* gLayout;
    EndLayout* eLayout;
};

#endif // MAINWINDOW_H
