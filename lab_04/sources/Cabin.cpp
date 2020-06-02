#include "Cabin.hpp"

void Cabin::Cabin()
{
    state = STAND_DOOR_CLOSED;
    QObject::Connect(this, SIGNAL(SignalOpeningDoor()), &doors, SLOT(SlotOpening()));
    QObject::Connect(this, SIGNAL(SignalClosingDoor()), &doors, SLOT(SlotClosing()));
    QObject::Connect(&doors, SIGNAL(SignalDoorIsClosed()), this, SLOT(SlotDoorClosed()));
    QObject::Connect(&doors, SIGNAL(SignalDoorIsNotClosed()), this, SLOT(SlotDoorNotClosing()));
}
void Cabin::SlotNextFloor(int floor)
{
    if (floor == currentFloor)
    {
        emit SignalOpeningDoor();
    }
    else
    {
        emit SignalClosingDoor();
        MoveToFloor(floor);
    }
}

void Cabin::SlotDoorClosed()
{
    state = STAND_DOOR_CLOSED;
}

void Cabin::SlotDoorNotClosing()
{
    state = STAND_DOOR_NOT_CLOSED;
}

void Cabin::MoveToFloor(int floor)
{
    state = STAND_DOOR_NOT_CLOSED;
}

void MoveToFloor(int floor)
{
    if (floor == currentFloor)
    {
        emit SignalOpeningDoor();
    }
    else
    {
        emit SignalClosingDoor();
        FloorStep(floor);
        MoveToFloor(floor);
    }
}

void FloorStep(int floor)
{
    int step = 0;
    if (floor > currentFloor)
    {
        step = 1;
    }
    else if (floor < currentFloor)
    {
        step = -1;
    }

    currentFloor += step;
}