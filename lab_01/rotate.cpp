#include "rotate.h"
#include "math.h"

void FormRotateInfo(rotateInfo &move, double degreeX, double degreeY, double degreeZ)
{
    move.degreeX = degreeX;
    move.degreeY = degreeY;
    move.degreeZ = degreeZ;
}

double DegreeToRadian(double angleInDegree)
{
    return angleInDegree * M_PI / 180;
}

double SinDegree(double angleInDegree)
{
    return sin(DegreeToRadian(angleInDegree));
}

double CosDegree(double angleInDegree)
{
    return cos(DegreeToRadian(angleInDegree));
}

void RotatePoint(point &rotatingPoint, rotateInfo &rotate)
{
    RotateDimensionX(rotatingPoint, rotate.degreeX);
    RotateDimensionY(rotatingPoint, rotate.degreeY);
    RotateDimensionZ(rotatingPoint, rotate.degreeZ);
}

void RotateDimensionX(point &rotatingPoint, double angle)
{
    double cosAngle = CosDegree(angle);
    double sinAngle = SinDegree(angle);

    rotatingPoint.y = rotatingPoint.y * cosAngle + rotatingPoint.z * sinAngle;
    rotatingPoint.z = -rotatingPoint.y * sinAngle + rotatingPoint.z * cosAngle;
}

void RotateDimensionY(point &rotatingPoint, double angle)
{
    double cosAngle = CosDegree(angle);
    double sinAngle = SinDegree(angle);

    rotatingPoint.x = rotatingPoint.x * cosAngle + rotatingPoint.z * sinAngle;
    rotatingPoint.z = -rotatingPoint.x * sinAngle + rotatingPoint.z * cosAngle;
}

void RotateDimensionZ(point &rotatingPoint, double angle)
{
    double cosAngle = CosDegree(angle);
    double sinAngle = SinDegree(angle);

    rotatingPoint.x = rotatingPoint.x * cosAngle + rotatingPoint.y * sinAngle;
    rotatingPoint.y = -rotatingPoint.x * sinAngle + rotatingPoint.y * cosAngle;
}

errorCode RotatePoints(pointArray &points, rotateInfo &rotate)
{
    errorCode error = SUCCES;

    if (points.array == nullptr || points.size <= 0)
    {
        error = INVALID_ARGUMENT;
    }
    else
    {
        for (int i = 0; i < points.size; i++)
        {
            RotatePoint(points.array[i], rotate);
        }
    }

    return error;
}
