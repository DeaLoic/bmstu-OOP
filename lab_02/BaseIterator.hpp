#ifndef BASE_ITERATOR_H
#define BASE_ITERATOR_H

class BaseIterator
{
public:
    BaseIterator();
    BaseIterator(const BaseIterator&);
    virtual ~BaseIterator();
    
protected:
    int index = 0;
    int size = 0;
};

#endif /* BASE_ITERATOR_H */