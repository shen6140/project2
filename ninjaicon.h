#ifndef NINJAICON_H
#define NINJAICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class NinjaIcon: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    NinjaIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

};

#endif // NINJAICON_H
