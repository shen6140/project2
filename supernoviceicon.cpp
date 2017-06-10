#include "supernoviceicon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

SuperNoviceIcon::SuperNoviceIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/superNoviceIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void SuperNoviceIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildSuperNovice)
    {
        game->buildSuperNovice = new SuperNovice();
        game->setCursor(QString(":/images/superNovice.png"));
    }

}
