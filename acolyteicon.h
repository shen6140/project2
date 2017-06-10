#ifndef ACOLYTEICON_H
#define ACOLYTEICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class AcolyteIcon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    AcolyteIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // ACOLYTEICON_H
