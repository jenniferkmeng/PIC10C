
#include "tiles.h"
#include <QGraphicsScene>


Tiles::Tiles(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    // Draw graphics
    setPixmap(QPixmap(":/Images/boxAlt.png"));
    setTransformOriginPoint(25, 25);
    setRotation(180); // Set rotation to 180 degrees

}

Tiles::~Tiles()
{

}
