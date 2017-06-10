#include "monk.h"
#include "enemy.h"
#include <QPixmap>
#include <QVector>
#include <QTimer>
#include <QGraphicsScene>
#include "cave.h"
#include "mvp.h"

Monk::Monk(): QObject(), QGraphicsPixmapItem() {
    //set the graphic
    setPixmap(QPixmap(":/images/monk.png"));
    setScale(0.75);
    HP = 200;

    //create vector called points
    QVector<QPointF> points;
    points << QPoint(0,0) << QPoint(1,0) << QPoint(1,1) << QPoint(0,1);

    //scale factor
    int SCALE_FACTOR = 150;
    for(size_t i = 0, n = points.size(); i < n; ++i){
        points[i] *= SCALE_FACTOR;
    }

    //create a polygon from these points
    QPolygonF polygon(points);

    // create the QGraphicsPolygonItem
    attackArea = new QGraphicsPolygonItem(QPolygonF(points),this);
    attackArea->setPen(QPen(Qt::transparent));

 //   attackArea->setPen(QPen(Qt::black));

    // move the polygon to the center of the tower
    QPointF poly_center(0.5,0.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);;
    QPointF minion_center(18,36);
    QLineF ln(poly_center,minion_center);  //create a line from polyCenter to towerCenter
    attackArea->setPos(x()+ln.dx(),y()+ln.dy());

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}

void Monk::move(){
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

    //move the swordman right
    setPos(x()+2,y());

    if(pos().x() > 1000)
    {
        scene()-> removeItem(this);
        delete this;
    }

}


void Monk::decreaseHP(int damage)
{
    HP = HP - damage;
}

