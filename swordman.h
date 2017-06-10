#ifndef SWORDMAN_H
#define SWORDMAN_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QObject>  //to connect novice to signal and slot

class Swordman: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT  //allow class to support signal and slot
public:
    Swordman();
    void decreaseHP(int damage);
    void increaseHP(int heal);

public slots:
    void move();

private:
    QGraphicsPolygonItem * attackArea;
    int HP;
};

#endif // SWORDMAN_H
