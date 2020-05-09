#include <initializer_list>
#include <memory>

#include "BaseSet.hpp"

template <typename T>
class Set : public BaseSet
{
public:
    Set();
    Set(... T arguments);
    Set(const Set<T>& set);
    Set(Set<T>&& set);
    Set(std::initializer_list<T> arguments);

    ~Set();

    bool IsContain(const T element) const;
    bool Add(T element);
    // AddRange(std::initializer_list<T> elements);
    // AddRange(... T elements);
    bool Remove(T element);
    

    Union(const Set<T>& set) const;
    Intersection(const Set<T>& set) const;
    Difference(const Set<T>& set) const;
    SymetricDifference(const Set<T>& set) const;

    bool IsSubset(const Set<T>& set) const;
    bool IsEqual(const Set<T>& set) const;
    bool Clear();

    bool operator ==(const Set<T>& right) const;
    bool operator !=(const Set<T>& right) const;
    Set<T>& operator =(const Set<T>& right);
    Set<T>& operator =(Set<T>&& right);
    Set<T>& operator =(std::initializer_list<T> arguments);
    


    Set<T>& operator +=(const T right);
    Set<T>& operator +=(const Set<T>& right);
    Set<T>& operator +(const Set<T>& left, const T right);
    Set<T>& operator +(const Set<T>& left, const Set<T>& right);

    Set<T>& operator *=(const T right);
    Set<T>& operator *=(const Set<T>& right);
    Set<T>& operator *(const Set<T>& left, const T right);
    Set<T>& operator *(const Set<T>& left, const Set<T>& right);

    Set<T>& operator -=(const T right);
    Set<T>& operator -=(const Set<T>& right);
    Set<T>& operator -(const Set<T>& left, const T right);
    Set<T>& operator -(const Set<T>& left, const Set<T>& right);

    Set<T>& operator /=(const Set<T>& right);
    Set<T>& operator /(const Set<T>& left, const Set<T>& right);

private:
    std::shared_ptr<T> elements;
};
