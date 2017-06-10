
#include "ninjaicon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

NinjaIcon::NinjaIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/ninjaIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void NinjaIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildNinja)
    {
        game->buildNinja = new Ninja();
        game->setCursor(QString(":/images/ninja.png"));
    }
}
