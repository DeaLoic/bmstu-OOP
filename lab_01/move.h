#ifndef MOVE_H
#define MOVE_H

#include "error_code.h"
#include "point.h"

typedef struct moveInfo
{
    int dx;
    int dy;
    int dz;
} moveInfo;

errorCode MovePoint(point &movingPoint, moveInfo move);

#endif