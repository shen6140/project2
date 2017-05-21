#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include "novice.h"
#include "magican.h"
#include "swordman.h"
#include "thief.h"


class Game: public QGraphicsView{
    Q_OBJECT

public:
    Game();
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void displayMainMenu();
    void setCountTower(int numTower);
    int getCountTower();
    void setCountCave(int numCave);
    int getCountCave();
    void decreaseCountTower();
    void decreaseCountCave();
    void gameOver();
    void displayGameOverWindow(QString textToDisplay);

    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Novice * buildNovice;
    Magican * buildMagican;
    Swordman * buildSwordman;
    Thief * buildThief;

public slots:
    void start();
    void restartGame();
    void spawnMVP();

private:
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    int countTower;
    int countCave;

};

#endif // GAME_H
