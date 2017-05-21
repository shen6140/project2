
#include "mvp.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //for rand()
#include "tower.h"
#include "novice.h"
#include "swordman.h"
#include "thief.h"
#include "magican.h"

MVP::MVP(): QObject(), QGraphicsPixmapItem()
{
    int random_mvp = rand() % 4;

    if (random_mvp == 0)
    {
        setPixmap(QPixmap(":/images/amonRa.png"));
    }
    else if (random_mvp == 1)
    {
        setPixmap(QPixmap(":/images/drake.png"));
    }
    else if (random_mvp == 2)
    {
        setPixmap(QPixmap(":/images/mistress.png"));
    }
    else if(random_mvp == 3)
    {
        setPixmap(QPixmap(":/images/darkLord.png"));
    }

    //set random position
    int random_number = rand() % 350;
    setPos(850,random_number);

    HP = 500;

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void MVP::decreaseHP(int damage)
{
    HP = HP - damage;
}


void MVP::move()
{
    //get a list of all the items currently colliding
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 1, n = colliding_items.size(); i < n; ++i)
    {
        if(HP > 0)
        {
            if (typeid(*(colliding_items[i])) == typeid(Tower))
            {
                decreaseHP(1);
                return;
            }
            else if(typeid(*(colliding_items[i])) == typeid(Swordman))
            {
                decreaseHP(1);
                return;
            }
            else if(typeid(*(colliding_items[i])) == typeid(Thief))
            {
                decreaseHP(1);
                return;
            }
            else if(typeid(*(colliding_items[i])) == typeid(Magican))
            {
                decreaseHP(1);
                return;
            }
            else if(typeid(*(colliding_items[i])) == typeid(Novice))
            {
                decreaseHP(1);
                return;
            }

        }
        else if (HP <= 0)
        {
           scene()->removeItem(this);
           delete this;
           return;
        }
    }


    //move the enemy left
    setPos(x()-3,y());

    if(pos().x() < 0)
    {
        scene()-> removeItem(this);
        delete this;
    }
}
