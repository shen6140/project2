
#include "assassinicon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

AssassinIcon::AssassinIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/assassinIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void AssassinIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildAssassin)
    {
        game->buildAssassin = new Assassin();
        game->setCursor(QString(":/images/assassin.png"));
    }

}
