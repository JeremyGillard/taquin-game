#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStackedLayout>
#include <QString>
#include <QStyleFactory>
#include <QWidget>

#include "gamescene.h"
#include "introductionscene.h"
#include "qtaquin.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void switchPage();

private:
    QTaquin* taquin;
    QWidget* centralWidget;
    IntroductionScene* iScene;
    GameScene* gScene;
    int switchPageIndex;

    QStackedLayout* layout;

    void initComponents();
    void arrangement();
    void behavior();
};

#endif // MAINWINDOW_H
