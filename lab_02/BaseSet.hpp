#ifndef __BASE_SET__
#define __BASE_SET__

class BaseSet
{
public:
    BaseSet();
    BaseSet(const BaseSet & set);

    ~BaseSet();

    int GetSize();
    bool IsEmpty();
protected:
    int size = 0;
};

#endif // __BASE_SET__