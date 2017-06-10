#ifndef MONK_H
#define MONK_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QObject>  //to connect novice to signal and slot

class Monk: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT  //allow class to support signal and slot
public:
    Monk();
    void decreaseHP(int damage);

public slots:
    void move();

private:
    QGraphicsPolygonItem * attackArea;
    int HP;
};

#endif // MONK_H
