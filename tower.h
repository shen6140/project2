#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QPointF>
#include <QObject>
#include <QGraphicsTextItem>

class Tower: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Tower(int Xpos,int Ypos);
    double distanceTo(QGraphicsItem * item);
    void fire();
    void decreaseHP(int damage);

public slots:
    void acquireTarget();

private:
    QPointF attackDest;  //attack destination
    bool hasTarget = false;
    bool hasMVP = false;
    QGraphicsPolygonItem * attackArea;
    int HP;
};

#endif // TOWER_H
