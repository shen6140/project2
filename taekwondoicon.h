#ifndef TAEKWONDOICON_H
#define TAEKWONDOICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class TaekwondoIcon: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    TaekwondoIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

};


#endif // TAEKWONDOICON_H
