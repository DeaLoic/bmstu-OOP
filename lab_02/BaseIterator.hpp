#ifndef BASE_ITERATOR_H
#define BASE_ITERATOR_H

class BaseIterator
{
public:
    BaseIterator();
    virtual ~BaseIterator() = 0;

protected:
    int index = 0;
    int size = 0;
};

#endif /* BASE_ITERATOR_H */