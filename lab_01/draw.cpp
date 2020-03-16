#include "draw.h"

errorCode FormDrawInfo(drawInfo &drawSetup, QGraphicsView *drawView)
{
    errorCode error = SUCCES;
    drawSetup.graphicsView = drawView;
    if (!drawView)
    {
        error = INVALID_ARGUMENT;
    }

    return error;
}
