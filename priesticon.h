#ifndef PRIESTICON_H
#define PRIESTICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class PriestIcon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    PriestIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // PRIESTICON_H
