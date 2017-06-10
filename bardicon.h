#ifndef BARDICON_H
#define BARDICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class BardIcon: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    BardIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

};


#endif // BARDICON_H
