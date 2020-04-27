#ifndef DRAW_H
#define DRAW_H

#include "QGraphicsView"
#include "error_code.h"
#include "graphics.h"
typedef struct drawInfo
{
    QGraphicsView *graphicsView;
} drawInfo;

errorCode FormDrawInfo(drawInfo &drawSetup, QGraphicsView *drawScene);
void UpdateGraphicsView(drawInfo &draw, graphics &graph);

#endif // DRAW_H
