#include "Cabin.hpp"

void Cabin::Cabin()
{
    state = STAND_DOOR_CLOSED;
    QObject::Connect(this, SIGNAL(SignalFloorReached(int)), &doors, SLOT(SlotOpening()));
    QObject::Connect(this, SIGNAL(SignalClosingDoor()), &doors, SLOT(SlotClosing()));
    QObject::Connect(this, SIGNAL(SignalStanding()), this, SLOT(SlotStanding()));
    QObject::Connect(&doors, SIGNAL(SignalDoorIsClosed()), this, SLOT(SlotMoving()));
    QObject::Connect(&movingTimer, SIGNAL(timeout()), this, SLOT(SlotMoving()));
}

void Cabin::SlotNextFloor(int floor)
{
    state = GOT_TARGET;
    targetFloor = floor;
    if (currentFloor == floor)
    {
        emit SignalStanding();
    }
    else
    {
        emit SignalClosingDoor();
    }    
}

void Cabin::SlotMoving()
{
    if (state == MOVING || state == GOT_TARGET)
    {
        state = MOVING;
        if (targetFloor == currentFloor)
        {
            emit SignalStanding();
        }
        else
        {
            emit SignalFloorPassed(currentFloor);
            FloorStep(targetFloor);
        }
    }
}

void Cabin::SlotStanding()
{
    state = STAND;
    emit SignalFloorReached(currentFloor);
}

void Cabin::FloorStep(int floor)
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

    movingTimer.start(CABIN_MOVING_TIME);
}