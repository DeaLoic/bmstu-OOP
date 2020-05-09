#ifndef DRAW_H
#define DRAW_H

#include "QGraphicsView"
#include "error_code.h"

typedef struct drawInfo
{
    QGraphicsView *graphicsView;
} drawInfo;

errorCode FormDrawInfo(drawInfo &drawSetup, QGraphicsView *drawView);

#endif // DRAW_H
