#ifndef SUPERNOVICEICON_H
#define SUPERNOVICEICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class SuperNoviceIcon: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    SuperNoviceIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

};

#endif // SUPERNOVICEICON_H
