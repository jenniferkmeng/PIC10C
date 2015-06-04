#include "game.h"
#include "bomb.h"
#include "enemy.h"
#include "destructibletiles.h"
#include "tiles.h"
#include "stars.h"

#include <QApplication>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QBrush>
#include <QImage>

#include <QMediaPlayer>
#include <QMediaPlaylist>

#include <chrono>
#include <random>

#include <QDebug>

#define SEED (unsigned int)std::chrono::system_clock::now().time_since_epoch().count()
#define DEFAULT std::default_random_engine

Game::Game(QWidget *parent, int ess, int sss, int tss):QGraphicsView(parent),
    ESPAWNSPEED(ess), SSPAWNSPEED(sss), TSPAWNSPEED(tss){

    // Create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,GAMEX,GAMEY); // Makes the scene 850x850 instead of infinity
    setBackgroundBrush(QBrush(QImage(":/Images/BG Center Tile.png")));

    // Make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // It can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(GAMEX,GAMEY);

    // Create the player
    player = new Player();
    player->setPos(50, 50); // Sets position of player at the top left

    // Make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // Add the player to the scene
    scene->addItem(player);


    // Set Up Board

        // Outside Perimeter
    int i = 0;
    do {
        Tiles* TopX = new Tiles();
        Tiles* LeftY = new Tiles();
        Tiles* BottomX = new Tiles();
        Tiles* RightY = new Tiles();
        TopX->setPos(i, 0);
        LeftY->setPos(0, i);
        BottomX->setPos(i, GAMEY-50);
        RightY->setPos(GAMEX-50, i);
        scene->addItem(TopX);
        scene->addItem(LeftY);
        scene->addItem(BottomX);
        scene->addItem(RightY);
        i = i + 50;
    } while (i <= GAMEX);

        // Inside Blocks
    int j = 100; // x coordinates
    int k = 100; // y coordinates
    do {

        Tiles* xy = new Tiles();
        if (j%100 == 0){
            xy->setPos(j, k);
            scene->addItem(xy);
            j+=50;
            k+=50;
        } else {
            j+=50;
            k+=50;
        }
    } while (j <= GAMEX-150);

    int l = 700;
    int m = 100;
    do {
        Tiles* yx = new Tiles();
        if (l%100 == 0){
            yx->setPos(l, m);
            scene->addItem(yx);
            l-=50;
            m+=50;
        } else {
            l-=50;
            m+=50;
        }
    }while (l >= 100);

    int a = 100;
    int b = 100;
    do {

        Tiles* TopInX = new Tiles();
        TopInX->setPos(a, b);
        scene->addItem(TopInX);
        a+=100;

    }while (a <= GAMEX - 150);

    a = 100;
    do {

        Tiles* LeftInY = new Tiles();
        LeftInY->setPos(a, b);
        scene->addItem(LeftInY);
        b+=100;
    }while (b <= GAMEY - 150);

    a = 700;
    b = 100;
    do {
        Tiles* RightInY = new Tiles();
        RightInY->setPos(a, b);
        scene->addItem(RightInY);
        b+=100;
    }while (b <= GAMEY - 150);

    a = 100;
    b = 700;
    do {
        Tiles* BottomInX = new Tiles();
        BottomInX->setPos(a, b);
        scene->addItem(BottomInX);
        a+=100;
    }while (a <= GAMEX -150);

    // Adds score into the scene
    scene->addItem(player->p1score);

    // Adds health into the scene
    player->p1health->setPos(x(), y()+25);
    scene->addItem(player->p1health);

    // Spawn enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(ESPAWNSPEED);

    // Create initial enemy at bottom right corner
    Enemy* E1 = new Enemy();
    E1->setPos(750, 750);
    scene->addItem(E1);

    // Generate random trees (destructible tiles)
    QTimer* ttimer = new QTimer();
    QObject::connect(ttimer,SIGNAL(timeout()),player,SLOT(spawnTrees()));
    ttimer->start(TSPAWNSPEED);

    // Generate random stars
    QTimer* stimer = new QTimer();
    QObject::connect(stimer,SIGNAL(timeout()),player,SLOT(spawnStars()));
    stimer->start(SSPAWNSPEED);

    // Play background music
    QMediaPlaylist* playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/Sounds/BG Music.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    QMediaPlayer* BG = new QMediaPlayer();
    BG->setPlaylist(playlist);
    BG->play();

    show();

    QCoreApplication::processEvents();

}


Game::~Game()
{

}




