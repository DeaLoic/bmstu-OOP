#include "BaseSet.hpp"

BaseSet::BaseSet()
{
    this->size = 0;
}

BaseSet::BaseSet(const BaseSet & set)
{
    this->size = set.size;
}
    
BaseSet::~BaseSet()
{
    this->size = 0;
}

int BaseSet::GetSize()
{
    return this->size;
}

bool BaseSet::IsEmpty()
{
    return size == 0;
}