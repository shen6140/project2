
#include "swordmanicon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

SwordmanIcon::SwordmanIcon(): QObject(), QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/images/swordmanIcon.png"));
    setPos(220,450);
    setScale(0.75);
}

void SwordmanIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->buildSwordman){
        game->buildSwordman = new Swordman();
        game->setCursor(QString(":/images/swordman.png"));
    }

}
