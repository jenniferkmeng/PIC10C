#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "game.h"



class Gameboard : public QWidget
{
    Q_OBJECT



public slots:

signals:
    void GameOver();

public:
    explicit Gameboard(QWidget *parent = 0);
    ~Gameboard();

private:
    Game* game;


};


#endif // GAMEBOARD_H

