#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Arrow: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Arrow();
public slots:
    void move();

};

#endif // ARROW_H
