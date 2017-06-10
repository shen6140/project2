#ifndef CAVE_H
#define CAVE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QPointF>
#include <QObject>
#include <QGraphicsTextItem>

class Cave: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    Cave(int Xpos,int Ypos);
    double distanceTo(QGraphicsItem * item);
    void fire();
    void decreaseHP(int damage);

public slots:
    void acquireTarget();
    void spawn();

private:
    QPointF attackDest;  //attack destination
    bool hasFirst = false;
    bool hasSecond = false;
    bool hasLightning = false;
    QGraphicsPolygonItem * attackArea;
    int HP;
};

#endif // CAVE_H
