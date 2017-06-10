
#include "card.h"

Card::Card(): QObject(), QGraphicsPixmapItem()
{

}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     emit clicked();
}
