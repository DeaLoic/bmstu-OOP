#ifndef SET_HPP
#define SET_HPP

#include <initializer_list>
#include <memory>
#include <iostream>

#include "Iterator.cpp"
#include "BaseSet.hpp"

template <typename Type>
class Set : virtual public BaseSet
{
    friend Iterator<Type>;
public:
    Set();
    Set(const Set<Type>& set);
    Set(Set<Type>&& set);
    explicit Set(std::initializer_list<Type> arguments);

    ~Set();

    bool IsContain(const Type element) const;
    bool Add(Type element);
    bool Remove(Type element);

    Set<Type>& Union(const Set<Type>& set);
    Set<Type>& Intersection(const Set<Type>& set);
    Set<Type>& Difference(const Set<Type>& set);
    Set<Type>& SymmetricDifference(const Set<Type>& set);

    bool IsSubset(const Set<Type>& set) const;
    bool IsEqual(const Set<Type>& set) const;
    void Clear();

    bool operator ==(const Set<Type>& right) const;
    bool operator !=(const Set<Type>& right) const;
    Set<Type>& operator =(const Set<Type>& right);
    Set<Type>& operator =(Set<Type>&& right);   
    Set<Type>& operator =(std::initializer_list<Type> arguments);
    


    Set<Type>& operator +=(const Type right);
    Set<Type>& operator +=(const Set<Type>& right);
    Set<Type> operator +(const Type right) const;
    Set<Type> operator +(const Set<Type>& right) const;


    Set<Type>& operator -=(const Type right);
    Set<Type>& operator -=(const Set<Type>& right);
    Set<Type> operator -(const Type right) const;
    Set<Type> operator -(const Set<Type>& right) const;

    Set<Type>& operator *=(const Set<Type>& right);
    Set<Type> operator *(const Set<Type>& right) const;

    Set<Type>& operator /=(const Set<Type>& right);
    Set<Type> operator /(const Set<Type>& right) const;

protected:
    void AllocNewArray(int size);
private:
    std::shared_ptr<Type> elements;
};

template<typename Type>
std::ostream& operator <<(std::ostream& os, const Set<Type>& set)
{
    Iterator<Type> iterator(set);
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