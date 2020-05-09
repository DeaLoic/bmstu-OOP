#include "link_array.h"

void SetZeroLinks(linkArray &links)
{
    links.size = 0;
    links.array = nullptr;
}

void ReassignmentLinks(linkArray &destLinks, linkArray &sourceLinks)
{
    destLinks.size = sourceLinks.size;
    destLinks.array = sourceLinks.array;
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
        linkArray tempLinks;
        error = LinksAllocate(tempLinks, count);
        tempLinks.size = count;
        for (int i = 0; i < count && error == SUCCES; i++)
        {
            error = ReadLink(tempLinks.array[i], file);
        }

        if (error != SUCCES)
        {
            LinksFree(tempLinks);
        }
        else
        {
            ReassignmentLinks(links, tempLinks);
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
