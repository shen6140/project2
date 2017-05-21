
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h> //for rand()
#include "tower.h"
#include "novice.h"
#include "swordman.h"
#include "thief.h"
#include "magican.h"

Enemy::Enemy(): QObject(), QGraphicsPixmapItem()
{

    int random_enemy = rand() % 3;

    if (random_enemy == 0)
    {
        setPixmap(QPixmap(":/images/redPoring.png"));
    }
    else if (random_enemy == 1)
    {
        setPixmap(QPixmap(":/images/greenPoring.png"));
    }
    else if (random_enemy == 2)
    {
        setPixmap(QPixmap(":/images/santaPoring.png"));
    }

//    setPos(300,90);

    //set random position
    int random_number = rand() % 350;
    setPos(800,random_number);     //to create enemy in front of cave
    HP = 150;


    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Enemy::decreaseHP(int damage)
{
    HP = HP - damage;
}


void Enemy::move()
{
    //get a list of all the items currently colliding
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 1, n = colliding_items.size(); i < n; ++i)
    {
        if(HP > 0)
        {
            if (typeid(*(colliding_items[i])) == typeid(Tower))
            {
                decreaseHP(3);
                return;
            }
            else if(typeid(*(colliding_items[i])) == typeid(Swordman))
            {
                decreaseHP(3);
                return;
            }
            else if(typeid(*(colliding_items[i])) == typeid(Thief))
            {
                decreaseHP(2);
                return;
            }
            else if(typeid(*(colliding_items[i])) == typeid(Magican))
            {
                decreaseHP(2);
                return;
            }
            else if(typeid(*(colliding_items[i])) == typeid(Novice))
            {
                decreaseHP(1);
                return;
            }
            else if(typeid(*(colliding_items[i])) == typeid(QGraphicsPolygonItem))
            {
               decreaseHP(1);
               setPos(x()-2,y());
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
    setPos(x()-4,y());

    if(pos().x() < 0)
    {
        scene()-> removeItem(this);
        delete this;
    }
}
