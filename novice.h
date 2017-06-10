#ifndef NOVICE_H
#define NOVICE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QObject>  //to connect novice to signal and slot

class Novice: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT  //allow class to support signal and slot
public:
    Novice();
    void decreaseHP(int damage);
    void increaseHP(int heal);

public slots:
    void move();

private:
    QGraphicsPolygonItem * attackArea;
    int HP;
};


#endif // NOVICE_H
