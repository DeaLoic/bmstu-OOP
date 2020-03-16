#ifndef POINT_DRAW_H
#define POINT_DRAW_H

#include "point_array.h"

typedef struct pointDraw
{
    int x;
    int y;
} pointDraw;

errorCode GetPointDraw(pointDraw &receivedPoint, pointArray &points, int index);

#endif // POINT_DRAW_H
