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

void UpdateGraphicsView(drawInfo &draw, graphics &graph)
{
    QGraphicsScene *prev = draw.graphicsView->scene();
    delete prev;
    draw.graphicsView->setScene(graph.scene);
}
