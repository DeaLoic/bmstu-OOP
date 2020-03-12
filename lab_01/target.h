#ifndef TARGET_H
#define TARGET_H

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
errorCode FormTargetMove(target& targetMove);
errorCode FormTargetRotate(target& targetRotate);

#endif // TARGET_H
