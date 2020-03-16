#ifndef LINK_ARRAY_H
#define LINK_ARRAY_H

#include "link.h"

typedef struct linkArray
{
    int size;
    link *array;
} linkArray;

void SetZeroLinks(linkArray &links);
void ReassignmentLinks(linkArray &destLinks, linkArray &sourceLinks);
errorCode ReadLinksByCount(linkArray &links, FILE *file, int count);
errorCode LinksAllocate(linkArray &links, int size);
void LinksFree(linkArray &links);

#endif // LINK_ARRAY_H
