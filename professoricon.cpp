
#include "professoricon.h"
#include "game.h"
#include "enemy.h"
#include <QGraphicsScene>

extern Game * game;

ProfessorIcon::ProfessorIcon(int Xpos,int Ypos): QObject(), QGraphicsPixmapItem()
{
    setPixmap(QPixmap(":/images/professorIcon.png"));
    setPos(Xpos,Ypos);
    setScale(0.75);
}

void ProfessorIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(!game->buildProfessor)
    {
        game->buildProfessor = new Professor();
        game->setCursor(QString(":/images/professor.png"));
    }
}
