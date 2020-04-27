#include "error_code.h"

char *GetErrorString(errorCode error)
{
    char *errorMessage;
    switch (error)
    {
    case FILE_ERROR:
        errorMessage = "Error in file operations";
        break;
    case INPUT_ERROR:
        errorMessage = "Error in input data value";
        break;
    case MEMORY_ERROR:
        errorMessage = "Error in memory allocation";
        break;
    case INVALID_ARGUMENT:
        errorMessage = "Function was called with invalig argument";
        break;
    case PARSE_ERROR:
        errorMessage = "Error in input data format";
        break;
    case BAD_ERROR:
        errorMessage = "Unspecified error";
        break;
    default:
        errorMessage = "Error";
        break;
    }

    return errorMessage;
}
