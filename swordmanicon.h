#ifndef SWORDMANICON_H
#define SWORDMANICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class SwordmanIcon: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    SwordmanIcon();
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

};

#endif // SWORDMANICON_H
