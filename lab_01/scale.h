#ifndef SCALE_H
#define SCALE_H

#include "error_code.h"
#include "point.h"
#include "point_array.h"

typedef struct scaleInfo
{
    double scaleX;
    double scaleY;
    double scaleZ;
} scaleInfo;

void FormScaleInfo(scaleInfo &scale, double scaleX, double scaleY, double scaleZ);

void ScalePoint(point &scalingPoint, scaleInfo &scale);
errorCode ScalePoints(pointArray &points, scaleInfo &scale);

#endif
