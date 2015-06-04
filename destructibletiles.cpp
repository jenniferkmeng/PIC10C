#include "destructibletiles.h"
#include "stars.h"
#include "tiles.h"
#include <QGraphicsScene>
#include <chrono>
#include <random>
#include <stdlib.h>

#include <QDebug>

#define SEED (unsigned int)std::chrono::system_clock::now().time_since_epoch().count()
#define DEFAULT std::default_random_engine

DestructibleTiles::DestructibleTiles(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    // Set Random position

    DEFAULT generator(SEED);
    std::uniform_int_distribution<int> distribution(1,15);
    // Mulitplied by 50 so that they will position on a grid like fashion
    int PosX = distribution(generator)*50;
    int PosY = distribution(generator)*50;

    // int randPosition = rand()%775; // To be inside the screen
    setPos(PosX,PosY);

    // Draw graphics
    setPixmap(QPixmap(":/Images/pineSapling.png"));

}

DestructibleTiles::~DestructibleTiles()
{

}

DestructibleTiles DestructibleTiles::generate()
{

    DestructibleTiles* temp = new DestructibleTiles();

    QList<QGraphicsItem*> collidingstuff = this->collidingItems(); // Houses all the stuff that the bomb collides with

    for (int i = 0, n = collidingstuff.size(); i < n; ++i){

        if (typeid( *(collidingstuff[i]) ) == typeid(Tiles) || typeid( *(collidingstuff[i]) ) == typeid(DestructibleTiles)){

            scene()->removeItem((collidingstuff[i]));

            scene()->update();

            delete collidingstuff[i];

            return this;

        } else if (typeid( *(collidingstuff[i]) ) == typeid(Stars)){

            qDebug() << "Created on a star";

            scene()->removeItem(collidingstuff[i]);

            scene()->update();

            delete collidingstuff[i];

            return this;

        } else return this;
    }

    return this;
}


