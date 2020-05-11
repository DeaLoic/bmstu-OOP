#include "Iterator.hpp"

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
    check();
    
    return *getPtr();
}

template<class Type>
const Type& Iterator<Type>::operator*() const
{
    check();
    
    return *getPtr();
}

template<class Type>
Type* Iterator<Type>::operator->()
{
    check();
    
    return getPtr();
}

template<class Type>
const Type* Iterator<Type>::operator->() const
{
    check();
    
    return getPtr();
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator=(const Iterator<Type>& iter)
{
    check();
    
    index = iter.index;
    size = iter.size;
    ptr = iter.ptr;
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator=(const Iterator<Type>&& iter)
{
    check();
    
    index = iter.index;
    size = iter.size;
    ptr = iter.ptr;
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator+=(int step)
{
    check();
    ptr += step;
    
    return *this;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator+(int step) const
{
    check();

    Iterator<Type> iter(*this);
    iter += step;
    
    return iter;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator++(int)
{
    check();
    ++(*this);
    
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator++()
{
    check();
    ++index;
    
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator-=(int size)
{
    check();
    index -= size;
    
    return *this;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator-(int size) const
{
    check();
    
    Iterator<Type> iter(*this);
    iter -= size;
    
    return iter;
}

template<class Type>
Iterator<Type> Iterator<Type>::operator--(int)
{
    check();
    --(*this);
    
    return *this;
}

template<class Type>
Iterator<Type>& Iterator<Type>::operator--()
{
    check();
    --index;
    
    return *this;
}

template<class Type>
bool Iterator<Type>::operator<=(const Iterator<Type>& iterator) const
{
    check();
    
    return ptr <= iterator.ptr;
}

template<class Type>
bool Iterator<Type>::operator<(const Iterator<Type>& iterator) const
{
    check();
    
    return ptr < iterator.ptr;
}

template<class Type>
bool Iterator<Type>::operator>=(const Iterator<Type>& iterator) const
{
    check();
    
    return ptr >= iterator.ptr;
}

template<class Type>
bool Iterator<Type>::operator>(const Iterator<Type>& iterator) const
{
    check();
    
    return ptr > iterator.ptr;
}

template<class Type>
bool Iterator<Type>::operator==(const Iterator<Type>& iterator) const
{
    check();
    
    return ptr == iterator.ptr;
}

template<class Type>
bool Iterator<Type>::operator!=(const Iterator<Type>& iterator) const
{
    check();
    
    return ptr != iterator.ptr;
}

template<class Type>
Iterator<Type>::operator bool() const
{
    check();
    
    if (index >= size || index < 0 || (size == 0))
        return false;
    else
        return true;
}

template<class Type>
bool Iterator<Type>::check() const
{
    if (!ptr.expired())
        return true;
    return false;
}
