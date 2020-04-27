#include "load.h"

void FormLoadInfo(loadInfo &load, char *filename)
{
    load.filename = filename;
}

errorCode ReadCount(int &count, FILE *file)
{
    errorCode error = SUCCES;
    if (!file)
    {
        error = FILE_ERROR;
    }
    else
    {
        if (fscanf(file, "%d", &count) != 1)
        {
            error = PARSE_ERROR;
        }
        else if (count <= 0)
        {
            error = INPUT_ERROR;
        }
    }

    return error;
}

errorCode LoadPoints(pointArray &points, FILE *file)
{
    errorCode error = SUCCES;
    if (!file)
    {
        error = FILE_ERROR;
    }
    else
    {
        int count;
        error = ReadCount(count, file);
        if (error == SUCCES)
        {
            error = ReadPointsByCount(points, file, count);
        }
        if (error != SUCCES)
        {
            PointsFree(points);
        }
    }
    
    return error;
}

errorCode LoadLinks(linkArray &links, FILE *file)
{
    errorCode error = SUCCES;
    if (!file)
    {
        error = FILE_ERROR;
    }
    else
    {
        int count;
        error = ReadCount(count, file);
        if (error == SUCCES)
        {
            error = ReadLinksByCount(links, file, count);
        }
        if (error != SUCCES)
        {
            LinksFree(links);
        }
    }
    
    return error;
}
