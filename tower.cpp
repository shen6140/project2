
#include "tower.h"
#include <QVector>
#include "arrow.h"
#include <QTimer>
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>
#include "mvp.h"

extern Game * game;

Tower::Tower(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/tower.png"));
    setPos(Xpos,Ypos);
    setScale(0.5);
    HP = 100;

    //create vector called points
    QVector<QPointF> points;
    points << QPoint(0,0) << QPoint(1,0) << QPoint(1,1) << QPoint(0,1);

    //scale factor of attackArea
    int SCALE_FACTOR = 400;
    for(size_t i = 0, n = points.size(); i < n; ++i)
    {
        points[i] *= SCALE_FACTOR;
    }

    //create a polygon from these points
    QPolygonF polygon(points);

    // create the QGraphicsPolygonItem
    attackArea = new QGraphicsPolygonItem(QPolygonF(points),this);
    attackArea->setPen(QPen(Qt::transparent));

//    attackArea->setPen(QPen(Qt::black));

    // move the polygon to the center of the tower
    QPointF poly_center(0.5,0.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);;
    QPointF tower_center(41,50);
    QLineF ln(poly_center,tower_center);  //create a line from polyCenter to towerCenter
    attackArea->setPos(x()+ln.dx(),y()+ln.dy());

    //connect a timer to acquireTarget
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(acquireTarget()));
    timer->start(1000);

//    //set attackDest
//    attackDest = QPointF(500,200);

}

double Tower::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(),item->pos());
    return ln.length();

}

void Tower::fire(){
    Arrow * arrow = new Arrow(QString(":/images/arrow.png"));
    arrow->setPos(x()+41,y()+50);
    QLineF ln(QPointF(x()+41,y()+50),attackDest);
    int angle = -1 * ln.angle();
    arrow->setRotation(angle);
    game->scene->addItem(arrow);

}

void Tower::decreaseHP(int damage)
{
    HP = HP - damage;
}

void Tower::acquireTarget()
{
    if(HP <= 0)
    {
        if (game->getCountTower() == 1)
        {
            scene()->removeItem(this);
            delete this;
            game->decreaseCountTower();
            game->gameOver();
            return;
        }
        else if (game->getCountTower() > 1)
        {
            scene()->removeItem(this);
            delete this;
            game->decreaseCountTower();
            return;
        }

    }
    if(HP > 0)
    {
        //get a list of all items colliding with attackArea
        QList <QGraphicsItem *> colliding_items = attackArea->collidingItems();
        if(colliding_items.size() == 1)
        {
            hasTarget = false;
            return;
        }

        double closestDistance = 500;
        QPointF closestPoint = QPointF(0,0);

        for(size_t i = 1 , n = colliding_items.size() ; i < n ; i++)
        {
            if (typeid(*(colliding_items[i])) == typeid(Enemy))
            { 
                double thisDistance = distanceTo(colliding_items[i]);
                if(thisDistance < closestDistance)
                {
                    closestDistance = thisDistance;
                    closestPoint = colliding_items[i]->pos();
                    hasTarget = true;
                }
            }
            else if (typeid(*(colliding_items[i])) == typeid(MVP))
            {
                double thisDistance = distanceTo(colliding_items[i]);
                if(thisDistance < closestDistance)
                {
                    closestDistance = thisDistance;
                    closestPoint = colliding_items[i]->pos();
                    hasMVP = true;
                }
            }
        }
        if (hasMVP == true)
        {
            attackDest = closestPoint;
            fire();
            decreaseHP(5);
            hasMVP = false;
        }
        else if(hasTarget == true)
        {
            attackDest = closestPoint;
            fire();
            decreaseHP(1);
            hasTarget = false;
        }
    }
}

