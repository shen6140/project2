#ifndef LIGHTNING_H
#define LIGHTNING_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Lightning: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Lightning();
public slots:
    void move();
private:
    int moveNum;

};

#endif // LIGHTING_H
