#ifndef ROTATE_H
#define ROTATE_H

#include "error_code.h"
#include "point.h"
#include "point_array.h"

typedef struct rotateInfo
{
    double degreeX;
    double degreeY;
    double degreeZ;
} rotateInfo;


void FormRotateInfo(rotateInfo &move, double degreeX, double degreeY, double degreeZ);

double SinDegree(double angleInDegree);
double CosDegree(double angleInDegree);

void RotatePoint(point &rotatingPoint, rotateInfo &rotate);
void RotateDimensionX(point &rotatingPoint, double angle);
void RotateDimensionY(point &rotatingPoint, double angle);
void RotateDimensionZ(point &rotatingPoint, double angle);
errorCode RotatePoints(pointArray &points, rotateInfo &rotate);

#endif
