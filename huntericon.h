#ifndef HUNTERICON_H
#define HUNTERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class HunterIcon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    HunterIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // HUNTERICON_H
