#ifndef CABIN_HPP
#define CABIN_HPP

#include <QObject>
#include <QTimer>
#include "Doors.hpp"

class Cabin : public QObject
{
    Q_OBJECT
    enum CabinState
    {
        STAND,
        GOT_TARGET,
        MOVING
    };

public:
    Cabin();

public signals:
    void SignalFloorPassed(int floor);
    void SignalFloorReached(int floor);
    void SignalStanding();
    void SignalClosingDoor();

public slots:
    void SlotNextFloor(int floor);
    void SlotMoving();
    void SlotStanding();

private:
    void FloorStep(int floor);

    int currentFloor;
    int targetFloor;
    Doors doors;
    CabinState state;

    QTimer movingTimer;
};

#endif