#include "Set.hpp"
#include "Iterator.hpp"
#include <initializer_list>

template <typename T>
Set<T>::Set()
{
    size = 0;
    AllocNewArray(size);
}

template <typename T>
Set<T>::Set(const Set<T>& set)
{
    size = set.size;
    AllocNewArray(size)
    Iterator<T> iterator = new Iterator<T>(set);
    for (int i = 0; i <= size; i++)
    {
        this->Add(iterator);
        iterator++;
    }
}

template <typename T>
Set<T>::Set(Set<T>&& set)
{
    size = set.size;
    elements = set.elements;
    set.elements = nullptr;
}

template <typename T>
Set<T>::Set(std::initializer_list<T> arguments)
{
    if (arguments.size() == 0)
    {
        Set();
    }
    
    int size = int(args.size());
    AllocNewArray(size);
    
    for (T element : arguments)
    {
        this->Add(element);
    }
}

template <typename T>
Set<T>::~Set()
{
    delete this->elements;
}

template <typename T>
bool Set<T>::IsContain(const T element) const
{
    bool isContain = false;
    for (T curElement : *this)
    {
        if (curElement == element)
        {
            isContain = true;
            break;
        }
    }

    return isContain;
}

template <typename T>
bool Set<T>::Add(T element)
{
    bool isAdded = false;
    if (!this->IsContain(element))
    {
        // Error catch
        realloc(elements, (size + 1) * sizeof(T));
        elements[size] = element;
        size++;
        isAdded = true;
    }

    return isAdded;
}

/*
template <typename T>
Set<T>::AddRange(std::initializer_list<T> elements);

template <typename T>
Set<T>::AddRange(... T elements);
*/

template <typename T>
bool Set<T>::Remove(T element)
{
    bool isRemoved = false;
    return isRemoved;
}

template <typename T>
Set<T>::Union(const Set<T>& set) const
{
    Set<T> result = new Set(*this);

    Iterator<T> iterator = new Iterator<T>(set);
    for (; iterator; iterator++)
    {
        result.Add(*iterator);
    }

    return result;
}

template <typename T>
Set<T>::Intersection(const Set<T>& set)
{
    Set<T> result = new Set();

    Iterator<T> iterator = new Iterator<T>(set);
    for (; iterator; iterator++)
    {
        if (this->IsContains(*iterator))
        {
            result.Add(*iterator);
        }
    }

    return result;
}

template <typename T>
Set<T>::Difference(const Set<T>& set)
{
    Set<T> result = new Set();

    Iterator<T> iterator = new Iterator<T>(*this);
    for (; iterator; iterator++)
    {
        if (!set.IsContains(*iterator))
        {
            result.Add(*iterator);
        }
    }

    return result;
}

template <typename T>
Set<T>::SymetricDifference(const Set<T>& set)
{
    Set<T> result = new Set();

    Iterator<T> iterator = new Iterator<T>(set);
    for (; iterator; iterator++)
    {
        if (!this->IsContains(*iterator))
        {
            result.Add(*iterator);
        }
    }

    Iterator<T> thisIterator = new Iterator<T>(*this);
    for (; thisIterator; thisIterator++)
    {
        if (!set.IsContains(*thisIterator))
        {
            result.Add(*thisIterator);
        }
    }

    return result;
}

template <typename T>
bool Set<T>::IsSubset(const Set<T>& set) const
{
    bool IsSubset = true;

    Iterator<T> iterator = new Iterator<T>(set);
    for (; iterator && IsSubset; iterator++)
    {
        if (this->IsContains(*iterator))
        {
            IsSubset = false;
        }
    }

    return result;
}

template <typename T>
bool Set<T>::IsEqual(const Set<T>& set) const;
{
    return this->GetSize() == set.GetSize() && this->IsSubset(set);
}

template <typename T>
bool Set<T>::Clear()
{
    delete elements;
    size = 0;
}

template <typename T>
bool Set<T>::operator ==(const Set<T>& right) const
{
    return this->IsEqual(right);
}

template <typename T>
bool Set<T>::operator !=(const Set<T>& right) const
{
    return !this->IsEqual(right);
}

template <typename T>
Set<T>& Set<T>::operator =(const Set<T>& right);

template <typename T>
Set<T>& Set<T>::operator =(std::initializer_list<T> arguments);



template <typename T>
Set<T>& Set<T>::operator +=(const T right);
template <typename T>
Set<T>& Set<T>::operator +=(const Set<T>& right);
template <typename T>
Set<T>& Set<T>::operator +(const Set<T>& left, const T right);
template <typename T>
Set<T>& Set<T>::operator +(const Set<T>& left, const Set<T>& right);

template <typename T>
Set<T>& Set<T>::operator *=(const T right);
template <typename T>
Set<T>& Set<T>::operator *=(const Set<T>& right);
template <typename T>
Set<T>& Set<T>::operator *(const Set<T>& left, const T right);
template <typename T>
Set<T>& Set<T>::operator *(const Set<T>& left, const Set<T>& right);

template <typename T>
Set<T>& Set<T>::operator -=(const T right);
template <typename T>
Set<T>& Set<T>::operator -=(const Set<T>& right);
template <typename T>
Set<T>& Set<T>::operator -(const Set<T>& left, const T right);
template <typename T>
Set<T>& Set<T>::operator -(const Set<T>& left, const Set<T>& right);

template <typename T>
Set<T>& Set<T>::operator /=(const Set<T>& right);
template <typename T>
Set<T>& Set<T>::operator /(const Set<T>& left, const Set<T>& right);