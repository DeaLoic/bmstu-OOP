#ifndef SET_EXCEPTIONS_H
#define SET_EXCEPTIONS_H

#include <exception>
#include <string>

class SetException : public std::exception
{
public:
	virtual const char* what()
	{
		return message;
	}

	explicit SetException();

	explicit SetException(const char *message)
		: message(message) {}

	explicit SetException(std::string &message)
	{
		this->message = message.c_str();
	}

	explicit SetException(const char *message, const char *additional_message)
		: message(message), additional_message(additional_message) {}

	explicit SetException(std::string &message, std::string &additional_message)
	{
		this->message = message.c_str();
		this->additional_message = additional_message.c_str();
	}

protected:
	const char *message;
	const char *additional_message;
};

class SetMemoryError : public SetException
{
public:
	explicit SetMemoryError()
		: SetException("Allocation memory error!\n") {}

	explicit SetMemoryError(const char *add_message)
		: SetException("Allocation memory error!\n", add_message) {}

};

#endif // SET_EXCEPTIONS_H