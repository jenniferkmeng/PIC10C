/**
 *@class IntroScreen
 *@author Jennifer Meng
 *@date June 04, 2015
 *@brief Represents the starting screen of the game
 *
 * The IntroScreen class uses the created Ui to dispay options for the user. From this screen, users can read the
 * instructions and select the difficulty mode for the Game.
*/

#ifndef INTROSCREEN_H
#define INTROSCREEN_H

#include "instructions.h"
#include "game.h"

#include <QWidget>
#include <QHBoxLayout>


namespace Ui {
class IntroScreen;
}

class IntroScreen : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief Default Constructor
     * @param parent is set to 0 if it has no parent
     */
    explicit IntroScreen(QWidget *parent = 0);

    /**
     * @brief Destructor
     */
    ~IntroScreen();

public slots:

    /**
     * @brief Slot for the creation of the Game in easy mode.
     * These slots are activated when pressed.
     */
    void Easy();

    /**
     * @brief Slot for the creation of the Game in medium mode.
     * These slots are activated when pressed.
     */
    void Medium();

    /**
     * @brief Slot for the creation of the Game in hard mode.
     * These slots are activated when pressed.
     */
    void Hard();

    /**
     * @brief Shows the instructions window for the Game.
     * These slots are activated when pressed.
     */
    void ShowInstructions();


private:
    Ui::IntroScreen *ui;

    QDialog* instructions;

    QHBoxLayout* layout;
    QWidget* w;

};


#endif // INTROSCREEN_H
