/**
 *@class Instructions
 *@author Jennifer Meng
 *@date June 04, 2015
 *@brief Represents the Game's instructions
 *
 * The instructions show up in another window from the IntroScreen when the user wants to view it. Users have the option
 * of reviewing the options whenever the Game is run in the beginning before gameplay.
*/

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <QDialog>

namespace Ui {
class Instructions;
}

class Instructions : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief Default Constructor
     * @param parent is set to 0 if it has no parent
     */
    explicit Instructions(QWidget *parent = 0);

    /**
     * @brief Destructor
     */
    ~Instructions();

private:
    Ui::Instructions *ui;
};

#endif // INSTRUCTIONS_H
