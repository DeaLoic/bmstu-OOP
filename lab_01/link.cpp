#include "link.h"

void FormLink(link &formingLink, int firstPoint, int secondPoint)
{
    formingLink.firstPoint = firstPoint;
    formingLink.secondPoint = secondPoint;
}

errorCode ReadLink(link &readingLink, FILE *file)
{
    errorCode error = SUCCES;
    if (!file)
    {
        error = INVALID_ARGUMENT;
    }
    else
    {
        int firstPoint, secondPoint;
        if (fscanf(file, "%d %d", &firstPoint, &secondPoint) != 2)
        {
            error = PARSE_ERROR;
        }
        else if (firstPoint < 0 && secondPoint < 0)
        {
            error = INPUT_ERROR;
        }
        else
        {
            FormLink(readingLink, firstPoint, secondPoint);
        }
    }

    return error;
}

void SetZeroLinks(linkArray &links)
{
    links.size = 0;
    links.array = nullptr;
}

errorCode ReadLinksByCount(linkArray &links, FILE *file, int count)
{
    errorCode error = SUCCES;
    if (!file || count < 0)
    {
        error = INVALID_ARGUMENT;
    }
    else
    {
        error = LinksAllocate(links, count);
        links.size = count;
        for (int i = 0; i < count && error == SUCCES; i++)
        {
            error = ReadLink(links.array[i], file);
        }

        if (error != SUCCES)
        {
            LinksFree(links);
        }
    }

    return error;
}

errorCode LinksAllocate(linkArray &links, int size)
{
    errorCode error = SUCCES;
    if (size < 0)
    {
        error = INVALID_ARGUMENT;
    }
    else
    {
        links.array = new link [size];
        if (links.array == nullptr && size != 0)
        {
            error = MEMORY_ERROR;
            SetZeroLinks(links);
        }
    }

    return error;
}

void LinksFree(linkArray &links)
{
    delete links.array;
    SetZeroLinks(links);
}
