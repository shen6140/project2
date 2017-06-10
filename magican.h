#ifndef MAGICAN_H
#define MAGICAN_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QObject>  //to connect novice to signal and slot

class Magican: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT  //allow class to support signal and slot
public:
    Magican();
    void decreaseHP(int damage);
    void increaseHP(int heal);
    double distanceTo(QGraphicsItem * item);
    void fire();

public slots:
    void move();
    void acquireTarget();

private:
    QGraphicsPolygonItem * attackArea;
    int HP;
    QPointF attackDest;  //attack destination
    bool hasTarget = false;
};

#endif // MAGICAN_H
