#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP

#include <memory>
#include "BaseIterator.hpp"

template<typename Type>
class Set;

template<typename Type>
class ConstIterator : virtual public BaseIterator
{
public:
    ConstIterator(const ConstIterator<Type>& ConstIterator);
    ConstIterator(const Set<Type>& set);

    ~ConstIterator();

    const Type& operator*() const;
    const Type* operator->() const;
    operator bool() const;
    
    ConstIterator<Type>& operator=(const ConstIterator<Type>& constIterator);
    ConstIterator<Type>& operator=(const ConstIterator<Type>&& constIterator);
    
    ConstIterator<Type>& operator+=(int n);
    ConstIterator<Type> operator+(int n) const;
    ConstIterator<Type>& operator++();
    ConstIterator<Type> operator++(int);
    
    ConstIterator<Type>& operator-=(int n);
    ConstIterator<Type> operator-(int n) const;
    ConstIterator<Type>& operator--();
    ConstIterator<Type> operator--(int);
    
    bool operator<=(const ConstIterator<Type>& constIterator) const;
    bool operator<(const ConstIterator<Type>& constIterator) const;
    bool operator>=(const ConstIterator<Type>& constIterator) const;
    bool operator>(const ConstIterator<Type>& constIterator) const;
    bool operator==(const ConstIterator<Type>& constIterator) const;
    bool operator!=(const ConstIterator<Type>& constIterator) const;
    
    bool check(int line) const;

protected:
    Type* getPtr() const;

private:
    std::weak_ptr<Type[]> ptr;
};

#endif