#ifndef BARD_H
#define BARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QObject>  //to connect novice to signal and slot

class Bard: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT  //allow class to support signal and slot
public:
    Bard();
    void decreaseHP(int damage);
    void increaseHP(int heal);

public slots:
    void move();

private:
    QGraphicsPolygonItem * attackArea;
    int HP;
};

#endif // BARD_H
