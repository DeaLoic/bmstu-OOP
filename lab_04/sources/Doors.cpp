#include "Doors.hpp"
#include "Taiming.hpp"

void Doors::Doors()
{
    state = CLOSED;

    QObject::connect(&openingTimer, SIGNAL(timeout()), this, SLOT(SlotSetOpen()));
    QObject::connect(&closingTimer, SIGNAL(timeout()), this, SLOT(SlotSetClose()));
    QObject::connect(&openedTimer, SIGNAL(timeout()), this, SLOT(SlotClosing()));
}

void Doors::SlotOpening()
{
    if (state == CLOSED)
    {
        state = OPENING;
        openingTimer.start(TIME_DOOR_OPENING);
    }
    else if (state == CLOSING)
    {
        state = OPENING;
        int time = closingTimer.remainingTime();
        closingTimer.stop();
        openingTimer.start(TIME_DOOR_OPENING - time);
    }
}

void Doors::SlotClosing()
{
    if (state == OPENED)
    {
        state = CLOSING;
        closingTimer.start(TIME_DOOR_CLOSING);
    }
    else if (state == CLOSED)
    {
        emit SignalDoorIsClosed()
    }
}

void Doors::SlotSetOpen()
{
    if (state == OPENING)
    {
        state = OPENED;
        openedTimer.start(TIME_DOOR_OPENED);
    }
}
void Doors::SlotSetClose()
{
    if (state == CLOSING)
    {
        state = CLOSED;
        emit SignalDoorIsClosed();
    }
    else if (state == CLOSED)
    {
        emit SignalDoorIsClosed();
    }
}