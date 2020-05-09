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
