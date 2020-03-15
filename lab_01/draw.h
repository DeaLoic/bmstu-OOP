#ifndef DRAW_H
#define DRAW_H

#include "QGraphicsView"
#include "error_code.h"

typedef struct drawInfo
{
    QGraphicsScene *scene;
    QPen pen;
} drawInfo;

errorCode FormDraw(drawInfo &drawSetup, QGraphicsScene drawScene, QPen pen);

#endif // DRAW_H
