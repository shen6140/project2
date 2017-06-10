
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
#include "mvp.h"
#include <QGraphicsScene>
#include "card.h"
#include <QDebug>
#include "supernovice.h"
#include "supernoviceicon.h"
#include "acolyte.h"
#include "acolyteicon.h"
#include "archer.h"
#include "archericon.h"
#include "merchant.h"
#include "merchanticon.h"
#include "priest.h"
#include "priesticon.h"
#include "monk.h"
#include "monkicon.h"
#include "knight.h"
#include "knighticon.h"
#include "assassin.h"
#include "assassinicon.h"
#include "wizard.h"
#include "wizardicon.h"
#include "hunter.h"
#include "huntericon.h"
#include "alchemist.h"
#include "alchemisticon.h"
#include "ninja.h"
#include "ninjaicon.h"
#include "sage.h"
#include "sageicon.h"
#include "bard.h"
#include "bardicon.h"
#include "professor.h"
#include "professoricon.h"
#include "taekwondo.h"
#include "taekwondoicon.h"


Game::Game():QGraphicsView()
{
    //create a scene
    scene = new QGraphicsScene();
    setMinimumSize(1000,550);
    setBackgroundBrush(QBrush(QImage(":/images/grassland.png")));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // make the newly created scene to visualize
    setScene(scene);

    buildNovice = nullptr;
    buildSwordman = nullptr;
    buildMagican = nullptr;
    buildThief = nullptr;
    buildSuperNovice = nullptr;
    buildAcolyte = nullptr;
    buildArcher = nullptr;
    buildMerchant = nullptr;
    buildPriest = nullptr;
    buildMonk = nullptr;
    buildKnight = nullptr;
    buildAssassin = nullptr;
    buildWizard = nullptr;
    buildHunter = nullptr;
    buildAlchemist = nullptr;
    buildNinja = nullptr;
    buildSage = nullptr;
    buildBard = nullptr;
    buildProfessor = nullptr;
    buildTaekwondo = nullptr;

    bgMusic = nullptr;
    mainTheme = nullptr;
    bardMusic = nullptr;

    clickNoviceCardNum = 0;
    clickSwordmanCardNum = 0;
    clickThiefCardNum = 0;
    clickMagicanCardNum = 0;
    clickSuperNoviceCardNum = 0;
    clickAcolyteCardNum = 0;
    clickArcherCardNum = 0;
    clickMerchantCardNum = 0;
    clickPriestCardNum = 0;
    clickMonkCardNum = 0;
    clickKnightCardNum = 0;
    clickAssassinCardNum = 0;
    clickWizardCardNum = 0;
    clickHunterCardNum = 0;
    clickAlchemistCardNum = 0;
    clickNinjaCardNum = 0;
    clickSageCardNum = 0;
    clickBardCardNum = 0;
    clickProfessorCardNum = 0;
    clickTaekwondoCardNum = 0;

    for(int i = 0 ; i < 20 ; i++ )
    {
        cardWanted[i] = 0 ;
    }

}

