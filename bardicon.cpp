
#include "bardicon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

BardIcon::BardIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/bardIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void BardIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildBard)
    {
        game->buildBard = new Bard();
        game->setCursor(QString(":/images/bard.png"));
    }

}
