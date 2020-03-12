#ifndef POINT_H
#define POINT_H

typedef struct point
{
    double x;
    double y;
    double z;
} point;

void FormPoint(point &formingPoint, double x, double y, double z);

#endif // POINT_H
