#include "point_array.h"

errorCode GetPoint(point &receviedPoint, pointArray &points, int index)
{
    errorCode error = SUCCES;
    if (points.size <= 0 || points.size <= index)
    {
        error = INVALID_ARGUMENT;
    }
    else
    {
        receviedPoint = points.array[index];
    }

    return error;
}

void SetZeroPoints(pointArray &points)
{
    points.size = 0;
    points.array = nullptr;
}

void ReassignmentPoints(pointArray &destPoints, pointArray &sourcePoints)
{
    destPoints.size = sourcePoints.size;
    destPoints.array = sourcePoints.array;
}

errorCode ReadPointsByCount(pointArray &points, FILE *file, int count)
{
    errorCode error = SUCCES;
    if (!file || count < 0)
    {
        error = INVALID_ARGUMENT;
    }
    else
    {
        pointArray tempPoints;
        error = PointsAllocate(tempPoints, count);
        tempPoints.size = count;
        for (int i = 0; i < count && error == SUCCES; i++)
        {
            error = ReadPoint(tempPoints.array[i], file);
        }

        if (error != SUCCES)
        {
            PointsFree(tempPoints);
        }
        else
        {
            ReassignmentPoints(points, tempPoints);
        }
    }

    return error;
}

errorCode PointsAllocate(pointArray &points, int size)
{
    errorCode error = SUCCES;
    if (size < 0)
    {
        error = INVALID_ARGUMENT;
    }
    else
    {
        points.array = new point [size];
        if (points.array == nullptr && size != 0)
        {
            error = MEMORY_ERROR;
            SetZeroPoints(points);
        }
    }

    return error;
}

void PointsFree(pointArray &points)
{
    delete points.array;
    SetZeroPoints(points);
}
