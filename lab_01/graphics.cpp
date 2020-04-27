#include "graphics.h"

void CreateGraphics(graphics &graphicsView, drawInfo &draw)
{
    graphicsView.scene = new QGraphicsScene(draw.graphicsView);
    graphicsView.pen = new QPen(Qt::black);
    graphicsView.height = draw.graphicsView->height();
    graphicsView.width = draw.graphicsView->width();
}

void DeleteGraphics(graphics &graphicsView)
{
    delete graphicsView.scene;
    delete graphicsView.pen;
}

void AddPointDrawOffset(pointDraw &drawingPoint, graphics &draw)
{
    drawingPoint.x += draw.width / 2;
    drawingPoint.y += draw.height / 2;
}

int GetHeight(graphics &draw)
{
    return draw.height;
}
int GetWidth(graphics &draw)
{
    return draw.width;
}

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

errorCode DrawLinks(graphics &draw, pointArray &points, linkArray &links)
{
    errorCode error = SUCCES;
    for (int i = 0; i < links.size && error == SUCCES; i++)
    {
        error = DrawLink(draw, points, links.array[i]);
    }

    return error;
}

errorCode DrawLink(graphics &draw, pointArray &points, link &drawingLink)
{
    pointDraw firstPointDraw, secondPointDraw;
    errorCode error = GetPointDraw(firstPointDraw, points, drawingLink.firstPoint);
    if (error == SUCCES)
    {
        AddPointDrawOffset(firstPointDraw, draw);
        error = GetPointDraw(secondPointDraw, points, drawingLink.secondPoint);
        if (error == SUCCES)
        {
            AddPointDrawOffset(secondPointDraw, draw);
            DrawLine(draw, firstPointDraw, secondPointDraw);
        }
    }

    return error;
}

void DrawLine(graphics &draw, pointDraw &firstPoint, pointDraw &secondPoint)
{
    draw.scene->addLine(firstPoint.x, firstPoint.y, secondPoint.x, secondPoint.y, *(draw.pen));
}

void UpdateScene(graphics &graph)
{
    graph.scene->setSceneRect(QRectF(QPointF(0, 0), QSizeF(graph.height, graph.height)));

}
