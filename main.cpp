#include <QApplication>
#include "game.h"
#include "introscreen.h"

// External global variable so that all classes can access it
Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    IntroScreen* intro = new IntroScreen();
    intro->show();

    return a.exec();
}
