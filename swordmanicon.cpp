
#include "swordmanicon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

SwordmanIcon::SwordmanIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/images/swordmanIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void SwordmanIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->buildSwordman){
        game->buildSwordman = new Swordman();
        game->setCursor(QString(":/images/swordman.png"));
    }

}
