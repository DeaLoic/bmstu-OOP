#ifndef MODEL_H
#define MODEL_H

#include "point.h"
#include "link.h"
#include "load.h"
#include "draw.h"
#include "move.h"
#include "rotate.h"
#include "scale.h"

typedef struct model
{
    pointArray points;
    linkArray links;
};

model GetNullModel();

errorCode DrawModel(model &drawingModel, drawInfo &draw);
errorCode LoadModel(model &loadingModel, loadInfo &load);
errorCode MoveModel(model &movingModel, moveInfo &move);
errorCode RotateModel(model &rotatingModel, rotateInfo &rotate);
errorCode ScaleModel(model &scalingModel, scaleInfo *scale);

#endif