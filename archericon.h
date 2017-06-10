#ifndef ARCHERICON_H
#define ARCHERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class ArcherIcon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ArcherIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // ARCHERICON_H
