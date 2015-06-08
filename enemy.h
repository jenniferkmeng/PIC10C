/**
 *@class Enemy
 *@author Jennifer Meng
 *@date June 04, 2015
 *@brief Represents an object that hurts the Player
 *
 * The Enemy class represents enemies that the Player has to avoid in order to not die. They move randomly and increase
 * in quantity with time.
*/

#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QList>


class Enemy: public QObject, public QGraphicsPixmapItem{

    Q_OBJECT

public:

    /**
     * @brief Default Constructor
     * @param parent is set to 0 if it has no parent
     */
    Enemy(QGraphicsItem* parent = 0);

    /**
     * @brief Destructor
     */
    ~Enemy();

public slots:

    /**
     * @brief This function moves the Enemy object to a random location in the Scene.
     *
     * It checks for collision between objects first, then places it in the location randomly generated by a random
     * number generator.
     */
    void move();
};

#endif // ENEMY_H