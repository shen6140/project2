#ifndef ASSASIN_H
#define ASSASIN_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QObject>  //to connect novice to signal and slot

class Assassin: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT  //allow class to support signal and slot
public:
    Assassin();
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

#endif // ASSASIN_H
