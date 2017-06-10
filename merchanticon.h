#ifndef MERCHANTICON_H
#define MERCHANTICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class MerchantIcon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    MerchantIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // MERCHANTICON_H
