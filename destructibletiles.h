/**
 *@class DestructibleTiles
 *@author Jennifer Meng
 *@date June 04, 2015
 *@brief Represents an object barrier for Player
 *
 * The DestructibleTiles class is a QGraphicsPixmapItem which creates trees when called. They can be destroyed by Bomb objects
 * but Player will not be able to move pass these objects unless destroyed.
*/

#ifndef DESTRUCTIBLETILES_H
#define DESTRUCTIBLETILES_H

#include "tiles.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

#include "game.h"

class DestructibleTiles: public QObject, public QGraphicsPixmapItem{

    Q_OBJECT

public:

    /**
     * @brief Default Constructor
     * @param parent is set to 0 if it has no parent
     */
    DestructibleTiles(QGraphicsItem* parent = 0);

    /**
     * @brief Destructor
     */
    ~DestructibleTiles();

    /**
     * @brief Generates trees based on the position and location of other Game objects
     * @return A DestructibleTiles object
     */
    DestructibleTiles generate();

public slots:
};


#endif // DESTRUCTIBLETILES_H

