#ifndef ROTATE_H
#define ROTATE_H

#include "error_code.h"
#include "point.h"

typedef struct rotateInfo
{
    double radiansX;
    double radiansY;
    double radiansZ;
} rotateInfo;

void RotatePoint(point &rotatingPoint, rotateInfo &rotate);
errorCode RotatePoints(pointArray &points, rotateInfo &rotate);

#endif