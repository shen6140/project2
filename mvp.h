#ifndef MVP_H
#define MVP_H

#include <QGraphicsPixmapItem>
#include <QObject>  //to use connect signal and slot

class MVP: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT //allow class to support signal and slot
public:
    MVP();
    void decreaseHP(int damage);

public slots:
    void move();

private:
    int HP;
};

#endif // MVP_H
