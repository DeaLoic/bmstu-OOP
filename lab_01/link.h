#ifndef LINK_H
#define LINK_H

#include "error_code.h"
#include "stdio.h"

typedef struct link
{
    int firstPoint;
    int secondPoint;
} link;

void FormLink(link &formingLink, int firstPoint, int secondPoint);
errorCode ReadLink(link &readingLink, FILE *file);

#endif
