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

void FormPoint(point &formingPoint, double x, double y, double z);
errorCode ReadPoint(point &readingPoint, FILE *file);

#endif // POINT_H
