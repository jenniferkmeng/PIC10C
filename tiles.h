/**
 *@class Tiles
 *@author Jennifer Meng
 *@date June 04, 2015
 *@brief Represents a barrier in the Game
 *
 * The Tiles class creates objects that the Player cannot pass through. They also are used to create the border for the Game.
*/

#ifndef TILES_H
#define TILES_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

#include "game.h"

class Tiles: public QObject, public QGraphicsPixmapItem{

    Q_OBJECT

public:

    /**
     * @brief Default Constructor
     * Draws the Tiles from a QPixmap
     * @param parent is set to 0 if it has no parent
     */
    Tiles(QGraphicsItem* parent = 0);

    /**
     * @brief Destructor
     */
    ~Tiles();

public slots:
};


#endif // TILES_H

