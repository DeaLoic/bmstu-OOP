#ifndef POINT_ARRAY_H
#define POINT_ARRAY_H

#include "point.h"

typedef struct pointArray
{
    int size;
    point *array;
} pointArray;

errorCode GetPoint(point &receviedPoint, pointArray &points, int index);
void SetZeroPoints(pointArray &points);
void ReassignmentPoints(pointArray &destPoints, pointArray &sourcePoints);

errorCode ReadPointsByCount(pointArray &points, FILE *file, int count);
errorCode PointsAllocate(pointArray &points, int size);
void PointsFree(pointArray &points);

#endif // POINT_ARRAY_H
