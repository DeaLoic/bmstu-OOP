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
