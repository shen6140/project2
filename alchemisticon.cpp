
#include "alchemisticon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

AlchemistIcon::AlchemistIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/alchemistIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void AlchemistIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildAlchemist)
    {
        game->buildAlchemist = new Alchemist();
        game->setCursor(QString(":/images/alchemist.png"));
    }
}
