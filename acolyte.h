#ifndef ACOLYTE_H
#define ACOLYTE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QObject>  //to connect novice to signal and slot

class Acolyte: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT  //allow class to support signal and slot
public:
    Acolyte();
    void decreaseHP(int damage);

public slots:
    void move();

private:
    QGraphicsPolygonItem * attackArea;
    int HP;
};

#endif // ACOLYTE_H
