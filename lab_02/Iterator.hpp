#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <memory>
#include "BaseIterator.hpp"

template<typename Type>
class Set;

template<typename Type>
class Iterator : public std::iterator<std::forward_iterator_tag, Type>
{
public:
    Iterator(const Iterator<Type>& iter);
    Iterator(const Set<Type>& vec);

    Type& operator*();
    const Type& operator*() const;
    Type* operator->();
    const Type* operator->() const;
    operator bool() const;
    
    Iterator<Type>& operator=(const Iterator<Type>& iter);
    Iterator<Type>& operator=(const Iterator<Type>&& iter);
    
    Iterator<Type>& operator+=(int n);
    Iterator<Type> operator+(int n) const;
    Iterator<Type>& operator++();
    Iterator<Type> operator++(int);
    
    Iterator<Type>& operator-=(int n);
    Iterator<Type> operator-(int n) const;
    Iterator<Type>& operator--();
    Iterator<Type> operator--(int);
    
    bool operator<=(const Iterator<Type>& b) const;
    bool operator<(const Iterator<Type>& b) const;
    bool operator>=(const Iterator<Type>& b) const;
    bool operator>(const Iterator<Type>& b) const;
    bool operator==(const Iterator<Type>& b) const;
    bool operator!=(const Iterator<Type>& b) const;
    
    bool check() const;

protected:
    Type* getPtr() const;
    int index = 0;
    int size = 0;

private:
    std::weak_ptr<Type> ptr;
};

#endif