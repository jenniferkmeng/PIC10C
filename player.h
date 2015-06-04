/**
 *@class Player
 *@author Jennifer Meng
 *@date June 04, 2015
 *@brief Represents the Player of the Game
 *
 * The Player class handles a variety of functions available to the user. It handles KeyPressEvents, the creation of Bombs,
 * movement and collision checking. Whenever a Player object is created, it creates Health and Score that is distinct and
 * unique only to that Player. The spawing of Enemies, trees and Stars are handled by the Player as well. As long as there
 * is a Player in the Game, they will keep spawning.
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "health.h"
#include "score.h"
#include "bomb.h"

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsItem>
#include <QList>

#include <QGraphicsTextItem>

class Player: public QObject, public QGraphicsPixmapItem{

    Q_OBJECT // QObject macro

public:

    /**
     * @brief Default Constructor
     * Score and Health are both created during the construction of a Player. The Player also has the ability to create
     * Bombsounds as well from this constructor.
     * @param parent is set to 0 if it has no parent.
     */
    Player(QGraphicsItem* parent = 0);

    /**
     * @brief Destructor
     */
    ~Player();

    /**
     * @brief keyPressEvent controls all the Keys pressed by the user during Gameplay
     * This function also checks for collision and handles the increment/decrement of Health and Score when needed.
     * @param event is the key pressed
     */
    void keyPressEvent(QKeyEvent* event);

    Health* p1health;
    Score* p1score;
    Bomb* p1bomb;

    /**
     * @brief Calls on the Health's decrease function
     */
    void decreaseHealth();

    /**
     * @brief Getter for Player's Health
     * @return An int value of Player's Health
     */
    int getP1Health();

    /**
     * @brief Calls on the Score's increase function
     */
    void increaseScore();

    /**
     * @brief Calls on the Score's increaseStar function
     */
    void increaseScoreStars();

    /**
     * @brief Calls on the Score's decrease function
     */
    void decreaseScore();

    /**
     * @brief Getter for Player's Score
     * @return An int value of Player's Score
     */
    int getP1Score();

    /**
     * @brief Creates the sounds for the Bombs when created by Player's key press
     */
    void bombsoundfn();

public slots:

    /**
     * @brief Spawns Enemies as long as there is a Player
     */
    void spawn();

    /**
     * @brief Spawns Stars as long as there is a Player
     */
    void spawnStars();

    /**
     * @brief Spawns trees as long as there is a Player
     */
    void spawnTrees();

private:
    QMediaPlayer* bombsound;
};
#endif // PLAYER_H

