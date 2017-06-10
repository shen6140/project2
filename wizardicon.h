#ifndef WIZARDICON_H
#define WIZARDICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class WizardIcon: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    WizardIcon(int Xpos,int Ypos);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // WIZARDICON_H
