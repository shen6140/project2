#include "thief.h"
#include "enemy.h"
#include <QPixmap>
#include <QVector>
#include <QTimer>
#include <QGraphicsScene>
#include "stone.h"
#include "game.h"
#include "cave.h"
#include "mvp.h"

extern Game * game;

Thief::Thief(): QObject(), QGraphicsPixmapItem() {
    //set the graphic
    setPixmap(QPixmap(":/images/thief.png"));
    setScale(0.75);
    HP = 100;

    //create vector called points
    QVector<QPointF> points;
    points << QPoint(0,0) << QPoint(1,0) << QPoint(1,1) << QPoint(0,1);

    //scale factor
    int SCALE_FACTOR = 300;
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
    QPointF minion_center(18,36);
    QLineF ln(poly_center,minion_center);  //create a line from polyCenter to towerCenter
    attackArea->setPos(x()+ln.dx(),y()+ln.dy());

    //connect
    QTimer * timerForMove = new QTimer();
    connect(timerForMove,SIGNAL(timeout()),this,SLOT(move()));
    timerForMove->start(50);

    //connect a timer to acquireTarget
    QTimer * timerForAcquire = new QTimer();
    connect(timerForAcquire,SIGNAL(timeout()),this,SLOT(acquireTarget()));
    timerForAcquire->start(1000);

    //set attackDest
    attackDest = QPointF(500,200);

}

void Thief::move(){
    //get a list of all the items currently colliding
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(HP > 0)
        {
            if (typeid(*(colliding_items[i])) == typeid(Enemy) || typeid(*(colliding_items[i])) == typeid(Cave))
            {
                decreaseHP(1);
                return;
            }
            else if (typeid(*(colliding_items[i])) == typeid(MVP))
            {
                decreaseHP(5);
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

    //move the thief right
    setPos(x()+2,y());

    if(pos().x() > 1000)
    {
        scene()-> removeItem(this);
        delete this;
    }
}


void Thief::acquireTarget()
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
    }
    if (hasTarget == true)
    {
        attackDest = closestPoint;
        fire();
        hasTarget = false;
    }
}


void Thief::decreaseHP(int damage)
{
    HP = HP - damage;
}

double Thief::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Thief::fire()
{
    Stone * stone1 = new Stone();
    stone1->setPos(x()+18,y()+36);
    QLineF ln1(QPointF(x()+18,y()+36),attackDest);
    int angle1 = -1 * ln1.angle();
    stone1->setRotation(angle1);
    game->scene->addItem(stone1);

    Stone * stone2 = new Stone();
    stone2->setPos(x()+10,y()+40);
    QLineF ln2(QPointF(x()+10,y()+40),attackDest);
    int angle2 = -1 * ln2.angle();
    stone2->setRotation(angle2);
    game->scene->addItem(stone2);
}
