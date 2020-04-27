#ifndef LOAD_H
#define LOAD_H

#include "point.h"
#include "link.h"
#include "model.h"

typedef struct loadInfo
{
    char *filename;
} loadInfo;

void FormLoadInfo(loadInfo &load, char *filename);

errorCode ReadCount(int &count, FILE *file);
errorCode LoadPoints(pointArray &points, FILE *file);
errorCode LoadLinks(linkArray &links, FILE *file);

#endif
