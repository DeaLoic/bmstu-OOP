#ifndef SET_EXCEPTIONS_H
#define SET_EXCEPTIONS_H

#include <exception>
#include <iostream>

class SetException : public std::exception
{
public:
	virtual const char* what()
	{
		return message.c_str();;
	}

	explicit SetException(const int line = 0,
					      const char* time = "",
					      const std::string& info = "Error!")
	{
		message = "\nException in:\nLine: " +
        std::to_string(line) + "\nAt time: " + time + "\nException: " + info;
	}

protected:
	std::string message;
};

class SetBadAlloc : virtual public SetException
{
public:
	explicit SetBadAlloc( const int size = 0,
		                  const int line = 0,
					      const char* time = "",
					      const std::string& info = "Allocation memory error!")
		: SetException(line, time, info + std::to_string(size) + "\n") {}

	const char *what() const noexcept override
    {
        return message.c_str();
    }
};

class SetBadWeakPtr : virtual public SetException
{
public:
	explicit SetBadWeakPtr(const int line = 0,
					       const char* time = "",
					       const std::string& info = "Bad weak pointer!\n")
		: SetException(line, time, info) {}
	
	const char *what() const noexcept override
    {
        return message.c_str();
    }
};

class SetOutOfRange : virtual public SetException
{
public:
    int index;
	explicit SetOutOfRange(const int index = 0,
		                   const int line = 0,
					       const char* time = "",
					       const std::string& info = "Out of range! Index: ")
		: SetException(line, time, info + std::to_string(index) + "\n") {}

	const char *what() const noexcept override
    {
        return message.c_str();
    }
};



#endif // SET_EXCEPTIONS_H