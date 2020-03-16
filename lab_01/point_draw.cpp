#include "point_draw.h"

errorCode GetPointDraw(pointDraw &receivedPoint, pointArray &points, int index)
{
    point tempPoint;
    errorCode error = GetPoint(tempPoint, points, index);
    if (error == SUCCES)
    {
        receivedPoint.x = (int)tempPoint.x;
        receivedPoint.y = (int)tempPoint.y;
    }

    return error;
}
