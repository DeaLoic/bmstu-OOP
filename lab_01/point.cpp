#include "point.h"

void FormPoint(point &formingPoint, double x, double y, double z)
{
    formingPoint.x = x;
    formingPoint.y = y;
    formingPoint.z = z;
}

errorCode ReadPoint(point &readingPoint, FILE *file)
{
    errorCode error = SUCCES;
    if (!file)
    {
        error = INVALID_ARGUMENT;
    }
    else
    {
        double currentX, currentY, currentZ;
        if (fscanf(file, "%lf %lf %lf", &currentX, &currentY, &currentZ) != 3)
        {
            error = PARSE_ERROR;
        }
        else
        {
            FormPoint(readingPoint, currentX, currentY, currentZ);
        }
    }

    return error;
}

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

errorCode ReadPointsByCount(pointArray &points, FILE *file, int count)
{
    errorCode error = SUCCES;
    if (!file || count < 0)
    {
        error = INVALID_ARGUMENT;
    }
    else
    {
        error = PointsAllocate(points, count);
        points.size = count;
        for (int i = 0; i < count && error == SUCCES; i++)
        {
            error = ReadPoint(points.array[i], file);
        }

        if (error != SUCCES)
        {
            PointsFree(points);
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
