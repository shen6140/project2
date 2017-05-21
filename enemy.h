#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>  //to use connect signal and slot

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT //allow class to support signal and slot
public:
    Enemy();
    void decreaseHP(int damage);

public slots:
    void move();

private:
    int HP;
};

#endif // ENEMY_H
