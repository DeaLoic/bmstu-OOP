#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "QObject"
#include "Button.hpp"
#include "Set/Set.hpp"
#include <vector>

class Controller : QObject
{
    Q_OBJECT
    enum Direction
    {
        UP,
        DOWN
    };

    enum ControllerState
    {
        WAITING,
        GOT_TARGET,
        PROCESSING
    };

public:
    Controller(int floors);
    ~Controller();

public signals:
    void SignalNextFloor(int floor);
    void SignalButtonReset(int floor);
    void SignalSelfWaiting();

public slots:
    void SlotFloorPassed(int floor);

private slots:
    void SlotFloorToVisit(int floor);
    void SlotMakeWaiting();

private:
    void AddFloorToQueue(int floor)
    int TakeNextFloor();

    ControllerState state;
    Direction direction;

    int currentFloor;
    int targetFloor;
    int floorCount;
    Set<int> currentDirectionSet;
    Set<int> nextDirectionSet;
    std::vector<Button*> buttons;
};

#endif