#ifndef SET_EXCEPTIONS_H
#define SET_EXCEPTIONS_H

#include <exception>
#include <string.h>

class SetException : public std::exception
{
public:
	virtual const char* what()
	{
		return message;
	}

	explicit SetException();

	explicit SetException(const char *message)
	{
		int len = strlen(message) + 1;
		this->message = new char[len];
		strcpy(this->message, message);
	}

protected:
	char *message;
};

class SetBadAlloc : public SetException
{
public:
    const long long size = 0;
	explicit SetBadAlloc()
		: SetException("Allocation memory error!\n") {}

	explicit SetBadAlloc(long long size)
		: SetException("Allocation memory error!"), size(size) {}

};

class SetBadWeakPtr : public SetException
{
public:
	explicit SetBadWeakPtr()
		: SetException("Bad weak pointer!\n") {}
};

class SetOutOfRange : public SetException
{
public:
    int index;
	explicit SetOutOfRange()
		: SetException("Out of range!\n") {}

	explicit SetOutOfRange(int index)
		: SetException("Out of range!\n"), index(index){}
};



#endif // SET_EXCEPTIONS_H