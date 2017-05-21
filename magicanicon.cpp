
#include "magicanicon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

MagicanIcon::MagicanIcon(): QObject(), QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/images/magicanIcon.png"));
    setPos(115,450);
    setScale(0.75);
}

void MagicanIcon::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!game->buildMagican){
        game->buildMagican = new Magican();
        game->setCursor(QString(":/images/magican.png"));
    }

}
