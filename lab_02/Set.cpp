#include "Set.hpp"
#include "ConstIterator.hpp"
#include "SetExceptions.hpp"
#include <exception>
#include <initializer_list>
#include <time.h>

using namespace std;
template <typename Type>
void Set<Type>::AllocNewArray(int size)
{
    std::shared_ptr<Type[]> temp;
    try
    {
        std::shared_ptr<Type[]> sp(new Type[size], std::default_delete<Type[]>());
        temp = sp;
    }
    catch (const std::bad_alloc& e)
    {
        time_t currentTime = time(NULL);
        throw SetBadAlloc(size, __FILE__, __LINE__, ctime(&currentTime));
    }

    elements.reset();
    elements = temp;
    allocateSize = size;
}

template <typename Type>
Set<Type>::Set(int allocateSize)
{
    size = 0;
    AllocNewArray(allocateSize);
}

template <typename Type>
Set<Type>::Set(const Set<Type>& set)
{
    size = 0;
    AllocNewArray(set.size);

    for (Type element : set)
    {
        this->Add(element);
    }
}

template <typename Type>
Set<Type>::Set(Set<Type>&& set)
{
    size = set.size;
    elements = set.elements;
    set.elements.reset();
}

template <typename Type>
Set<Type>::Set(std::initializer_list<Type> arguments)
{
    
    int size = int(arguments.size());
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
    ConstIterator<Type> iterator(*this);
    for (; iterator && !isContain; iterator++)
    {
        if (*iterator == element)
        {
            isContain = true;
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
        isAdded = true;
        if (size < allocateSize)
        {
            elements[size++] = element;
        }
        else
        {
            std::shared_ptr<Type[]> temp;
            try
            {
                std::shared_ptr<Type[]> sp(new Type[size + 5], std::default_delete<Type[]>());
                temp = sp;
            }
            catch (const std::bad_alloc&)
            {
                
                time_t currentTime = time(NULL);
                throw SetBadAlloc(size + 5, __FILE__, __LINE__, ctime(&currentTime));
            }

            
            ConstIterator<Type> iterator(*this);
            for (int i = 0; i < size; i++, iterator++)
            {
                temp[i] = *iterator;
            }
            temp[size++] = element;
            allocateSize += 5;
            elements.reset();
            elements = temp;
        }
    }

    return isAdded;
}

template <typename Type>
bool Set<Type>::Remove(Type element)
{
    bool isRemoved = false;
    if (this->IsContain(element))
    {
        size_t index = 0;
        for (int i = this->GetSize() - 1; i >= 0; i--)
        {
            if (elements[i] == element)
            {
                index = i;
            }
        }
        elements[index] = elements[this->GetSize() - 1];
        size--;
        isRemoved = true;
    }
    return isRemoved;
}

template <typename Type>
Set<Type>& Set<Type>::Union(const Set<Type>& set)
{
    for (Type element : set)
    {
        this->Add(element);
    }

    return *this;
}

template <typename Type>
Set<Type>& Set<Type>::Intersection(const Set<Type>& set)
{
    Set<Type> result;

    for (Type element : set)
    {
        if (this->IsContain(element))
        {
            result.Add(element);
        }
    }

    *this = result;
    return *this;
}

template <typename Type>
Set<Type>& Set<Type>::Difference(const Set<Type>& set)
{
    for (Type element : set)
    {
        if (this->IsContain(element))
        {
            this->Remove(element);
        }
    }

    return *this;
}

template <typename Type>
Set<Type>& Set<Type>::SymmetricDifference(const Set<Type>& set)
{
    *this = (*this - set) + (set - *this);
	return *this;
}

template <typename Type>
bool Set<Type>::IsSubset(const Set<Type>& set) const
{
    bool IsSubset = true;

    ConstIterator<Type> iterator(set);
    for (; iterator && IsSubset; iterator++)
    {
        if (!this->IsContain(*iterator))
        {
            IsSubset = false;
        }
    }

    return IsSubset;
}

template <typename Type>
bool Set<Type>::IsEqual(const Set<Type>& set) const
{
    return (size == set.size) && this->IsSubset(set);
}

template <typename Type>
void Set<Type>::Clear()
{
    elements.reset();
    size = 0;
    allocateSize = 0;
    AllocNewArray(1);
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
    ConstIterator<Type> iterator(right);
    for (int i = 0; i < right.size; i++, iterator = iterator + 1)
    {
        this->Add(*iterator);
    }
    
    return *this;
}

template <typename Type>
Set<Type>& Set<Type>::operator =(Set<Type>&& right)
{
    size = right.size;
    elements = right.elements;
    right.elements.reset();

    return *this;
}

template <typename Type>
Set<Type>& Set<Type>::operator =(std::initializer_list<Type> arguments)
{
    this->Clear();

    int size = int(arguments.size());
    AllocNewArray(size);
    
    for (Type element : arguments)
    {
        this->Add(element);
    }
    
    return *this;
}

template <typename Type>
Set<Type>& Set<Type>::operator +=(const Type right)
{
    this->Add(right);

    return *this;
}

template <typename Type>
Set<Type>& Set<Type>::operator +=(const Set<Type>& right)
{
    this->Union(right);

    return *this;
}

template <typename Type>
Set<Type> Set<Type>::operator +(const Type right) const
{
    Set<Type> value(*this);
    value.Add(right);

    return value;
}

template <typename Type>
Set<Type> Set<Type>::operator +(const Set<Type>& right) const
{
    Set<Type> value(*this);
    value.Union(right);

    return value;
}

template <typename Type>
Set<Type>& Set<Type>::operator *=(const Set<Type>& right)
{
    this->Intersection(right);

    return *this;
}

template <typename Type>
Set<Type> Set<Type>::operator *(const Set<Type>& right) const
{
    Set<Type> value(*this);
    value.Intersection(right);
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
Set<Type> Set<Type>::operator -(const Type right) const
{
    Set<Type> value(*this);
    value.Remove(right);
    return value;
}

template <typename Type>
Set<Type> Set<Type>::operator -(const Set<Type>& right) const
{
    Set<Type> value(*this);
    value.Difference(right);
    return value;
}

template <typename Type>
Set<Type>& Set<Type>::operator /=(const Set<Type>& right)
{
    this->SymmetricDifference(right);
    return *this;
}

template <typename Type>
Set<Type> Set<Type>::operator /(const Set<Type>& right) const
{
    Set<Type> value(*this);
    value.SymmetricDifference(right);
    return value;
}

template <typename Type>
ConstIterator<Type> Set<Type>::begin() const
{
    ConstIterator<Type> constIterator(*this);
    return constIterator;
}

template <typename Type>
ConstIterator<Type> Set<Type>::end() const
{
    ConstIterator<Type> constIterator(*this);
    constIterator += this->size;
    return constIterator;
}
