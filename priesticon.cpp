
#include "priesticon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

PriestIcon::PriestIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/priestIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void PriestIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildPriest)
    {
        game->buildPriest = new Priest();
        game->setCursor(QString(":/images/priest.png"));
    }
}
