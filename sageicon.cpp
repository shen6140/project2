
#include "sageicon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

SageIcon::SageIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/sageIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void SageIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildSage)
    {
        game->buildSage = new Sage();
        game->setCursor(QString(":/images/sage.png"));
    }

}

