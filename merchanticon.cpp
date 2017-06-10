
#include "merchanticon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

MerchantIcon::MerchantIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/merchantIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void MerchantIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildMerchant)
    {
        game->buildMerchant = new Merchant();
        game->setCursor(QString(":/images/merchant.png"));
    }
}
