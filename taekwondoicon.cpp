
#include "taekwondoicon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

TaekwondoIcon::TaekwondoIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/images/taekwondoIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void TaekwondoIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->buildTaekwondo)
    {
        game->buildTaekwondo = new Taekwondo();
        game->setCursor(QString(":/images/taekwondo.png"));
    }

}
