
#include "acolyteicon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

AcolyteIcon::AcolyteIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/acolyteIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void AcolyteIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildAcolyte)
    {
        game->buildAcolyte = new Acolyte();
        game->setCursor(QString(":/images/acolyte.png"));
    }
}
