#include "Iterator.hpp"
#include "SetExceptions.hpp"
#include <time.h>

template<class Type>
Type* Iterator<Type>::getPtr() const
{
    std::shared_ptr<Type> associatePtr = ptr.lock();
    return associatePtr.get() + index;
}

template<class Type>
Iterator<Type>::Iterator(const Set<Type>& set)
{
    index = 0;
    size = set.size;
    ptr = set.elements;
}

template<class Type>
Iterator<Type>::Iterator(const Iterator<Type>& iter)
{
    index = iter.index;
    size = iter.size;
    ptr = iter.ptr;
}

template<class Type>
Type& Iterator<Type>::operator*()
{
    check(__LINE__);
    if (!this)
    {
        throw SetOutOfRange(__LINE__);
    }
    
    return *getPtr();
}

template<class Type>
const Type& Iterator<Type>::operator*() const
{
    check(__LINE__);
    if (!this)
    {
        throw SetOutOfRange(__LINE__);
    }

    return *getPtr();
}

template<class Type>
Type* Iterator<Type>::operator->()
{
    check(__LINE__);
    if (!this)
    {
        throw SetOutOfRange(__LINE__);
    }
    
    return getPtr();
}

template<class Type>
const Type* Iterator<Type>::operator->() const
{
    check(__LINE__);
    if (!this)
    {
        throw SetOutOfRange(__LINE__);
    }

    return getPtr();
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator=(const Iterator<Type>& iter)
{
    check(__LINE__);
    
    index = iter.index;
    size = iter.size;
    ptr = iter.ptr;
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator=(const Iterator<Type>&& iter)
{
    check(__LINE__);
    
    index = iter.index;
    size = iter.size;
    ptr = iter.ptr;
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator+=(int step)
{
    check(__LINE__);
    index += step;
    
    return *this;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator+(int step) const
{
    check(__LINE__);

    Iterator<Type> iter(*this);
    iter += step;
    
    return iter;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator++(int)
{
    check(__LINE__);
    ++(*this);
    
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator++()
{
    check(__LINE__);
    ++index;
    
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator-=(int size)
{
    check(__LINE__);
    index -= size;
    
    return *this;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator-(int size) const
{
    check(__LINE__);
    
    Iterator<Type> iter(*this);
    iter -= size;
    
    return iter;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator--(int)
{
    check(__LINE__);
    --(*this);
    
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator--()
{
    check(__LINE__);
    --index;
    
    return *this;
}

template<class Type>
bool Iterator<Type>::operator<=(const Iterator<Type>& iterator) const
{
    check(__LINE__);
    
    return ptr <= iterator.ptr;
}

template<class Type>
bool Iterator<Type>::operator<(const Iterator<Type>& iterator) const
{
    check(__LINE__);
    
    return ptr < iterator.ptr;
}

template<class Type>
bool Iterator<Type>::operator>=(const Iterator<Type>& iterator) const
{
    check(__LINE__);
    
    return ptr >= iterator.ptr;
}

template<class Type>
bool Iterator<Type>::operator>(const Iterator<Type>& iterator) const
{
    check(__LINE__);
    
    return ptr > iterator.ptr;
}

template<class Type>
bool Iterator<Type>::operator==(const Iterator<Type>& iterator) const
{
    check(__LINE__);
    
    return ptr == iterator.ptr;
}

template<class Type>
bool Iterator<Type>::operator!=(const Iterator<Type>& iterator) const
{
    check(__LINE__);
    
    return ptr != iterator.ptr;
}

template<class Type>
Iterator<Type>::operator bool() const
{
    check(__LINE__);
    
    if (index >= size || index < 0 || (size == 0))
        return false;
    else
        return true;
}

template<class Type>
bool Iterator<Type>::check(int line) const
{
    if (!ptr.expired())
    {
        return true;
    }
    time_t currentTime = time(NULL);
    throw SetBadWeakPtr(line, ctime(&currentTime));
    return false;
}
