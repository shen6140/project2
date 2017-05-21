#ifndef STONE_H
#define STONE_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Stone: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Stone();
public slots:
    void move();

};

#endif // STONE_H
