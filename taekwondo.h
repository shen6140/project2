#ifndef TAEKWONDO_H
#define TAEKWONDO_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QObject>  //to connect novice to signal and slot

class Taekwondo: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT  //allow class to support signal and slot
public:
    Taekwondo();
    void decreaseHP(int damage);
    void increaseHP(int heal);

public slots:
    void move();

private:
    QGraphicsPolygonItem * attackArea;
    int HP;
};

#endif // TAEKWONDO_H
