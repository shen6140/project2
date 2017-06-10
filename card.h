#ifndef CARD_H
#define CARD_H

#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QGraphicsPixmapItem>

class Card: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    // constructors
    Card();

    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void clicked();

};

#endif // CARD_H
