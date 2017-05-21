
#include "cave.h"
#include <QVector>
#include "arrow.h"
#include <QTimer>
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

Cave::Cave(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/images/cave.png"));
    setPos(Xpos,Ypos);
    setScale(1);
    HP = 50;

    //create vector called points
    QVector<QPointF> points;
    points << QPoint(0,0) << QPoint(1,0) << QPoint(1,1) << QPoint(0,1);

    //scale factor of attackArea
    int SCALE_FACTOR = 200;
    for(size_t i = 0, n = points.size(); i < n; ++i){
        points[i] *= SCALE_FACTOR;
    }

    //create a polygon from these points
    QPolygonF polygon(points);

    // create the QGraphicsPolygonItem
    attackArea = new QGraphicsPolygonItem(QPolygonF(points),this);
    attackArea->setPen(QPen(Qt::transparent));

    // move the polygon to the center of the tower
    QPointF poly_center(0.5,0.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);;
    QPointF cave_center(41,50);
    QLineF ln(poly_center,cave_center);  //create a line from polyCenter to towerCenter
    attackArea->setPos(x()+ln.dx(),y()+ln.dy());

    //connect a timer to acquireTarget
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(acquireTarget()));
    timer->start(1000);

    //set attackDest
    attackDest = QPointF(500,200);

}

double Cave::distanceTo(QGraphicsItem *item){
    QLineF ln(pos(),item->pos());
    return ln.length();

}

void Cave::fire(){
    Arrow * arrow = new Arrow();
    arrow->setPos(x()+33,y()+55);
    QLineF ln(QPointF(x()+33,y()+55),attackDest);
    int angle = -1 * ln.angle();
    arrow->setRotation(angle);
    game->scene->addItem(arrow);

}

void Cave::decreaseHP(int damage)
{
    HP = HP - damage;
}

void Cave::acquireTarget()
{
    if(HP <= 0)
    {
        if (game->getCountCave() == 1)
        {
            scene()->removeItem(this);
            delete this;
            game->decreaseCountCave();
            game->gameOver();
            return;
        }
        else if (game->getCountCave() > 1)
        {
            scene()->removeItem(this);
            delete this;
            game->decreaseCountCave();
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

        for(size_t i = 0 , n = colliding_items.size() ; i < n ; i++)
        {
            if (typeid(*(colliding_items[i])) == typeid(Novice)||typeid(*(colliding_items[i])) == typeid(Swordman)||typeid(*(colliding_items[i])) == typeid(Magican)||typeid(*(colliding_items[i])) == typeid(Thief))
            {
                double thisDistance = distanceTo(colliding_items[i]);
                if(thisDistance < closestDistance)
                {
                    closestDistance = thisDistance;
                    closestPoint = colliding_items[i]->pos();
                    hasTarget = true;
                }
            }
        }
        if(hasTarget == true)
        {
            attackDest = closestPoint;
            fire();
            decreaseHP(1);
            hasTarget = false;
        }

    }

}

void Cave::spawn()
{
    //spawn an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
