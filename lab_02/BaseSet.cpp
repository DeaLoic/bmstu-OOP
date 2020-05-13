#include "BaseSet.hpp"

BaseSet::BaseSet()
{
    this->size = 0;
}

BaseSet::~BaseSet() = default;

int BaseSet::GetSize()
{
    return this->size;
}

bool BaseSet::IsEmpty()
{
    return size == 0;
}