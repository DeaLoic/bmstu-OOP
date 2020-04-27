#ifndef TARGET_H
#define TARGET_H

#include "error_code.h"

#include "draw.h"
#include "move.h"
#include "scale.h"
#include "rotate.h"
#include "load.h"

typedef enum targetType
{
    INIT,
    DESTRUCT,
    LOAD,
    DRAW,
    MOVE,
    ROTATE,
    SCALE,
} targetType;

typedef struct target
{
    targetType type;
    union
    {
        loadInfo load;
        drawInfo draw;
        moveInfo move;
        rotateInfo rotate;
        scaleInfo scale;
    };
} target;

errorCode TargetProcessing(target &pointTarget);

void FormTargetInit(target &targetInit);
void FormTargetDestruct(target &targetDestruct);
void FormTargetLoad(target &targetLoad, loadInfo &loadSetup);
void FormTargetDraw(target &targetDraw, drawInfo &drawSetup);
void FormTargetMove(target &targetMove, moveInfo &moveSetup);
void FormTargetRotate(target &targetRotate, rotateInfo &rotateSetup);
void FormTargetScale(target &targetRotate, scaleInfo &scaleSetup);

#endif // TARGET_H
