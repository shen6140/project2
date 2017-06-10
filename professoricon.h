#ifndef PROFESSORICON_H
#define PROFESSORICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class ProfessorIcon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ProfessorIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // PROFESSORICON_H
