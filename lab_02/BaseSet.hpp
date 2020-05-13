#ifndef __BASE_SET__
#define __BASE_SET__

class BaseSet
{
public:
    BaseSet();
    BaseSet(const BaseSet & set);

    virtual ~BaseSet() = 0;

    int GetSize();
    bool IsEmpty();
protected:
    int allocateSize = 0;
    int size = 0;
};

#endif // __BASE_SET__