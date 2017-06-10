#include "lightning.h"
#include <QTimer>
#include <qmath.h>   //for qSin, qCos
#include "game.h"
#include "enemy.h"
#include "cave.h"
#include "mvp.h"

extern Game * game;

Lightning::Lightning(): QObject(), QGraphicsPixmapItem()
{
    //put in a arrow image
    setPixmap(QPixmap(":/images/lightningBolt.png"));

    moveNum = 0;

    //connect to timer
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Lightning::move()
{
    if(moveNum %2 == 0 )
    {
        setPos(x(),y()+10);
        moveNum += 1;
    }
    else if(moveNum %2 != 0)
    {
        setPos(x(),y()-10);
        moveNum += 1;
    }
    if(moveNum > 50)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
}
