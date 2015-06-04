#include "player.h"
#include "game.h"
#include "bomb.h"
#include "enemy.h"
#include "destructibletiles.h"
#include "tiles.h"
#include "stars.h"

#include <QKeyEvent>
#include <QGraphicsScene>

#include <QDebug>

extern Game* game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    p1health = new Health();
    p1score = new Score();

    // Player has potential to make bomb sound
    bombsound = new QMediaPlayer();
    bombsound->setMedia(QUrl("qrc:/Sounds/Explosion.mp3"));

    // Draw player
    setPixmap(QPixmap(":/Images/p1_front.png"));

}

Player::~Player()
{

}

void Player::keyPressEvent(QKeyEvent *event)
{
    // qDebug() << "Player knows that you pressed a key";

    // If the left key was pressed
    if (event->key() == Qt::Key_Left){

        // Check if position of player is within the screen
        if ((pos().x() > 0) ) {

            // Move to temp position
            setPos(x()-50, y());

            // Check to see if the temp position is any Tile
            QList<QGraphicsItem*> collidingstuff = this->collidingItems(); // Houses all the stuff that the bomb collides with

            for (int i = 0, n = collidingstuff.size(); i < n; ++i){
                if (typeid( *(collidingstuff[i]) ) == typeid(Tiles) || typeid( *(collidingstuff[i]) ) == typeid(DestructibleTiles)){

                    qDebug() << "Collided with Tiles";

                    // Go back to old position if item in front is any tile
                    setPos(x()+50, y());

                    return;
                }
                if (typeid( *(collidingstuff[i]) ) == typeid(Enemy)){

                    qDebug() << "Player collided with Enemy, Left Key";

                    decreaseScore();
                    decreaseHealth();

                    scene()->removeItem(collidingstuff[i]);

                }

                if (typeid( *(collidingstuff[i]) ) == typeid(Stars)){

                    qDebug() << "Player collected a star";

                    increaseScoreStars();

                    scene()->removeItem(collidingstuff[i]);

                    delete collidingstuff[i];

                }
            }
        }
    }

    // If the right key was pressed
    if (event->key() == Qt::Key_Right){

        if (pos().x() + 50 < 800) {

            // First move player to a temp position
            setPos(x()+50, y());

            // Check to see if the temp position is any Tile
            QList<QGraphicsItem*> collidingstuff = this->collidingItems(); // Houses all the stuff that the bomb collides with

            for (int i = 0, n = collidingstuff.size(); i < n; ++i){
                if (typeid( *(collidingstuff[i]) ) == typeid(Tiles) || typeid( *(collidingstuff[i]) ) == typeid(DestructibleTiles)){

                    qDebug() << "Collided with Tiles";

                    // Go back to old position if item in front is any tile
                    setPos(x()-50, y());

                    return;
                }
                if (typeid( *(collidingstuff[i]) ) == typeid(Enemy)){

                    qDebug() << "Player collided with Enemy, Right Key";

                    decreaseScore();
                    decreaseHealth();

                    scene()->removeItem(collidingstuff[i]);

                    //delete collidingstuff[i];

                }

                if (typeid( *(collidingstuff[i]) ) == typeid(Stars)){

                    qDebug() << "Player collected a star";

                    increaseScoreStars();

                    scene()->removeItem(collidingstuff[i]);

                    scene()->update();

                    delete collidingstuff[i];

                }
            }
        }
    }
    // If the up key was pressed
    if (event->key() == Qt::Key_Up){

        if (pos().y() > 0){

            // First move player to a temp position
            setPos(x(), y()-50);
            // 0,0 at the top left corner

            // Check to see if the temp position is any Tile
            QList<QGraphicsItem*> collidingstuff = this->collidingItems(); // Houses all the stuff that the bomb collides with

            for (int i = 0, n = collidingstuff.size(); i < n; ++i){
               if (typeid( *(collidingstuff[i]) ) == typeid(Tiles) || typeid( *(collidingstuff[i]) ) == typeid(DestructibleTiles)){

                   qDebug() << "Collided with Tiles";

                   // Go back to old position if item in front is any tile
                   setPos(x(), y()+50);

                   return;
               }
               if (typeid( *(collidingstuff[i]) ) == typeid(Enemy)){

                    qDebug() << "Player collided with Enemy, Up Key";

                    decreaseScore();
                    decreaseHealth();

                    scene()->removeItem(collidingstuff[i]);


                }
                if (typeid( *(collidingstuff[i]) ) == typeid(Stars)){

                    qDebug() << "Player collected a star";

                    increaseScoreStars();

                    scene()->removeItem(collidingstuff[i]);

                    delete collidingstuff[i];

                }

            }
        }
    }

    // If the down key was pressed
    if (event->key() == Qt::Key_Down){

        if (pos().y() + 50 < 800) {

            // Move to temp position
            setPos(x(), y()+50);

            // Check to see if the temp position is any Tile
            QList<QGraphicsItem*> collidingstuff = this->collidingItems(); // Houses all the stuff that the bomb collides with

            for (int i = 0, n = collidingstuff.size(); i < n; ++i){

                if (typeid( *(collidingstuff[i]) ) == typeid(Tiles) || typeid( *(collidingstuff[i]) ) == typeid(DestructibleTiles)){

                    setPos(x(), y()-50);

                    return;
                } if (typeid( *(collidingstuff[i]) ) == typeid(Enemy)){

                    qDebug() << "Player collided with Enemy, Down Key";

                    decreaseScore();
                    decreaseHealth();

                    scene()->removeItem(collidingstuff[i]);

                } if (typeid( *(collidingstuff[i]) ) == typeid(Stars)){

                    qDebug() << "Player collected a star";

                    increaseScoreStars();

                    scene()->removeItem(collidingstuff[i]);

                    delete collidingstuff[i];
                }
            }
        }
    }

    // If the space bar was pressed, by default, bombs move up
    if (event->key() == Qt::Key_Space){

        // Create Bomb
        p1bomb = new Bomb();
        // qDebug() << "Bomb created";
        p1bomb->Up();

        // Set position of bomb
        p1bomb->setPos(x(), y());

        // Add to the scene; all QGraphicsItem has a pointer to the screen
        scene()->addItem(p1bomb);

        if (p1bomb->pos().x() > 850 || p1bomb->pos().y() > 850){

            scene()->removeItem(p1bomb);
            delete p1bomb;
        }

        bombsoundfn();

    }

    // If the "a" key is pressed, bombs move left
    if (event->key() == Qt::Key_A){

        // Create Bomb
        p1bomb = new Bomb();
        // qDebug() << "Bomb created";
        p1bomb->Left();

        // Set position of bomb
        p1bomb->setPos(x(), y());

        // Add to the scene; all QGraphicsItem has a pointer to the screen
        scene()->addItem(p1bomb);

        bombsoundfn();

    }

    // If the "s" key is pressed, bombs move down
    if (event->key() == Qt::Key_S){

        // Create Bomb
        p1bomb = new Bomb();
        // qDebug() << "Bomb created";
        p1bomb->Down();


        // Set position of bomb
        p1bomb->setPos(x(), y());

        // Add to the scene; all QGraphicsItem has a pointer to the screen
        scene()->addItem(p1bomb);

        bombsoundfn();

    }

    // If the "d" key is pressed, bombs move right
    if (event->key() == Qt::Key_D){

        // Create Bomb
        p1bomb = new Bomb();
        // qDebug() << "Bomb created";
        p1bomb->Right();


        // Set position of bomb
        p1bomb->setPos(x(), y());

        // Add to the scene; all QGraphicsItem has a pointer to the screen
        scene()->addItem(p1bomb);

        bombsoundfn();

    }

    // If the "w" key is pressed, bombs move up
    if (event->key() == Qt::Key_W){

        // Create Bomb
        p1bomb = new Bomb();
        // qDebug() << "Bomb created";
        p1bomb->Up();


        // Set position of bomb
        p1bomb->setPos(x(), y());

        // Add to the scene; all QGraphicsItem has a pointer to the screen
        scene()->addItem(p1bomb);

        bombsoundfn();

    }

}

