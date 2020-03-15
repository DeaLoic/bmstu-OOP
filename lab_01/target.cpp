#include "target.h"
#include "model.h"

errorCode TargetProcessing(target &pointTarget)
{
    static model mainModel = GetNullModel();

    errorCode error = SUCCES;
    switch (pointTarget.type)
    {
    case INIT:
        break;
    case LOAD:
        error = LoadModel(mainModel, pointTarget.load);
        break;
    case DESTRUCT:
        error = DestructModel(mainModel);
        break;
    case DRAW:
        error = DrawModel(mainModel, pointTarget.draw);
        break;
    case MOVE:
        error = MoveModel(mainModel, pointTarget.move);
        break;
    case ROTATE:
        error = RotateModel(mainModel, pointTarget.rotate);
        break;
    case SCALE:
        error = ScaleModel(mainModel, pointTarget.scale);
        break;
    default:
        error = INVALID_ARGUMENT;
    }

    return error;
}

void FormTargetInit(target& targetInit)
{
    targetInit.type = INIT;
}

void FormTargetDestruct(target& targetDestruct)
{
    targetDestruct.type = DESTRUCT;
}

void FormTargetLoad(target &targetLoad, loadInfo &loadSetup)
{
    targetLoad.type = LOAD;
    targetLoad.load = loadSetup;
}

void FormTargetDraw(target &targetDraw, drawInfo &drawSetup)
{
    targetDraw.type = DRAW;
    targetDraw.draw = drawSetup;
}

void FormTargetMove(target &targetMove, moveInfo &moveSetup)
{
    targetMove.type = MOVE;
    targetMove.move = moveSetup;
}

void FormTargetRotate(target &targetRotate, rotateInfo &rotateSetup)
{
    targetRotate.type = ROTATE;
    targetRotate.rotate = rotateSetup;
}

void FormTargetScale(target &targetScale, scaleInfo &scaleSetup)
{
    targetScale.type = SCALE;
    targetScale.scale = scaleSetup;
}
