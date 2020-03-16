#include "model.h"
#include "stdio.h"
#include "graphics.h"

model GetNullModel()
{
    model tempModel;
    SetZeroLinks(tempModel.links);
    SetZeroPoints(tempModel.points);

    return tempModel;
}

errorCode DestructModel(model &destructingModel)
{
    LinksFree(destructingModel.links);
    PointsFree(destructingModel.points);

    return SUCCES;
}

errorCode LoadModel(model &loadingModel, loadInfo &load)
{
    errorCode error = SUCCES;
    FILE *file = fopen(load.filename, "r");

    if (!file)
    {
        error = FILE_ERROR;
    }
    else
    {
        error = LoadPoints(loadingModel.points, file);
        if (error == SUCCES)
        {
            error = LoadLinks(loadingModel.links, file);
        }
        fclose(file);
    }

    return error;
}

errorCode DrawModel(model &drawingModel, drawInfo &draw)
{
    graphics graph;
    CreateGraphics(graph, draw);

    errorCode error = DrawLinks(graph, drawingModel.points, drawingModel.links);
    UpdateGraph(graph);
    UpdateDraw(draw, graph);
    DeleteGraphics(graph);

    return error;
}

errorCode MoveModel(model &movingModel, moveInfo &move)
{
    return MovePoints(movingModel.points, move);
}

errorCode RotateModel(model &rotatingModel, rotateInfo &rotate)
{
    return RotatePoints(rotatingModel.points, rotate);
}

errorCode ScaleModel(model &scalingModel, scaleInfo &scale)
{
    return ScalePoints(scalingModel.points, scale);
}
