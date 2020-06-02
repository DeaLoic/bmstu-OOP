#include "Elevator.hpp"

Elevator::Elevator(int floors)
{
    controller = new Controller(floors);
    cabin = new Cabin();
}

Elevator::~Elevator()
{
}