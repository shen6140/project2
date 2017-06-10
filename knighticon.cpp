
#include "knighticon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

KnightIcon::KnightIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/images/knightIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void KnightIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->buildKnight){
        game->buildKnight = new Knight();
        game->setCursor(QString(":/images/knight.png"));
    }

}
