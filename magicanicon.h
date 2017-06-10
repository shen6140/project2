#ifndef MAGICANICON_H
#define MAGICANICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class MagicanIcon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    MagicanIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // MAGICANICON_H
