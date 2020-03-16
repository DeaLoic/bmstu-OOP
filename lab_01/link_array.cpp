#include "link_array.h"

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
