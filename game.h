#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <QMediaPlayer>
#include "novice.h"
#include "magican.h"
#include "swordman.h"
#include "thief.h"
#include "sage.h"
#include "card.h"
#include "supernovice.h"
#include "acolyte.h"
#include "archer.h"
#include "merchant.h"
#include "priest.h"
#include "monk.h"
#include "knight.h"
#include "assassin.h"
#include "wizard.h"
#include "hunter.h"
#include "alchemist.h"
#include "ninja.h"
#include "bard.h"
#include "professor.h"
#include "taekwondo.h"


class Game: public QGraphicsView
{
    Q_OBJECT

public:
    Game();
    void setCursor(QString filename);
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void displayMainMenu();
    void setCountTower(int numTower);
    int getCountTower();
    void setCountCave(int numCave);
    int getCountCave();
    void decreaseCountTower();
    void decreaseCountCave();
    void gameOver();
    void displayGameOverWindow(QString textToDisplay);



    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    QMediaPlayer * bgMusic;
    QMediaPlayer * mainTheme;
    QMediaPlayer * bardMusic;
    bool bardPlaying = false;

    Novice * buildNovice;
    Magican * buildMagican;
    Swordman * buildSwordman;
    Thief * buildThief;
    SuperNovice * buildSuperNovice;
    Acolyte * buildAcolyte;
    Archer * buildArcher;
    Merchant * buildMerchant;
    Priest * buildPriest;
    Monk * buildMonk;
    Knight * buildKnight;
    Assassin * buildAssassin;
    Wizard * buildWizard;
    Hunter * buildHunter;
    Alchemist * buildAlchemist;
    Ninja * buildNinja;
    Sage * buildSage;
    Bard * buildBard;
    Professor * buildProfessor;
    Taekwondo * buildTaekwondo;

    Card * noviceCard;
    Card * swordmanCard;
    Card * magicanCard;
    Card * thiefCard;
    Card * superNoviceCard;
    Card * acolyteCard;
    Card * archerCard;
    Card * merchantCard;
    Card * priestCard;
    Card * monkCard;
    Card * knightCard;
    Card * assassinCard;
    Card * wizardCard;
    Card * hunterCard;
    Card * alchemistCard;
    Card * ninjaCard;
    Card * sageCard;
    Card * bardCard;
    Card * professorCard;
    Card * taekwondoCard;

    int clickNoviceCardNum;
    int clickSwordmanCardNum;
    int clickMagicanCardNum;
    int clickThiefCardNum;
    int clickSuperNoviceCardNum;
    int clickAcolyteCardNum;
    int clickArcherCardNum;
    int clickMerchantCardNum;
    int clickPriestCardNum;
    int clickMonkCardNum;
    int clickKnightCardNum;
    int clickAssassinCardNum;
    int clickWizardCardNum;
    int clickHunterCardNum;
    int clickAlchemistCardNum;
    int clickNinjaCardNum;
    int clickSageCardNum;
    int clickBardCardNum;
    int clickProfessorCardNum;
    int clickTaekwondoCardNum;

public slots:
    void start();
    void restartGame();
    void spawnMVP();
    void drawCardWindow();
    void clickNoviceCard();
    void clickSwordmanCard();
    void clickMagicanCard();
    void clickThiefCard();
    void clickSuperNoviceCard();
    void clickAcolyteCard();
    void clickArcherCard();
    void clickMerchantCard();
    void clickPriestCard();
    void clickMonkCard();
    void clickKnightCard();
    void clickAssassinCard();
    void clickWizardCard();
    void clickHunterCard();
    void clickAlchemistCard();
    void clickNinjaCard();
    void clickSageCard();
    void clickBardCard();
    void clickProfessorCard();
    void clickTaekwondoCard();

private:
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    int countTower;
    int countCave;
    int cardWanted[20];

};

#endif // GAME_H
