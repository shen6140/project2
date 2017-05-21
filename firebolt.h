#ifndef FIREBOLT_H
#define FIREBOLT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Firebolt: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Firebolt();
public slots:
    void move();

};

#endif // FIREBOLT_H
