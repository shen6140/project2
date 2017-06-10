
#include "noviceicon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

NoviceIcon::NoviceIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/noviceIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void NoviceIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildNovice)
    {
        game->buildNovice = new Novice();
        game->setCursor(QString(":/images/novice.png"));
    }

}

