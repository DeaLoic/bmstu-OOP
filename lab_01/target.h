#ifndef TARGET_H
#define TARGET_H

#include "error_code.h"

typedef enum targetType
{
    INIT,
    DESTRUCT,
    DRAW,
    MOVE,
    ROTATE,
} targetType;

typedef struct target
{
    targetType type;
    union
    {
        initInfo init;
        desturctInfo destruct;
        drawInfo draw;
        moveInfo move;
        rotateInfo rotate;
    } info;
} target;

errorCode TargetProcessing(target pointTarget);

errorCode FormTargetInit(target& targetInit);
errorCode FormTargetDestruct(target& targetDestruct);
errorCode FormTargetDraw(target& targetDraw);
errorCode FormTargetMove(target& targetMove, double moveX, double moveY, double moveZ);
errorCode FormTargetRotate(target& targetRotate, double rotateX, double rotateY, double rotateZ);
errorCode FormTargetScale(target& targetRotate, double scaleX, double scaleY, double scaleZ);

#endif // TARGET_H
