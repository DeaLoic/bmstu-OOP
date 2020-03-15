#ifndef ERROR_CODE_H
#define ERROR_CODE_H

typedef enum errorCode
{
    SUCCES,
    FILE_OPEN = -10,
    MEMORY_ERROR,
    INVALID_ARGUMENT,
    PARSE_ERROR,
    BAD_ERROR,
} errorCode;

#endif
