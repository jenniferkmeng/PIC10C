/**
 *@class Score
 *@author Jennifer Meng
 *@date June 04, 2015
 *@brief Represents the Player's score
 *
 * The Score class is a QGraphicsTextItem that updates the score whenever the Player gains points.
*/

#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QObject>

class Score: public QGraphicsTextItem{

    Q_OBJECT

    friend class Player;
    friend class Game;

public:

    /**
     * @brief Default Constructor
     * This initializes the score to 0 and also draws the text needed for the Player to view their score
     * @param parent is set to 0 if it has no parent
     */
    Score(QGraphicsItem* parent = 0); // If no parent, it doesnt have a parent

    /**
     * @brief Destructor
     */
    ~Score();

    /**
     * @brief Increases the score by 1 point by killing an Enemy
     */
    void increase();

    /**
     * @brief Increases the score by 50 points upon collecting a Star
     */
    void increaseStar();

    /**
     * @brief Decreases score by 25 if Player runs into an Enemy or if Enemy runs into Player
     */
    void decrease();

    /**
     * @brief A Getter function for score
     * @return The int value of score
     */
    int getScore();

private:
    int score;
};

#endif // SCORE_H

