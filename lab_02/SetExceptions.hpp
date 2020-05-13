#ifndef SET_EXCEPTIONS_H
#define SET_EXCEPTIONS_H

#include <exception>
#include <string>
#include <iostream>

class SetException : public std::exception
{
public:
	virtual const char* what()
	{
		return message.c_str();
	}

	explicit SetException(const std::string& file = "",
		                  const int line = 0,
					      const char* time = "",
					      const std::string& info = "Error!")
	{
		message = "\nException in:\nFile: " + file + "\nLine: " +
        std::to_string(line) + "\nAt time: " + time + "\nException: " + info;
	}

protected:
	std::string message;
};

class SetBadAlloc : virtual public SetException
{
public:
	explicit SetBadAlloc( const int size = 0,
	                      const std::string& file = "",
		                  const int line = 0,
					      const char* time = "",
					      const std::string& info = "Allocation memory error!")
		: SetException(file, line, time, info + std::to_string(size) + "\n") {}
};

class SetBadWeakPtr : virtual public SetException
{
public:
	explicit SetBadWeakPtr(const std::string& file = "",
		                   const int line = 0,
					       const char* time = "",
					       const std::string& info = "Bad weak pointer!\n")
		: SetException(file, line, time, info) {}
};

class SetOutOfRange : virtual public SetException
{
public:
    int index;
	explicit SetOutOfRange(const std::string& file = "",
	                       const int index = 0,
		                   const int line = 0,
					       const char* time = "",
					       const std::string& info = "Out of range! Index: ")
		: SetException(file, line, time, info + std::to_string(index) + "\n") {}
};



#endif // SET_EXCEPTIONS_H