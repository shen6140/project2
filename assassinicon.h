#ifndef ASSASSINICON_H
#define ASSASSINICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class AssassinIcon: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    AssassinIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

};

#endif // ASSASSINICON_H
