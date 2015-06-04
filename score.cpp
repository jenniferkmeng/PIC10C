#include "score.h"
#include "game.h"
#include "player.h"

#include "mainwindow.h"
#include <QString>
#include <QFont>
#include <QApplication>

#include <QDebug>

extern Game* game;
extern Player* player;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){

    // Initialize Score to 0
    score = 0;

    // Draw the score (text)
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(QColor(86,239,209));
    setFont(QFont("Century Gothic", 16, QFont::Bold));
}

Score::~Score()
{

}

void Score::increase(){

    qDebug() << "Score Increased";
    prepareGeometryChange();
    ++score;
    // Text is updated
    setPlainText(QString("Score: ") + QString::number(score));
    update();
}

void Score::increaseStar()
{

    qDebug() << "Score Increased";
    prepareGeometryChange();
    score = score + 50;
    // Text is updated
    setPlainText(QString("Score: ") + QString::number(score));
    update();
}

void Score::decrease()
{
    qDebug() << "Score Decreased";

    prepareGeometryChange();
    score = score - 25;
    setPlainText(QString("Score: ") + QString::number(score));
    update();
}

int Score::getScore(){

    return score;
}
