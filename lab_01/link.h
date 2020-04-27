#ifndef LINK_H
#define LINK_H

#include "error_code.h"
#include "stdio.h"

typedef struct link
{
    int firstPoint;
    int secondPoint;
} link;

typedef struct linkArray
{
    int size;
    link *array;
} linkArray;

void SetZeroLinks(linkArray &links);
void FormLink(link &formingLink, int firstPoint, int secondPoint);
errorCode ReadLink(link &readingLink, FILE *file);

errorCode ReadLinksByCount(linkArray &links, FILE *file, int count);
errorCode LinksAllocate(linkArray &links, int size);
void LinksFree(linkArray &links);

#endif