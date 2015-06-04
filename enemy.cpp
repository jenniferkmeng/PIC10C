#include "enemy.h"
#include "game.h"
#include "tiles.h"
#include "destructibletiles.h"
#include "score.h"
#include "health.h"
#include "stars.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>

#include <stdlib.h>
#include <random>
#include <chrono>

#include <QDebug>

extern Game* game;

#define SEED (unsigned int)std::chrono::system_clock::now().time_since_epoch().count()
#define DEFAULT std::default_random_engine

Enemy::Enemy(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent){

    // Set Random position
    DEFAULT generator(SEED);
    std::uniform_int_distribution<int> distribution(1,15);
    int PosX = distribution(generator)*50;
    int PosY = distribution(generator)*50;

    setPos(PosX,PosY);

    // Draw enemy
    setPixmap(QPixmap(":/Images/p3_front.png"));

    // Connect the slots
    // Set a time, everytime that time goes to 0, its signal will execute
    QTimer* timer = new QTimer();
    // Connects timeout from timer to move
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // Sets timer;s time to 2000ms (2s); every 2s the enemy will move
    timer->start(2000);

}

Enemy::~Enemy(){

}

void Enemy::move(){

    DEFAULT gen(SEED);
    std::uniform_int_distribution<int> distribution(0, 5);


    int movementX = distribution(gen)*50;
    int movementY = distribution(gen)*50;

    setPos(x() + movementX, y() + movementY);

    // Check if enemy collides with game objects
    QList<QGraphicsItem*> collidingstuff = collidingItems(); // Houses all the stuff that the enemies collide with
    for (int i = 0, n = collidingstuff.size(); i < n; ++i){

        // If enemy moves and collides with player,
        if (typeid( *(collidingstuff[i]) ) == typeid(Player)){

            qDebug() << "Enemy Collided with Player";

            // Decrease the health and score
            game->player->decreaseHealth();
            game->player->decreaseScore();

            return;

        }

        // If enemy moves and collides with any type of tiles,
        if (typeid( *(collidingstuff[i]) ) == typeid(Tiles) || typeid( *(collidingstuff[i]) ) == typeid(DestructibleTiles)){

            // Go back to old location
            setPos(x() - movementX, y()- movementY);

            return;

       }

       // If enemy runs into another enemy ,
       if (typeid( *(collidingstuff[i]) ) == typeid(Enemy)){

           // Delete the current enemy
           delete this;

           return;
       }

       // If enemy runs into stars,
       if (typeid( *(collidingstuff[i]) ) == typeid(Stars)){

           // Remove the star from the scene
           scene()->removeItem(collidingstuff[i]);

           return;
       }
    }

    // If enemy moves out of the screen,
    if (pos().y() > 800 || pos().x() > 800){

        // Set its position inside
        setPos(x() - 5*movementX, y() - 5*movementY);
        // Make it move again
        move();
    }
}


