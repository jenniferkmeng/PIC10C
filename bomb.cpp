#include "bomb.h"
#include "game.h"
#include "player.h"
#include "enemy.h"
#include "destructibletiles.h"
#include "tiles.h"

#include <QTimer>
#include <QGraphicsScene>

#include <QDebug>

Bomb::Bomb(QGraphicsItem* parent): QObject(), QGraphicsPixmapItem(parent){

    // Draw graphics
    setPixmap(QPixmap(":/Images/bomb.png"));
    //game->player->p1score

}
Bomb Bomb::Up(){

    // Connect the slots; make/connect a timer to move() the bomb every so often
    // Set a time, everytime that time goes to 0, its signal will execute
    QTimer* timer = new QTimer();

    // Connects timeout from timer to move
    connect(timer, SIGNAL(timeout()), this, SLOT(moveUp()));

    // Sets timer;s time to 50ms; every 50ms the bomb will move
    timer->start(50);

    return this;
}

Bomb Bomb::Left(){
/*
    // Draw graphics
    setPixmap(QPixmap(":/Images/bomb.png"));
*/

    // Connect the slots; make/connect a timer to move() the bomb every so often
    // Set a time, everytime that time goes to 0, its signal will execute
    QTimer* timer = new QTimer();

    // Connects timeout from timer to move
    connect(timer, SIGNAL(timeout()), this, SLOT(moveLeft()));

    // Sets timer;s time to 50ms; every 50ms the bomb will move
    timer->start(50);

    return this;
}

Bomb Bomb::Right(){

    // Draw graphics
    setPixmap(QPixmap(":/Images/bomb.png"));


    // Connect the slots; make/connect a timer to move() the bomb every so often
    // Set a time, everytime that time goes to 0, its signal will execute
    QTimer* timer = new QTimer();

    // Connects timeout from timer to move
    connect(timer, SIGNAL(timeout()), this, SLOT(moveRight()));

    // Sets timer;s time to 50ms; every 50ms the bomb will move
    timer->start(50);

    return this;
}

Bomb Bomb::Down(){

    // Draw graphics
    setPixmap(QPixmap(":/Images/bomb.png"));


    // Connect the slots; make/connect a timer to move() the bomb every so often
    // Set a time, everytime that time goes to 0, its signal will execute
    QTimer* timer = new QTimer();

    // Connects timeout from timer to move
    connect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));

    // Sets timer;s time to 50ms; every 50ms the bomb will move
    timer->start(50);

    return this;

}

void Bomb::collisioncheck()
{

    // Check if player's bombs collide with enemy
    QList<QGraphicsItem*> collidingstuff = this->collidingItems(); // Houses all the stuff that the bomb collides with
    //collidingstuff = collidingItems();
    // Traverse the list and find out if bomb collides with an enemy
    for (int i = 0, n = collidingstuff.size(); i < n; ++i){
        if (typeid( *(collidingstuff[i]) ) == typeid(Enemy)){

            // Increase the score
            game->player->increaseScore();

            // Remove both the bomb and the enemy
            scene()->removeItem( collidingstuff[i] );
            scene()->removeItem(this);

            return;

        }
        if (typeid( *(collidingstuff[i]) ) == typeid(DestructibleTiles)){

            // Remove both the bomb and the tile
            scene()->removeItem(collidingstuff[i]);
            scene()->removeItem(this);

            return;

        }
        if (typeid( *(collidingstuff[i]) ) == typeid(Tiles)){

            scene()->removeItem(this);
            return;
        }

    }
}


Bomb::~Bomb()
{

}

// Default movement of bombs is upwards
void Bomb::moveUp(){

    collisioncheck();

    // Just move bomb up
    setPos(x(), y()-20);

}

void Bomb::moveRight(){

    collisioncheck();

    // Just move bomb right
    setPos(x()+20, y());

}

void Bomb::moveLeft(){

    collisioncheck();

    // Just move bomb left
    setPos(x()-20, y());

}

void Bomb::moveDown()
{
    collisioncheck();

    // Just move bomb down
    setPos(x(), y()+20);

}



