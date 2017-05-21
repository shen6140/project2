#ifndef NOVICEICON_H
#define NOVICEICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class NoviceIcon: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    NoviceIcon();
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

};

#endif // NOVICEICON_H
