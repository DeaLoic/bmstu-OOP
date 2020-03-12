#ifndef DRAW_H
#define DRAW_H

#include "QGraphicsView"
#include "error_code.h"
typedef struct draw
{
    QGraphicsScene *scene;
    QPen pen;
} draw;

errorCode FormDraw(draw &drawSetup, QGraphicsScene drawScene, QPen pen);

#endif // DRAW_H
