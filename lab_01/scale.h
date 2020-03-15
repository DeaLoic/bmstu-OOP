#ifndef SCALE_H
#define SCALE_H

#include "error_code.h"
#include "point.h"

typedef struct scaleInfo
{
    double scaleX;
    double scaleY;
    double scaleZ;
} scaleInfo;

errorCode ScalePoint(point &scalingPoint, scaleInfo &scale);

#endif