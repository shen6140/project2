#ifndef ALCHEMISTICON_H
#define ALCHEMISTICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class AlchemistIcon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    AlchemistIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // ALCHEMISTICON_H
