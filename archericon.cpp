
#include "archericon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

ArcherIcon::ArcherIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/archerIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void ArcherIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildArcher)
    {
        game->buildArcher = new Archer();
        game->setCursor(QString(":/images/archer.png"));
    }
}
