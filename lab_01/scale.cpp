#include "scale.h"

void FormScaleInfo(scaleInfo &scale, double scaleX, double scaleY, double scaleZ)
{
    scale.scaleX = scaleX;
    scale.scaleY = scaleY;
    scale.scaleZ = scaleZ;
}

void ScalePoint(point &scalingPoint, scaleInfo &scale)
{
    scalingPoint.x *= scale.scaleX;
    scalingPoint.y *= scale.scaleY;
    scalingPoint.z *= scale.scaleZ;
}

errorCode ScalePoints(pointArray &points, scaleInfo &scale)
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
            ScalePoint(points.array[i], scale);
        }
    }

    return error;
}