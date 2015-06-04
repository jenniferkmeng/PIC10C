/**
  @mainpage Foreign Alien Invasion
  @author Jennifer Meng
  @date June 04, 2015
  @brief Foreign Alien Invasion is a game created using C++ and Qt for UCLA's PIC10C course.

  @section Controls Summary
  - Move the player with the arrow keys
  - Shoot bombs in respective directions using the W, A, S, D keys

  @section Gameplay Summary
  The player is always located at the top right corner when a game is started. During gameplay, enemies, trees that are destructible
  and stars are spawn at random locations and on anything until the player dies. The main objective is to stay alive and earn as many
  points as possible. Collect stars and kill enemies for increase the score. Run into an enemy or an enemy running into the player
  will deduct 1 healh and 25 points. At end of gameplay, score will be outputted under "Application Output" on the Qt console.

*/

/**
 *@class Game
 *@author Jennifer Meng
 *@date June 04, 2015
 *@brief The Game class is a custom class derived from QGraphicsView. It provides a widget for displaying the contents of a QGraphicsScene.
 *
 * The Game class handles all the objects used in the game. It is arguably the most important class in this project. The Game class is
 * public since all the game objects need access to all its functions and attributes. This class handles the QGraphicsScene, Player,
 * Key Board Events, the spawning of Stars, Trees and Enemies, setting up the Game layout and music.
*/

#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>

#include "player.h"
#include "score.h"
#include "health.h"

class Game;
extern Game* game;

class Game: public QGraphicsView{

    Q_OBJECT

public:
    // Member functions

    /**
     * @brief Default Constructor
     * @param parent is initialized to 0 if it has no parent
     * @param ESPAWNSPEED is the spawn rate for enemies
     * @param SSPAWNSPEED is the spawn rate for stars
     * @param TSPAWNSPEED is the spawn rate for trees
     */
    Game(QWidget* parent = 0, int ESPAWNSPEED = 2000, int SSPAWNSPEED = 1500, int TSPAWNSPEED = 3000);

    /**
     * @brief Destructor
     */
    ~Game();

    // Attributes made public due to requirement for all other classes to access
    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health* health;

signals:

private:

    int GAMEX = 850; // Width dimension for the Game
    int GAMEY = 850; // Height dimension for the Game

    int ESPAWNSPEED; // Enemy spawn rate
    int SSPAWNSPEED; // Stars spawn rate
    int TSPAWNSPEED; // Trees spawn rate
};

#endif // GAME_H
