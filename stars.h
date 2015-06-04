/**
 *@class Stars
 *@author Jennifer Meng
 *@date June 04, 2015
 *@brief Represents objects that the Player collects
 *
 * The Stars class is the main class that creates an object for 50 points each. So technically, these objects are the
 * main way to accumulate points and increase the score quickly.
*/

#ifndef STARS_H
#define STARS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

#include "game.h"

class Stars: public QObject, public QGraphicsPixmapItem{

    Q_OBJECT

public:

    /**
     * @brief Default Constructor
     * Draws the Stars from a QPixmap
     * @param parent is set to 0 if it has no parent
     */
    Stars(QGraphicsItem* parent = 0);

    /**
     * @brief Destructor
     */
    ~Stars();

public slots:
};


#endif // STARS_H