void Game::setCursor(QString filename)
{
    if(cursor)
    {
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
    else if(buildSuperNovice)
    {
        delete cursor;
        scene->addItem(buildSuperNovice);
        buildSuperNovice->setPos(event->pos());

        cursor = nullptr;
        buildSuperNovice = nullptr;
    }
    else if(buildAcolyte)
    {
        delete cursor;
        scene->addItem(buildAcolyte);
        buildAcolyte->setPos(event->pos());

        cursor = nullptr;
        buildAcolyte = nullptr;
    }
    else if(buildArcher)
    {
        delete cursor;
        scene->addItem(buildArcher);
        buildArcher->setPos(event->pos());

        cursor = nullptr;
        buildArcher = nullptr;
    }
    else if(buildMerchant)
    {
        delete cursor;
        scene->addItem(buildMerchant);
        buildMerchant->setPos(event->pos());

        cursor = nullptr;
        buildMerchant = nullptr;
    }
    else if(buildPriest)
    {
        delete cursor;
        scene->addItem(buildPriest);
        buildPriest->setPos(event->pos());

        cursor = nullptr;
        buildPriest = nullptr;
    }
    else if(buildMonk)
    {
        delete cursor;
        scene->addItem(buildMonk);
        buildMonk->setPos(event->pos());

        cursor = nullptr;
        buildMonk = nullptr;
    }
    else if(buildKnight)
    {
        delete cursor;
        scene->addItem(buildKnight);
        buildKnight->setPos(event->pos());

        cursor = nullptr;
        buildKnight = nullptr;
    }
    else if(buildAssassin)
    {
        delete cursor;
        scene->addItem(buildAssassin);
        buildAssassin->setPos(event->pos());

        cursor = nullptr;
        buildAssassin = nullptr;
    }
    else if(buildWizard)
    {
        delete cursor;
        scene->addItem(buildWizard);
        buildWizard->setPos(event->pos());

        cursor = nullptr;
        buildWizard = nullptr;
    }
    else if(buildHunter)
    {
        delete cursor;
        scene->addItem(buildHunter);
        buildHunter->setPos(event->pos());

        cursor = nullptr;
        buildHunter = nullptr;
    }
    else if(buildAlchemist)
    {
        delete cursor;
        scene->addItem(buildAlchemist);
        buildAlchemist->setPos(event->pos());

        cursor = nullptr;
        buildAlchemist = nullptr;
    }
    else if(buildNinja)
    {
        delete cursor;
        scene->addItem(buildNinja);
        buildNinja->setPos(event->pos());

        cursor = nullptr;
        buildNinja = nullptr;
    }
    else if(buildSage)
    {
        delete cursor;
        scene->addItem(buildSage);
        buildSage->setPos(event->pos());

        cursor = nullptr;
        buildSage = nullptr;
    }
    else if(buildBard)
    {
        delete cursor;
        scene->addItem(buildBard);
        buildBard->setPos(event->pos());

        cursor = nullptr;
        buildBard = nullptr;
    }
    else if(buildProfessor)
    {
        delete cursor;
        scene->addItem(buildProfessor);
        buildProfessor->setPos(event->pos());

        cursor = nullptr;
        buildProfessor = nullptr;
    }
    else if(buildTaekwondo)
    {
        delete cursor;
        scene->addItem(buildTaekwondo);
        buildTaekwondo->setPos(event->pos());

        cursor = nullptr;
        buildTaekwondo = nullptr;
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
     QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Project Three"));
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
     connect(playButton,SIGNAL(clicked()),this,SLOT(drawCardWindow()));
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

void Game::drawCardWindow()
{
    // clear the screen
    scene->clear();
    scene->setSceneRect(0,0,1000,900);

    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Please select four characters to defend your tower "));
    QFont titleFont("comic sans",25);
    titleText->setFont(titleFont);
    titleText->setPos(20,150);
    scene->addItem(titleText);

    // create the play button
    Button* startGameButton = new Button(QString("Start Game"));
    startGameButton->setPos(100,80);
    connect(startGameButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(startGameButton);

    // create quit button
    Button* quit = new Button(QString("Quit"));
    quit->setPos(400,80);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    noviceCard = new Card();
    noviceCard->setPixmap(QPixmap(":/images/noviceIcon.png"));
    noviceCard->setScale(0.75);
    noviceCard->setPos(50,250);
    scene->addItem(noviceCard);
    connect(noviceCard,SIGNAL(clicked()),this,SLOT(clickNoviceCard()));

    superNoviceCard = new Card();
    superNoviceCard->setPixmap(QPixmap(":/images/superNoviceIcon.png"));
    superNoviceCard->setScale(0.75);
    superNoviceCard->setPos(180,250);
    scene->addItem(superNoviceCard);
    connect(superNoviceCard,SIGNAL(clicked()),this,SLOT(clickSuperNoviceCard()));

    swordmanCard = new Card();
    swordmanCard->setPixmap(QPixmap(":/images/swordmanIcon.png"));
    swordmanCard->setScale(0.75);
    swordmanCard->setPos(50,380);
    scene->addItem(swordmanCard);
    connect(swordmanCard,SIGNAL(clicked()),this,SLOT(clickSwordmanCard()));

    magicanCard = new Card();
    magicanCard->setPixmap(QPixmap(":/images/magicanIcon.png"));
    magicanCard->setScale(0.75);
    magicanCard->setPos(180,380);
    scene->addItem(magicanCard);
    connect(magicanCard,SIGNAL(clicked()),this,SLOT(clickMagicanCard()));

    thiefCard = new Card();
    thiefCard->setPixmap(QPixmap(":/images/thiefIcon.png"));
    thiefCard->setScale(0.75);
    thiefCard->setPos(310,380);
    scene->addItem(thiefCard);
    connect(thiefCard,SIGNAL(clicked()),this,SLOT(clickThiefCard()));

    acolyteCard = new Card();
    acolyteCard->setPixmap(QPixmap(":/images/acolyteIcon.png"));
    acolyteCard->setScale(0.75);
    acolyteCard->setPos(440,380);
    scene->addItem(acolyteCard);
    connect(acolyteCard,SIGNAL(clicked()),this,SLOT(clickAcolyteCard()));

    archerCard = new Card();
    archerCard->setPixmap(QPixmap(":/images/archerIcon.png"));
    archerCard->setScale(0.75);
    archerCard->setPos(570,380);
    scene->addItem(archerCard);
    connect(archerCard,SIGNAL(clicked()),this,SLOT(clickArcherCard()));

    merchantCard = new Card();
    merchantCard->setPixmap(QPixmap(":/images/merchantIcon.png"));
    merchantCard->setScale(0.75);
    merchantCard->setPos(700,380);
    scene->addItem(merchantCard);
    connect(merchantCard,SIGNAL(clicked()),this,SLOT(clickMerchantCard()));

    knightCard = new Card();
    knightCard->setPixmap(QPixmap(":/images/knightIcon.png"));
    knightCard->setScale(0.75);
    knightCard->setPos(50,510);
    scene->addItem(knightCard);
    connect(knightCard,SIGNAL(clicked()),this,SLOT(clickKnightCard()));

    assassinCard = new Card();
    assassinCard->setPixmap(QPixmap(":/images/assassinIcon.png"));
    assassinCard->setScale(0.75);
    assassinCard->setPos(180,510);
    scene->addItem(assassinCard);
    connect(assassinCard,SIGNAL(clicked()),this,SLOT(clickAssassinCard()));

    wizardCard = new Card();
    wizardCard->setPixmap(QPixmap(":/images/wizardIcon.png"));
    wizardCard->setScale(0.75);
    wizardCard->setPos(310,510);
    scene->addItem(wizardCard);
    connect(wizardCard,SIGNAL(clicked()),this,SLOT(clickWizardCard()));

    hunterCard = new Card();
    hunterCard->setPixmap(QPixmap(":/images/hunterIcon.png"));
    hunterCard->setScale(0.75);
    hunterCard->setPos(440,510);
    scene->addItem(hunterCard);
    connect(hunterCard,SIGNAL(clicked()),this,SLOT(clickHunterCard()));

    priestCard = new Card();
    priestCard->setPixmap(QPixmap(":/images/priestIcon.png"));
    priestCard->setScale(0.75);
    priestCard->setPos(570,510);
    scene->addItem(priestCard);
    connect(priestCard,SIGNAL(clicked()),this,SLOT(clickPriestCard()));

    alchemistCard = new Card();
    alchemistCard->setPixmap(QPixmap(":/images/alchemistIcon.png"));
    alchemistCard->setScale(0.75);
    alchemistCard->setPos(700,510);
    scene->addItem(alchemistCard);
    connect(alchemistCard,SIGNAL(clicked()),this,SLOT(clickAlchemistCard()));

    ninjaCard = new Card();
    ninjaCard->setPixmap(QPixmap(":/images/ninjaIcon.png"));
    ninjaCard->setScale(0.75);
    ninjaCard->setPos(50,640);
    scene->addItem(ninjaCard);
    connect(ninjaCard,SIGNAL(clicked()),this,SLOT(clickNinjaCard()));

    sageCard = new Card();
    sageCard->setPixmap(QPixmap(":/images/sageIcon.png"));
    sageCard->setScale(0.75);
    sageCard->setPos(180,640);
    scene->addItem(sageCard);
    connect(sageCard,SIGNAL(clicked()),this,SLOT(clickSageCard()));

    monkCard = new Card();
    monkCard->setPixmap(QPixmap(":/images/monkIcon.png"));
    monkCard->setScale(0.75);
    monkCard->setPos(310,640);
    scene->addItem(monkCard);
    connect(monkCard,SIGNAL(clicked()),this,SLOT(clickMonkCard()));

    bardCard = new Card();
    bardCard->setPixmap(QPixmap(":/images/bardIcon.png"));
    bardCard->setScale(0.75);
    bardCard->setPos(440,640);
    scene->addItem(bardCard);
    connect(bardCard,SIGNAL(clicked()),this,SLOT(clickBardCard()));

    professorCard = new Card();
    professorCard->setPixmap(QPixmap(":/images/professorIcon.png"));
    professorCard->setScale(0.75);
    professorCard->setPos(570,640);
    scene->addItem(professorCard);
    connect(professorCard,SIGNAL(clicked()),this,SLOT(clickProfessorCard()));

    taekwondoCard = new Card();
    taekwondoCard->setPixmap(QPixmap(":/images/taekwondoIcon.png"));
    taekwondoCard->setScale(0.75);
    taekwondoCard->setPos(700,640);
    scene->addItem(taekwondoCard);
    connect(taekwondoCard,SIGNAL(clicked()),this,SLOT(clickTaekwondoCard()));
}

void Game::clickNoviceCard()
{
    clickNoviceCardNum += 1;

    if (clickNoviceCardNum %2 != 0 )
    {
        noviceCard->setPixmap(QPixmap(":/images/noviceIconC.png"));
        cardWanted[0] = 1;
    }
    else if(clickNoviceCardNum %2 == 0 )
    {
        noviceCard->setPixmap(QPixmap(":/images/noviceIcon.png"));
        cardWanted[0] = 0;
    }
}

void Game::clickSuperNoviceCard()
{
    clickSuperNoviceCardNum += 1;

    if (clickSuperNoviceCardNum %2 != 0 )
    {
        superNoviceCard->setPixmap(QPixmap(":/images/superNoviceIconC.png"));
        cardWanted[1] = 1;
    }
    else if(clickSuperNoviceCardNum %2 == 0 )
    {
        superNoviceCard->setPixmap(QPixmap(":/images/superNoviceIcon.png"));
        cardWanted[1] = 0;
    }
}

void Game::clickSwordmanCard()
{
    clickSwordmanCardNum += 1;
    if (clickSwordmanCardNum %2 != 0 )
    {
        swordmanCard->setPixmap(QPixmap(":/images/swordmanIconC.png"));
        cardWanted[2] = 1;
    }
    else if(clickSwordmanCardNum %2 == 0 )
    {
        swordmanCard->setPixmap(QPixmap(":/images/swordmanIcon.png"));
        cardWanted[2] = 0;
    }
}

void Game::clickThiefCard()
{
    clickThiefCardNum += 1;
    if (clickThiefCardNum %2 != 0 )
    {
        thiefCard->setPixmap(QPixmap(":/images/thiefIconC.png"));
        cardWanted[3] = 1;
    }
    else if(clickThiefCardNum %2 == 0 )
    {
        thiefCard->setPixmap(QPixmap(":/images/thiefIcon.png"));
        cardWanted[3] = 0;
    }
}

void Game::clickMagicanCard()
{
    clickMagicanCardNum += 1;

    if (clickMagicanCardNum %2 != 0 )
    {
        magicanCard->setPixmap(QPixmap(":/images/magicanIconC.png"));
        cardWanted[4] = 1;
    }
    else if(clickMagicanCardNum %2 == 0 )
    {
        magicanCard->setPixmap(QPixmap(":/images/magicanIcon.png"));
        cardWanted[4] = 0;
    }
}

void Game::clickAcolyteCard()
{
    clickAcolyteCardNum += 1;

    if (clickAcolyteCardNum %2 != 0 )
    {
        acolyteCard->setPixmap(QPixmap(":/images/acolyteIconC.png"));
        cardWanted[5] = 1;
    }
    else if(clickAcolyteCardNum %2 == 0 )
    {
        acolyteCard->setPixmap(QPixmap(":/images/acolyteIcon.png"));
        cardWanted[5] = 0;
    }
}

void Game::clickArcherCard()
{
    clickArcherCardNum += 1;

    if (clickArcherCardNum %2 != 0 )
    {
        archerCard->setPixmap(QPixmap(":/images/archerIconC.png"));
        cardWanted[6] = 1;
    }
    else if(clickArcherCardNum %2 == 0 )
    {
        archerCard->setPixmap(QPixmap(":/images/archerIcon.png"));
        cardWanted[6] = 0;
    }
}

void Game::clickMerchantCard()
{
    clickMerchantCardNum += 1;

    if (clickMerchantCardNum %2 != 0 )
    {
        merchantCard->setPixmap(QPixmap(":/images/merchantIconC.png"));
        cardWanted[7] = 1;
    }
    else if(clickMerchantCardNum %2 == 0 )
    {
        merchantCard->setPixmap(QPixmap(":/images/merchantIcon.png"));
        cardWanted[7] = 0;
    }
}
void Game::clickKnightCard()
{
    clickKnightCardNum += 1;

    if (clickKnightCardNum %2 != 0 )
    {
        knightCard->setPixmap(QPixmap(":/images/knightIconC.png"));
        cardWanted[8] = 1;
    }
    else if(clickKnightCardNum %2 == 0 )
    {
        knightCard->setPixmap(QPixmap(":/images/knightIcon.png"));
        cardWanted[8] = 0;
    }
}

void Game::clickAssassinCard()
{
    clickAssassinCardNum += 1;

    if (clickAssassinCardNum %2 != 0 )
    {
        assassinCard->setPixmap(QPixmap(":/images/assassinIconC.png"));
        cardWanted[9] = 1;
    }
    else if(clickAssassinCardNum %2 == 0 )
    {
        assassinCard->setPixmap(QPixmap(":/images/assassinIcon.png"));
        cardWanted[9] = 0;
    }
}

void Game::clickWizardCard()
{
    clickWizardCardNum += 1;

    if (clickWizardCardNum %2 != 0 )
    {
        wizardCard->setPixmap(QPixmap(":/images/wizardIconC.png"));
        cardWanted[10] = 1;
    }
    else if(clickWizardCardNum %2 == 0 )
    {
        wizardCard->setPixmap(QPixmap(":/images/wizardIcon.png"));
        cardWanted[10] = 0;
    }
}

void Game::clickPriestCard()
{
    clickPriestCardNum += 1;

    if (clickPriestCardNum %2 != 0 )
    {
        priestCard->setPixmap(QPixmap(":/images/priestIconC.png"));
        cardWanted[11] = 1;
    }
    else if(clickPriestCardNum %2 == 0 )
    {
        priestCard->setPixmap(QPixmap(":/images/priestIcon.png"));
        cardWanted[11] = 0;
    }
}

void Game::clickHunterCard()
{
    clickHunterCardNum += 1;

    if (clickHunterCardNum %2 != 0 )
    {
        hunterCard->setPixmap(QPixmap(":/images/hunterIconC.png"));
        cardWanted[12] = 1;
    }
    else if(clickHunterCardNum %2 == 0 )
    {
        hunterCard->setPixmap(QPixmap(":/images/hunterIcon.png"));
        cardWanted[12] = 0;
    }
}

void Game::clickAlchemistCard()
{
    clickAlchemistCardNum += 1;

    if (clickAlchemistCardNum %2 != 0 )
    {
        alchemistCard->setPixmap(QPixmap(":/images/alchemistIconC.png"));
        cardWanted[13] = 1;
    }
    else if(clickAlchemistCardNum %2 == 0 )
    {
        alchemistCard->setPixmap(QPixmap(":/images/alchemistIcon.png"));
        cardWanted[13] = 0;
    }
}

void Game::clickNinjaCard()
{
    clickNinjaCardNum += 1;

    if (clickNinjaCardNum %2 != 0 )
    {
        ninjaCard->setPixmap(QPixmap(":/images/ninjaIconC.png"));
        cardWanted[14] = 1;
    }
    else if(clickNinjaCardNum %2 == 0 )
    {
        ninjaCard->setPixmap(QPixmap(":/images/ninjaIcon.png"));
        cardWanted[14] = 0;
    }
}

void Game::clickSageCard()
{
    clickSageCardNum += 1;

    if (clickSageCardNum %2 != 0 )
    {
        sageCard->setPixmap(QPixmap(":/images/sageIconC.png"));
        cardWanted[15] = 1;
    }
    else if(clickSageCardNum %2 == 0 )
    {
        sageCard->setPixmap(QPixmap(":/images/sageIcon.png"));
        cardWanted[15] = 0;
    }
}

void Game::clickMonkCard()
{
    clickMonkCardNum += 1;

    if (clickMonkCardNum %2 != 0 )
    {
        monkCard->setPixmap(QPixmap(":/images/monkIconC.png"));
        cardWanted[16] = 1;
    }
    else if(clickMonkCardNum %2 == 0 )
    {
        monkCard->setPixmap(QPixmap(":/images/monkIcon.png"));
        cardWanted[16] = 0;
    }
}

void Game::clickBardCard()
{
    clickBardCardNum += 1;

    if (clickBardCardNum %2 != 0 )
    {
        bardCard->setPixmap(QPixmap(":/images/bardIconC.png"));
        cardWanted[17] = 1;
    }
    else if(clickBardCardNum %2 == 0 )
    {
        bardCard->setPixmap(QPixmap(":/images/bardIcon.png"));
        cardWanted[17] = 0;
    }
}

void Game::clickProfessorCard()
{
    clickProfessorCardNum += 1;

    if (clickProfessorCardNum %2 != 0 )
    {
        professorCard->setPixmap(QPixmap(":/images/professorIconC.png"));
        cardWanted[18] = 1;
    }
    else if(clickProfessorCardNum %2 == 0 )
    {
        professorCard->setPixmap(QPixmap(":/images/professorIcon.png"));
        cardWanted[18] = 0;
    }
}

void Game::clickTaekwondoCard()
{
    clickTaekwondoCardNum += 1;

    if (clickTaekwondoCardNum %2 != 0 )
    {
        taekwondoCard->setPixmap(QPixmap(":/images/taekwondoIconC.png"));
        cardWanted[19] = 1;
    }
    else if(clickTaekwondoCardNum %2 == 0 )
    {
        taekwondoCard->setPixmap(QPixmap(":/images/taekwondoIcon.png"));
        cardWanted[19] = 0;
    }
}

void Game::start()
{
    // clear the screen
    scene->clear();
    scene->setSceneRect(0,0,1000,550);

    mainTheme->stop();
    delete mainTheme;

    // play background music
    bgMusic = new QMediaPlayer();
    bgMusic->setMedia(QUrl("qrc:/music/streamside.mp3"));
    bgMusic->setVolume(20);
    bgMusic->play();

    //set the cursor
    cursor = nullptr;

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

    setCountTower(3);
    setCountCave(3);

    int Xpos;
    int cardPlaced = 0;

    if(cardWanted[0] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }

        NoviceIcon * noviceIC = new NoviceIcon(Xpos,450);
        scene->addItem(noviceIC);
        cardWanted[0] = 0;
        cardPlaced += 1;

    }
    if(cardWanted[1] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        SuperNoviceIcon * superNoviceIC = new SuperNoviceIcon(Xpos,450);
        scene->addItem(superNoviceIC);
        cardWanted[1] = 0;
        cardPlaced += 1;
    }

    if(cardWanted[2] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        SwordmanIcon * swordmanIC = new SwordmanIcon(Xpos,450);
        scene->addItem(swordmanIC);
        cardWanted[2] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[3] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        ThiefIcon * thiefIC = new ThiefIcon(Xpos,450);
        scene->addItem(thiefIC);
        cardWanted[3] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[4] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        MagicanIcon * magicanIC = new MagicanIcon(Xpos,450);
        scene->addItem(magicanIC);
        cardWanted[4] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[5] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        AcolyteIcon * acolyteIC = new AcolyteIcon(Xpos,450);
        scene->addItem(acolyteIC);
        cardWanted[5] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[6] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        ArcherIcon * archerIC = new ArcherIcon(Xpos,450);
        scene->addItem(archerIC);
        cardWanted[6] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[7] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        MerchantIcon * merchantIC = new MerchantIcon(Xpos,450);
        scene->addItem(merchantIC);
        cardWanted[7] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[8] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        KnightIcon * knightIC = new KnightIcon(Xpos,450);
        scene->addItem(knightIC);
        cardWanted[8] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[9] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        AssassinIcon * assassinIC = new AssassinIcon(Xpos,450);
        scene->addItem(assassinIC);
        cardWanted[9] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[10] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        WizardIcon * wizardIC = new WizardIcon(Xpos,450);
        scene->addItem(wizardIC);
        cardWanted[10] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[11] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        PriestIcon * priestIC = new PriestIcon(Xpos,450);
        scene->addItem(priestIC);
        cardWanted[11] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[12] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        HunterIcon * hunterIC = new HunterIcon(Xpos,450);
        scene->addItem(hunterIC);
        cardWanted[12] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[13] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        AlchemistIcon * alchemistIC = new AlchemistIcon(Xpos,450);
        scene->addItem(alchemistIC);
        cardWanted[13] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[14] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        NinjaIcon * ninjaIC = new NinjaIcon(Xpos,450);
        scene->addItem(ninjaIC);
        cardWanted[14] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[15] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        SageIcon * sageIC = new SageIcon(Xpos,450);
        scene->addItem(sageIC);
        cardWanted[15] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[16] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        MonkIcon * monkIC = new MonkIcon(Xpos,450);
        scene->addItem(monkIC);
        cardWanted[16] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[17] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        BardIcon * bardIC = new BardIcon(Xpos,450);
        scene->addItem(bardIC);
        cardWanted[17] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[18] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        ProfessorIcon * professorIC = new ProfessorIcon(Xpos,450);
        scene->addItem(professorIC);
        cardWanted[18] = 0;
        cardPlaced += 1;
    }
    if (cardWanted[19] == 1)
    {
        if(cardPlaced == 0)
        {
            Xpos = 10;
        }
        else if(cardPlaced == 1)
        {
            Xpos = 115;
        }
        else if(cardPlaced == 2)
        {
            Xpos = 220;
        }
        else if(cardPlaced == 3)
        {
            Xpos = 325;
        }
        TaekwondoIcon * taekwondoIC = new TaekwondoIcon(Xpos,450);
        scene->addItem(taekwondoIC);
        cardWanted[19] = 0;
        cardPlaced += 1;
    }


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
    displayMainMenu();
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
