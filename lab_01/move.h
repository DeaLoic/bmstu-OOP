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

void FormMoveInfo(moveInfo &move, double dx, double dy, double dz);

void MovePoint(point &movingPoint, moveInfo &move);
errorCode MovePoints(pointArray &points, moveInfo &move);


#endif