#ifndef POINT_H
#define POINT_H

#include "error_code.h"
#include "stdio.h"

typedef struct point
{
    double x;
    double y;
    double z;
} point;

typedef struct pointArray
{
    int size;
    point *array;
} pointArray;

void FormPoint(point &formingPoint, double x, double y, double z);
errorCode ReadPoint(point &readingPoint, FILE *file);

errorCode GetPoint(point &receviedPoint, pointArray &points, int index);
void SetZeroPoints(pointArray &points);
errorCode ReadPointsByCount(pointArray &points, FILE *file, int count);
errorCode PointsAllocate(pointArray &points, int size);
void PointsFree(pointArray &points);

#endif // POINT_H
