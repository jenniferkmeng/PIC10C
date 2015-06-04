#include "stars.h"
#include <QGraphicsScene>
#include <chrono>
#include <random>
#include <stdlib.h>

#define SEED (unsigned int)std::chrono::system_clock::now().time_since_epoch().count()
#define DEFAULT std::default_random_engine

Stars::Stars(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    // Draw graphics
    setPixmap(QPixmap(":/Images/stars.png"));

    // Place in random location on the Game
    DEFAULT generator(SEED);
    std::uniform_int_distribution<int> distribution(1,15);
    int PosX = distribution(generator)*50;
    int PosY = distribution(generator)*50;

    setPos(PosX,PosY);

}

Stars::~Stars()
{

}

