#ifndef THIEFICON_H
#define THIEFICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class ThiefIcon: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    ThiefIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

};

#endif // THIEFICON_H
