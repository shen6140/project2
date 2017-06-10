#ifndef MONKICON_H
#define MONKICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class MonkIcon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    MonkIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // MONKICON_H
