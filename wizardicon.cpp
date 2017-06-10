
#include "wizardicon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

WizardIcon::WizardIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/wizardIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void WizardIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildWizard)
    {
        game->buildWizard = new Wizard();
        game->setCursor(QString(":/images/wizard.png"));
    }

}
