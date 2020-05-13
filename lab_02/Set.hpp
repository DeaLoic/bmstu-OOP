#ifndef SET_HPP
#define SET_HPP

#include <initializer_list>
#include <memory>
#include <iostream>

#include "ConstIterator.cpp"
#include "BaseSet.hpp"

template <typename Type>
class Set : virtual public BaseSet
{
    friend ConstIterator<Type>;

public:
    Set(int allocateSize = 1);
    Set(const Set<Type>& set);
    Set(Set<Type>&& set);
    explicit Set(std::initializer_list<Type> arguments);

    ~Set();

    Set<Type>& operator =(const Set<Type>& right);
    Set<Type>& operator =(Set<Type>&& right);   
    Set<Type>& operator =(std::initializer_list<Type> arguments);

    bool IsContain(const Type element) const;
    bool IsSubset(const Set<Type>& set) const;
    void Clear();

    bool IsEqual(const Set<Type>& set) const;
    bool operator ==(const Set<Type>& right) const;
    bool operator !=(const Set<Type>& right) const;

    bool Add(Type element);
    Set<Type>& operator +=(const Type right);
    Set<Type> operator +(const Type right) const;

    bool Remove(Type element);
    Set<Type>& operator -=(const Type right);
    Set<Type> operator -(const Type right) const;

    Set<Type>& Union(const Set<Type>& set);
    Set<Type>& operator +=(const Set<Type>& right);
    Set<Type> operator +(const Set<Type>& right) const;

    Set<Type>& Difference(const Set<Type>& set);
    Set<Type>& operator -=(const Set<Type>& right);
    Set<Type> operator -(const Set<Type>& right) const;

    Set<Type>& Intersection(const Set<Type>& set);
    Set<Type>& operator *=(const Set<Type>& right);
    Set<Type> operator *(const Set<Type>& right) const;

    Set<Type>& SymmetricDifference(const Set<Type>& set);
    Set<Type>& operator /=(const Set<Type>& right);
    Set<Type> operator /(const Set<Type>& right) const;

    ConstIterator<Type> begin() const;
    ConstIterator<Type> end() const;

protected:
    void AllocNewArray(int size);

private:
    std::shared_ptr<Type[]> elements;
};

template<typename Type>
std::ostream& operator <<(std::ostream& os, const Set<Type>& set)
{
    ConstIterator<Type> iterator(set);
    if (iterator)
    {
        os << *iterator;
        iterator++;
    }

    for (; iterator; iterator++)
    {
        os << ' ' << *iterator ;
    }

    return os;
}

#endif