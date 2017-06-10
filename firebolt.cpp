#include "firebolt.h"
#include <QTimer>
#include <qmath.h>   //for qSin, qCos
#include "game.h"
#include "enemy.h"
#include "cave.h"
#include "mvp.h"

extern Game * game;

Firebolt::Firebolt(QString filename, float scale): QObject(), QGraphicsPixmapItem()
{
    //put in a arrow image
    setPixmap(QPixmap(filename));
    setScale(scale);

    //connect to timer
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Firebolt::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if (typeid(*(colliding_items[i])) == typeid(Enemy) || typeid(*(colliding_items[i])) == typeid(MVP) || typeid(*(colliding_items[i])) == typeid(Cave))
        {
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    int STEP_SIZE = 30;
    double theta = rotation();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx,y()+dy);

    if(pos().x() < 0 || pos().x() > 1000 || pos().y() < 0 || pos().y() > 550)
    {
        scene()-> removeItem(this);
        delete this;
    }
}
