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
        model tempModel = GetNullModel();

        error = LoadPoints(tempModel.points, file);
        if (error == SUCCES)
        {
            error = LoadLinks(tempModel.links, file);
            if (error != SUCCES)
            {
                PointsFree(tempModel.points);
            }
            else
            {
                ReassignmentModel(loadingModel, tempModel);
            }
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

void ReassignmentModel(model &destModel, model &sourceModel)
{
    DestructModel(destModel);
    ReassignmentPoints(destModel.points, sourceModel.points);
    ReassignmentLinks(destModel.links, sourceModel.links);
}