void Player::decreaseHealth()
{

    p1health->decrease();

    if (p1health->health <= 0){

        qDebug() << "You died. " << "You scored " << game->player->getP1Score() << "!";
        game->close();
        game->parentWidget()->close();

    }

}

int Player::getP1Health()
{
    return p1health->getHealth();
}

void Player::increaseScore()
{
    p1score->increase();
}

void Player::increaseScoreStars()
{
    p1score->increaseStar();
}

void Player::decreaseScore()
{
    p1score->decrease();
}

int Player::getP1Score()
{
    return p1score->getScore();
}

void Player::bombsoundfn()
{
    // Play bomb sound
    // Checks to see if sound is still playing
    if (bombsound->state() == QMediaPlayer::PlayingState){
        bombsound->setPosition(0);
    } else if (bombsound->state() == QMediaPlayer::StoppedState){
        bombsound->play();
    }
}

void Player::spawn(){

    // Create enemy
    Enemy* enemy = new Enemy();
    // Adds enemy into scene
    scene()->addItem(enemy);

}

void Player::spawnStars()
{
    // Create stars for points
    Stars* strs = new Stars();
    // Adds stars into scene
    scene()->addItem(strs);
}

void Player::spawnTrees()
{
    // Create trees
    DestructibleTiles* dts = new DestructibleTiles();
    // Adds trees into scene
    scene()->addItem(dts);
}
