/**
 *@class Bomb
 *@author Jennifer Meng
 *@date June 04, 2015
 *@brief Represents an object used to kill Enemies or destroy trees (Destructible Tiles)
 *
 * The Bomb class is a QGraphicsPixmapItem which will move in the direction that the Player chooses based on the
 * Keyboard Key pressed. If it collides with an Enemy, score is increased. If it collides with a tree, it will be
 * removed. Once the Bomb has collided with any object, it will be removed from the Game.
*/

#ifndef BOMB_H
#define BOMB_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QList>

#include "score.h"

class Bomb: public QObject, public QGraphicsPixmapItem{

    Q_OBJECT

    friend class Player;
    friend class Game;

public:
    /**
     * @brief Default Constructor
     * @param parent is initialized to 0 if it has no parent
     */
    Bomb(QGraphicsItem* parent = 0);

    /**
     * @brief Creates a timer which will update/move the Bomb upwards every 50ms
     * @return A Bomb object set in the new position
     */
    Bomb Up();

    /**
     * @brief Creates a timer which will update/move the Bomb left every 50ms
     * @return A Bomb object set in the new position
     */
    Bomb Left();

    /**
     * @brief Creates a timer which will update/move the Bomb right every 50ms
     * @return A Bomb object set in the new position
     */
    Bomb Right();

    /**
     * @brief Creates a timer which will update/move the Bomb downwards every 50ms
     * @return A Bomb object set in the new position
     */
    Bomb Down();

    /**
     * @brief Creates a QList of QGraphicsItems based off of the collidingItems() function for QGraphicsItems.
     *
     * This function provides a means to check if the Bomb has collided with any other game object
     */
    void collisioncheck();

    /**
     * @brief Destructor
     */
    ~Bomb();


public slots:

    /**
     * @brief This function first checks for collision then updates the position for upward movement
     *
     * This slot is used to connect to a timer so that whenever the countdown ends, this action is performed.
     */
    void moveUp();

    /**
     * @brief This function first checks for collision then updates the position for rightward movement
     *
     * This slot is used to connect to a timer so that whenever the countdown ends, this action is performed.
     */
    void moveRight();

    /**
     * @brief This function first checks for collision then updates the position for leftward movement
     *
     * This slot is used to connect to a timer so that whenever the countdown ends, this action is performed.
     */
    void moveLeft();

    /**
     * @brief This function first checks for collision then updates the position for downward movement
     *
     * This slot is used to connect to a timer so that whenever the countdown ends, this action is performed.
     */
    void moveDown();

private:

};

#endif // BOMB_H
