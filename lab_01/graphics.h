#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "QGraphicsView"
#include "draw.h"

#include "point_array.h"
#include "link_array.h"
#include "point_draw.h"

typedef struct graphics
{
    QGraphicsScene *scene;
    QPen pen;
    int height;
    int width;
} graphics;

void CreateGraphics(graphics &graphicsView, drawInfo &draw);
void DeleteGraphics(graphics &graphicsView);

void UpdateGraph(graphics &graph);
errorCode UpdateDraw(drawInfo &draw, graphics &scene);

void AddPointDrawOffset(pointDraw &drawingPoint, graphics &draw);

int GetHeight(graphics &draw);
int GetWidth(graphics &draw);

errorCode DrawLinks(graphics &draw, pointArray &points, linkArray &links);
errorCode DrawLink(graphics &draw, pointArray &points, link &drawingLink);
void DrawLine(graphics &draw, pointDraw &firstPoint, pointDraw &secondPoint);


#endif // GRAPHICS_H
