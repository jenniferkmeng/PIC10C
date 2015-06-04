#include "health.h"
#include "score.h"
#include "player.h"
#include "game.h"

#include "mainwindow.h"
#include <QString>
#include <QFont>
#include <QApplication>

#include <QDebug>

Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent){

    health = 2;
    // Draw the health (text)
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(QColor(239,86,116));
    setFont(QFont("Century Gothic", 16, QFont::Bold));
}

Health::~Health()
{

}

void Health::decrease(){

    qDebug() << "Health Decreased";
    prepareGeometryChange();
    health--;
    // Text is updated
    setPlainText(QString("Health: ") + QString::number(health));
    update();
}


int Health::getHealth(){

    return health;
}

