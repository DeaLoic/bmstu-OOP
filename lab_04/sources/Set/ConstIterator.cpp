#include "ConstIterator.hpp"
#include "SetExceptions.hpp"
#include <time.h>

template<class Type>
Type* ConstIterator<Type>::getPtr() const
{
    std::shared_ptr<Type[]> associatePtr = ptr.lock();
    return associatePtr.get() + index;
}

template<class Type>
ConstIterator<Type>::ConstIterator(const Set<Type>& set)
{
    index = 0;
    size = set.size;
    ptr = set.elements;
}

template<class Type>
ConstIterator<Type>::ConstIterator(const ConstIterator<Type>& constIterator)
{
    index = constIterator.index;
    size = constIterator.size;
    ptr = constIterator.ptr;
}

template<class Type>
ConstIterator<Type>::~ConstIterator()
{
    ptr.reset();
}

template<class Type>
const Type& ConstIterator<Type>::operator*() const
{
    check(__LINE__);
    if (!this)
    {
        throw SetOutOfRange(__FILE__, __LINE__);
    }

    return *getPtr();
}

template<class Type>
const Type* ConstIterator<Type>::operator->() const
{
    check(__LINE__);
    if (!this)
    {
        throw SetOutOfRange(__LINE__);
    }

    return getPtr();
}

template<class Type>
ConstIterator<Type>& ConstIterator<Type>::operator=(const ConstIterator<Type>& constIterator)
{
    check(__LINE__);
    
    index = constIterator.index;
    size = constIterator.size;
    ptr = constIterator.ptr;
    return *this;
}

template<class Type>
ConstIterator<Type>& ConstIterator<Type>::operator=(const ConstIterator<Type>&& constIterator)
{
    check(__LINE__);
    
    index = constIterator.index;
    size = constIterator.size;
    ptr = constIterator.ptr;
    return *this;
}

template<class Type>
ConstIterator<Type>& ConstIterator<Type>::operator+=(int step)
{
    check(__LINE__);
    index += step;
    
    return *this;
}

template<class Type>
ConstIterator<Type> ConstIterator<Type>::operator+(int step) const
{
    check(__LINE__);

    ConstIterator<Type> iter(*this);
    iter += step;
    
    return iter;
}

template<class Type>
ConstIterator<Type> ConstIterator<Type>::operator++(int)
{
    check(__LINE__);
    ++(*this);
    
    return *this;
}

template<class Type>
ConstIterator<Type>& ConstIterator<Type>::operator++()
{
    check(__LINE__);
    ++index;
    
    return *this;
}

template<class Type>
ConstIterator<Type>& ConstIterator<Type>::operator-=(int size)
{
    check(__LINE__);
    index -= size;
    
    return *this;
}

template<class Type>
ConstIterator<Type> ConstIterator<Type>::operator-(int size) const
{
    check(__LINE__);
    
    ConstIterator<Type> iterator(*this);
    iterator -= size;
    
    return iterator;
}

template<class Type>
ConstIterator<Type> ConstIterator<Type>::operator--(int)
{
    check(__LINE__);
    --(*this);
    
    return *this;
}

template<class Type>
ConstIterator<Type>& ConstIterator<Type>::operator--()
{
    check(__LINE__);
    --index;
    
    return *this;
}

template<class Type>
bool ConstIterator<Type>::operator<=(const ConstIterator<Type>& constIterator) const
{
    check(__LINE__);
    
    return this->getPtr() <= constIterator.getPtr();
}

template<class Type>
bool ConstIterator<Type>::operator<(const ConstIterator<Type>& constIterator) const
{
    check(__LINE__);
    
    return this->getPtr() < constIterator.getPtr();
}

template<class Type>
bool ConstIterator<Type>::operator>=(const ConstIterator<Type>& constIterator) const
{
    check(__LINE__);
    
    return this->getPtr() >= constIterator.getPtr();
}

template<class Type>
bool ConstIterator<Type>::operator>(const ConstIterator<Type>& constIterator) const
{
    check(__LINE__);
    
    return this->getPtr() > constIterator.getPtr();
}

template<class Type>
bool ConstIterator<Type>::operator==(const ConstIterator<Type>& constIterator) const
{
    check(__LINE__);
    
    return this->getPtr() == constIterator.getPtr();
}

template<class Type>
bool ConstIterator<Type>::operator!=(const ConstIterator<Type>& constIterator) const
{
    check(__LINE__);
    
    return this->getPtr() != constIterator.getPtr();
}

template<class Type>
ConstIterator<Type>::operator bool() const
{
    check(__LINE__);
    
    if (index >= size || index < 0 || (size == 0))
        return false;
    else
        return true;
}

template<class Type>
bool ConstIterator<Type>::check(int line) const
{
    if (!ptr.expired())
    {
        return true;
    }
    time_t currentTime = time(NULL);
    throw SetBadWeakPtr(__FILE__, line, ctime(&currentTime));
    return false;
}
