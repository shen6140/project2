
#include "huntericon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

HunterIcon::HunterIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/hunterIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void HunterIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildHunter){
        game->buildHunter = new Hunter();
        game->setCursor(QString(":/images/hunter.png"));
    }

}
