/**
 *@class Health
 *@author Jennifer Meng
 *@date June 04, 2015
 *@brief Represents the Player's Health
 *
 * The Health class is a QGraphicsTextItem that updates the health whenever it decreases.
*/

#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QObject>

class Health: public QGraphicsTextItem{

    Q_OBJECT

    friend class Player;
    friend class Game;

public:

    /**
     * @brief Default Constructor
     * Health by default is initialized to 2.
     * @param parent is set to 0 if it has no parent
     */
    Health(QGraphicsItem* parent = 0); // If no parent, it doesnt have a parent

    /**
     * @brief Destructor
     */
    ~Health();

    /**
     * @brief Decreases the health by 1
     */
    void decrease(); // To increase the health

    /**
     * @brief Getter for Health
     * @return An int value for health
     */
    int getHealth(); // Getter for health

signals:

private:
    int health;
};

#endif // HEALTH_H

