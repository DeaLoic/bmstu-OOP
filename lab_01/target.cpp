#include "target.h"
#include "model.h"

errorCode TargetProcessing(target &pointTarget)
{
    
}

void FormTargetInit(target& targetInit)
{
    targetInit.type = INIT;
    return SUCCES;
}

void FormTargetDestruct(target& targetDestruct)
{
    targetDestruct.type = DESTRUCT;
    return SUCCES;
}

void FormTargetLoad(target &targetLoad, loadInfo &loadSetup)
{
    targetLoad.type = LOAD;
    targetLoad.info.load = loadSetup;
}

void FormTargetDraw(target &targetDraw, drawInfo &drawSetup)
{
    targetDraw.type = DRAW;
    targetDraw.info.draw = drawSetup;
}

void FormTargetMove(target &targetMove, moveInfo &moveSetup)
{
    targetMove.type = MOVE;
    targetMove.info.move = moveSetup;
}

void FormTargetRotate(target &targetRotate, rotateInfo &rotateSetup)
{
    targetRotate.type = ROTATE;
    targetRotate.info.rotate = rotateSetup;
}

void FormTargetScale(target &targetRotate, scaleInfo &scaleSetup)
{
    targetScale.type = SCALE;
    targetScale.info.scale = scaleSetup;
}