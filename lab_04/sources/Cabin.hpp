#include "Doors.hpp"

class Cabin
{
    enum CabinState
    {
        STAND_DOOR_CLOSED,
        STAND_DOOR_NOT_CLOSED,
        MOVING
    };

public:
    Cabin();

public signals:
    void SignalFloorReached(int floor);
    void SignalFloorPassed(int floor);
    void SignalOpenningDoor();
    void SignalClosingDoor();

public slots:
    void SlotNextFloor(int floor);
    void SlotDoorClosed();
    void SlotDoorNotClosing();

private:
    void MoveToFloor(int floor);
    void FloorStep(int floor);

    int currentFloor;
    Doors doors;
    CabinState state;

    QTimer movingTimer;
}