
#include "monkicon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

MonkIcon::MonkIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/monkIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void MonkIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildMonk)
    {
        game->buildMonk = new Monk();
        game->setCursor(QString(":/images/monk.png"));
    }
}
