#include "Elevator.hpp"

Elevator::Elevator(int floors)
{
    controller = new Controller(floors);
    cabin = new Cabin();

    QObject::connect(&controller, SIGNAL(SignalNextFloor(int)), &cabin, SLOT(SlotNextFloor(int)));
    QObject::connect(&cabin, SIGNAL(SignalFloorPassed(int)), &controller, SLOT(SlotFloorPassed(int)));
    QObject::connect(&cabin, SIGNAL(SignalFloorReached(int)), &controller, SLOT(SlotFloorPassed(int)));
}

Elevator::~Elevator()
{
    delete cabin;
    delete controller;
}