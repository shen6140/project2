
#include "thieficon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

ThiefIcon::ThiefIcon(): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/thiefIcon.png"));
    setPos(325,450);
    setScale(0.75);
}

void ThiefIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildThief)
    {
        game->buildThief = new Thief();
        game->setCursor(QString(":/images/thief.png"));
    }

}
