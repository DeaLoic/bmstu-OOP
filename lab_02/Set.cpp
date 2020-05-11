#include "Set.hpp"
#include "Iterator.hpp"
#include <initializer_list>

template <typename Type>
Set<Type>::Set()
{
    size = 0;
    AllocNewArray(size);
}

template <typename Type>
Set<Type>::Set(const Set<Type>& set)
{
    size = set.size;
    AllocNewArray(size);
    Iterator<Type> iterator = new Iterator<Type>(set);
    for (int i = 0; i <= size; i++)
    {
        this->Add(iterator);
        iterator++;
    }
}

template <typename Type>
Set<Type>::Set(Set<Type>&& set)
{
    size = set.size;
    elements = set.elements;
    set.elements = nullptr;
}

template <typename Type>
Set<Type>::Set(std::initializer_list<Type> arguments)
{
    if (arguments.size() == 0)
    {
        Set();
    }
    
    int size = int(args.size());
    AllocNewArray(size);
    
    for (Type element : arguments)
    {
        this->Add(element);
    }
}

template <typename Type>
Set<Type>::~Set()
{
    elements.reset();
}

template <typename Type>
bool Set<Type>::IsContain(const Type element) const
{
    bool isContain = false;
    for (Type curElement : *this)
    {
        if (curElement == element)
        {
            isContain = true;
            break;
        }
    }

    return isContain;
}

template <typename Type>
bool Set<Type>::Add(Type element)
{
    bool isAdded = false;
    if (!this->IsContain(element))
    {
        // Error catch
        realloc(elements, (size + 1) * sizeof(Type));
        elements[size] = element;
        size++;
        isAdded = true;
    }

    return isAdded;
}

/*
template <typename Type>
Set<Type>::AddRange(std::initializer_list<Type> elements);

template <typename Type>
Set<Type>::AddRange(... Type elements);
*/

template <typename Type>
bool Set<Type>::Remove(Type element)
{
    bool isRemoved = false;
    return isRemoved;
}

template <typename Type>
Set<Type>& Set<Type>::Union(const Set<Type>& set)
{
    Iterator<Type> iterator = new Iterator<Type>(set);
    for (; iterator; iterator++)
    {
        this.Add(*iterator);
    }

    return *this;
}

template <typename Type>
Set<Type>& Set<Type>::Intersection(const Set<Type>& set)
{
    Set<Type> result = new Set();

    Iterator<Type> iterator = new Iterator<Type>(set);
    for (; iterator; iterator++)
    {
        if (this->IsContains(*iterator))
        {
            result.Add(*iterator);
        }
    }

    *this = result;
    return *this;
}

template <typename Type>
Set<Type>& Set<Type>::Difference(const Set<Type>& set)
{
    Set<Type> result = new Set();

    Iterator<Type> iterator = new Iterator<Type>(*this);
    for (; iterator; iterator++)
    {
        if (!set.IsContains(*iterator))
        {
            result.Add(*iterator);
        }
    }

    *this = result;

    return *this;
}

template <typename Type>
Set<Type>& Set<Type>::SymetricDifference(const Set<Type>& set)
{
    *this = (*this / set) + (set / *this);
	return (*this);
}

template <typename Type>
bool Set<Type>::IsSubset(const Set<Type>& set) const
{
    bool IsSubset = true;

    Iterator<Type> iterator = new Iterator<Type>(set);
    for (; iterator && IsSubset; iterator++)
    {
        if (!this->IsContains(*iterator))
        {
            IsSubset = false;
        }
    }

    return result;
}

template <typename Type>
bool Set<Type>::IsEqual(const Set<Type>& set) const
{
    return this->GetSize() == set.GetSize() && this->IsSubset(set);
}

template <typename Type>
void Set<Type>::Clear()
{
    elements.reset();
    size = 0;
}

template <typename Type>
bool Set<Type>::operator ==(const Set<Type>& right) const
{
    return this->IsEqual(right);
}

template <typename Type>
bool Set<Type>::operator !=(const Set<Type>& right) const
{
    return !this->IsEqual(right);
}

template <typename Type>
Set<Type>& Set<Type>::operator =(const Set<Type>& right)
{
    this->Clear();

    Iterator<Type> iterator(right);
    for (; iterator; iterator++)
    {
        this->Add(*iterator);
    }
    
    return *this;
}

Set<Type>& operator =(Set<Type>&& right)
{
    size = right.size;
    elements = right.elements;
    right.elements = nullptr;
}

template <typename Type>
Set<Type>& Set<Type>::operator +=(const Set<Type>& right)
{
    this->Union(right);

    return *this;
}

template <typename Type>
Set<Type> Set<Type>::operator +(const Set<Type>& left, const Type right)
{
    value = new Set<Type>(left);
    value->Add(right)
    return value;
}

template <typename Type>
Set<Type> Set<Type>::operator +(const Set<Type>& left, const Set<Type>& right)
{
    value = new Set<Type>(left);
    value->Union(right)
    return value;
}

template <typename Type>
Set<Type>& Set<Type>::operator *=(const Set<Type>& right)
{
    this->Intersection(right);

    return *this;
}

template <typename Type>
Set<Type> Set<Type>::operator *(const Set<Type>& left, const Set<Type>& right)
{
    value = new Set<Type>(left);
    value->Intersection(right)
    return value;
}

template <typename Type>
Set<Type>& Set<Type>::operator -=(const Type right)
{
    this->Remove(right);
    return *this;
}

template <typename Type>
Set<Type>& Set<Type>::operator -=(const Set<Type>& right)
{
    this->Difference(right);
    return *this;
}

template <typename Type>
Set<Type> Set<Type>::operator -(const Set<Type>& left, const Type right)
{
    value = new Set<Type>(left);
    value->Remove(right)
    return value;
}

template <typename Type>
Set<Type> Set<Type>::operator -(const Set<Type>& left, const Set<Type>& right)
{
    value = new Set<Type>(left);
    value->Difference(right)
    return value;
}

template <typename Type>
Set<Type>& Set<Type>::operator /=(const Set<Type>& right)
{
    this->SymmetricDifference(right);
    return *this;
}

template <typename Type>
Set<Type> Set<Type>::operator /(const Set<Type>& left, const Set<Type>& right)
{
    value = new Set<Type>(left);
    value->SymmetricDifference(right)
    return value;
}