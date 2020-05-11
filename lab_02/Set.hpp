#ifndef SET_HPP
#define SET_HPP

#include <initializer_list>
#include <memory>

#include "BaseSet.hpp"

template <typename Type>
class Set : public BaseSet
{
public:
    Set();
    Set(const Set<Type>& set);
    Set(Set<Type>&& set);
    Set(std::initializer_list<Type> arguments);

    ~Set();

    bool IsContain(const Type element) const;
    bool Add(Type element);
    // AddRange(std::initializer_list<Type> elements);
    // AddRange(... Type elements);
    bool Remove(Type element);
    

    Set<Type>& Union(const Set<Type>& set);
    Set<Type>& Intersection(const Set<Type>& set);
    Set<Type>& Difference(const Set<Type>& set);
    Set<Type>& SymetricDifference(const Set<Type>& set);

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

    template<typename T>
    friend Set<Type> operator +(const Set<Type>& left, const Type right);
    template<typename T>
    friend Set<Type> operator +(const Set<Type>& left, const Set<Type>& right);

    Set<Type>& operator *=(const Type right);
    Set<Type>& operator *=(const Set<Type>& right);
    template<typename T>
    friend Set<Type> operator *(const Set<Type>& left, const Type right);
    template<typename T>
    friend Set<Type> operator *(const Set<Type>& left, const Set<Type>& right);

    Set<Type>& operator -=(const Type right);
    Set<Type>& operator -=(const Set<Type>& right);
    template<typename T>
    friend Set<Type> operator -(const Set<Type>& left, const Type right);
    template<typename T>
    friend Set<Type> operator -(const Set<Type>& left, const Set<Type>& right);

    Set<Type>& operator /=(const Set<Type>& right);
    template<typename T>
    friend Set<Type> operator /(const Set<Type>& left, const Set<Type>& right);

private:
    std::shared_ptr<Type> elements;
};

#endif