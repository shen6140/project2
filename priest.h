#ifndef PRIEST_H
#define PRIEST_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QObject>  //to connect novice to signal and slot

class Priest: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT  //allow class to support signal and slot
public:
    Priest();
    void decreaseHP(int damage);

public slots:
    void move();

private:
    QGraphicsPolygonItem * attackArea;
    int HP;
};

#endif // PRIEST_H
