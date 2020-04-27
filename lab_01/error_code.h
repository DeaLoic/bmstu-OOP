#ifndef ERROR_CODE_H
#define ERROR_CODE_H

typedef enum errorCode
{
    SUCCES,
    FILE_ERROR = -10,
    INPUT_ERROR,
    MEMORY_ERROR,
    INVALID_ARGUMENT,
    PARSE_ERROR,
    BAD_ERROR,
} errorCode;

char *GetErrorString(errorCode error);

#endif
