#include "move.h"

void FormMoveInfo(moveInfo &move, double dx, double dy, double dz)
{
    move.dx = dx;
    move.dy = dy;
    move.dz = dz;
}

void MovePoint(point &movingPoint, moveInfo &move)
{
    movingPoint.x += move.dx;
    movingPoint.y += move.dy;
    movingPoint.z += move.dz;
}

errorCode MovePoints(pointArray &points, moveInfo &move)
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
            MovePoint(points.array[i], move);
        }
    }

    return error;
}