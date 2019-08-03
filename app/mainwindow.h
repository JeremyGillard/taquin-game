#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QDebug>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStackedLayout>
#include <QWidget>

#include "endscene.h"
#include "gamescene.h"
#include "introductionscene.h"
#include "qtaquin.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void startGame();
    void endGame();
    void restartGame();

private:
    QTaquin* taquin = nullptr;

    QWidget* centralWidget;
    QStackedLayout* layout;

    IntroductionScene* iScene;
    GameScene* gScene;
    EndScene* eScene;

    void initMenuBar();
};

#endif // MAINWINDOW_H
