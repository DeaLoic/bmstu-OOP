#ifndef LINK_H
#define LINK_H

#include "error_code.h"

typedef struct link
{
    int firstPoint;
    int secondPoint;
} link;

typedef struct linkArray
{
    int size;
    link *links;
} linkArray;

void FormLink(link &formingLink, int firstPoint, int secondPoint);
errorCode ReadLink(link &readingLink, FILE *filename);

void SetZeroLinks(linkArray &links);
errorCode ReadLinksByCount(linkArray &links, FILE *file, int count);
errorCode LinksAllocate(linkArray &links, int size);
void LinksFree(linkArray &links);

#endif