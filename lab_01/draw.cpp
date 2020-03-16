#include "draw.h"

errorCode FormDrawInfo(drawInfo &drawSetup, QGraphicsView *drawScene)
{
    errorCode error = SUCCES;
    drawSetup.graphicsView = drawScene;
    if (!drawScene)
    {
        error = INVALID_ARGUMENT;
    }

    return error;
}
