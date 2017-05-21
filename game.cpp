
#include "game.h"
#include <QGraphicsScene>
#include <QImage>
#include <QTimer>
#include "tower.h"
#include "arrow.h"
#include "enemy.h"
#include "button.h"
#include "novice.h"
#include "noviceicon.h"
#include "magican.h"
#include "magicanicon.h"
#include "swordman.h"
#include "swordmanicon.h"
#include "thief.h"
#include "thieficon.h"
#include "cave.h"
#include <QMediaPlayer>
#include "mvp.h"

extern Game * game;
QMediaPlayer * bgMusic;
QMediaPlayer * mainTheme;
bool firstGame;

Game::Game():QGraphicsView()
{
    //create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,550);
    setBackgroundBrush(QBrush(QImage(":/images/grassland.png")));

    // make the newly created scene the scene to visualize
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,550);

    firstGame = true;

}

void Game::setCursor(QString filename)
{    //setCursor function is ok

    if(cursor){
        scene->removeItem(cursor);
        delete cursor;
    }
    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(QPixmap(filename));
    cursor->setScale(0.75);
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event)   //mouseMoveEvent is ok
{
    if(cursor)
    {
        cursor->setPos(event->pos());
    }

}

void Game::mousePressEvent(QMouseEvent *event)
{
    if(buildNovice)
    {
        delete cursor;
        scene->addItem(buildNovice);
        buildNovice->setPos(event->pos());

        cursor = nullptr;
        buildNovice = nullptr;
    }
    else if(buildMagican)
    {
        delete cursor;
        scene->addItem(buildMagican);
        buildMagican->setPos(event->pos());

        cursor = nullptr;
        buildMagican = nullptr;
    }
    else if(buildSwordman)
    {
        delete cursor;
        scene->addItem(buildSwordman);
        buildSwordman->setPos(event->pos());

        cursor = nullptr;
        buildSwordman = nullptr;
    }
    else if (buildThief)
    {
        delete cursor;
        scene->addItem(buildThief);
        buildThief->setPos(event->pos());

        cursor = nullptr;
        buildThief = nullptr;
    }
    else
    {
        QGraphicsView::mousePressEvent(event);
    }


}

void Game::displayMainMenu()
{
     // play opening mainTheme music
     mainTheme = new QMediaPlayer();
     mainTheme->setMedia(QUrl("qrc:/music/mainTheme.mp3"));
     mainTheme->setVolume(60);
     mainTheme->play();

     // create the title text
     QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Project TWO"));
     QFont titleFont("comic sans",50);
     titleText->setFont(titleFont);
     int txPos = this->width()/2 - titleText->boundingRect().width()/2;
     int tyPos = 150;
     titleText->setPos(txPos,tyPos);
     scene->addItem(titleText);

     // create the play button
     Button* playButton = new Button(QString("Play"));
     int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
     int byPos = 275;
     playButton->setPos(bxPos,byPos);
     connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
     scene->addItem(playButton);

     // create the quit button
     Button* quitButton = new Button(QString("Quit"));
     int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
     int qyPos = 350;
     quitButton->setPos(qxPos,qyPos);
     connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
     scene->addItem(quitButton);

}

void Game::setCountTower(int numTower)
{
    countTower = numTower;
}

int Game::getCountTower()
{
    return countTower;
}

void Game::setCountCave(int numCave)
{
    countCave = numCave;
}

int Game::getCountCave()
{
    return countCave;
}

void Game::decreaseCountTower()
{
    countTower = countTower - 1;
}

void Game::decreaseCountCave()
{
    countCave = countCave - 1;
}

void Game::gameOver()
{
    QString message;

    if (countTower > countCave)
    {
        message = " YOU WIN ! ";
    }
    else if (countTower < countCave)
    {
        message = " YOU LOSE ! ";
    }
    else if (countTower ==  countCave)
    {
        message = " TIE GAME ! ";
    }

    displayGameOverWindow(message);
}

void Game::displayGameOverWindow(QString textToDisplay)
{
    // disable all scene items
    for (size_t i = 0, n = scene->items().size(); i < n; i++)
    {
        scene->items()[i]->setEnabled(false);
    }

    // pop up semi transparent panel
    drawPanel(0,0,1000,550,Qt::black,0.65);

    // draw panel
    drawPanel(300,70,400,400,Qt::lightGray,0.75);

    // create playAgain button
    Button* playAgain = new Button(QString("Play Again"));
    playAgain->setPos(410,300);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    // create quit button
    Button* quit = new Button(QString("Quit"));
    quit->setPos(410,375);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    // create text annoucning winner
    QGraphicsTextItem* gameOverText = new QGraphicsTextItem(textToDisplay);
    gameOverText->setPos(300,150);
    gameOverText->setScale(5);
    scene->addItem(gameOverText);

}

void Game::start()
{
    // clear the screen
    scene->clear();

    if(firstGame)
    {
        mainTheme->stop();
        delete mainTheme;
    }


    // play background music
    bgMusic = new QMediaPlayer();
    bgMusic->setMedia(QUrl("qrc:/music/streamside.mp3"));
    bgMusic->setVolume(20);
    bgMusic->play();

    //set the cursor
    cursor = nullptr;
    buildNovice = nullptr;
    setMouseTracking(true);

    Tower * towerUp = new Tower(30,40);
    scene->addItem(towerUp);

    Tower * towerMiddle = new Tower(80,150);
    scene->addItem(towerMiddle);

    Tower * towerDown = new Tower(30,260);
    scene->addItem(towerDown);

    Cave * caveUp = new Cave(850,40);
    scene->addItem(caveUp);

    Cave * caveMiddle = new Cave(800,150);
    scene->addItem(caveMiddle);

    Cave * caveDown = new Cave(850,260);
    scene->addItem(caveDown);

    game->setCountTower(3);
    game->setCountCave(3);

    NoviceIcon * noviceIC = new NoviceIcon();
    scene->addItem(noviceIC);

    MagicanIcon * magicanIC = new MagicanIcon();
    scene->addItem(magicanIC);

    SwordmanIcon * swordmanIC = new SwordmanIcon();
    scene->addItem(swordmanIC);

    ThiefIcon * thiefIC = new ThiefIcon();
    scene->addItem(thiefIC);

    countTower = 3;
    countCave = 3;

    //MVP challenge
    Button* MVP = new Button(QString(" MVP "));
    MVP->setPos(750,490);
    scene->addItem(MVP);
    connect(MVP,SIGNAL(clicked()),this,SLOT(spawnMVP()));

    //spawn the enemies
    QTimer * timerForUpCave = new QTimer();
    QObject::connect(timerForUpCave,SIGNAL(timeout()),caveUp,SLOT(spawn()));
    timerForUpCave->start(5000);

    //spawn the enemies
    QTimer * timerForMiddleCave = new QTimer();
    QObject::connect(timerForMiddleCave,SIGNAL(timeout()),caveUp,SLOT(spawn()));
    timerForMiddleCave->start(5000);

    //spawn the enemies
    QTimer * timerForDownCave = new QTimer();
    QObject::connect(timerForDownCave,SIGNAL(timeout()),caveUp,SLOT(spawn()));
    timerForDownCave->start(5000);
}

void Game::restartGame()
{
    // clear some stuff then call start()
    scene->clear();
    bgMusic->stop();
    delete bgMusic;
    firstGame = false;
    start();
}

void Game::spawnMVP()
{
    //spawn an enemy
    MVP * mvp = new MVP();
    scene->addItem(mvp);
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity)
{
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}
