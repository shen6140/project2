#ifndef KNIGHT_H
#define KNIGHT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QObject>  //to connect novice to signal and slot

class Knight: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT  //allow class to support signal and slot
public:
    Knight();
    void decreaseHP(int damage);
    void increaseHP(int heal);

public slots:
    void move();

private:
    QGraphicsPolygonItem * attackArea;
    int HP;
};

#endif // KNIGHT_H
