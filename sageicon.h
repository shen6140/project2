#ifndef SAGEICON_H
#define SAGEICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class SageIcon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    SageIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // SAGEICON_H
