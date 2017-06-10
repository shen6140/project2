#ifndef KNIGHTICON_H
#define KNIGHTICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class KnightIcon: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    KnightIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

};


#endif // KNIGHTICON_H
