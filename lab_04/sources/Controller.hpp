#include "QObject"
#include "Button.hpp"
#include "Set/Set.hpp"
#include <vector>

class Controller
{
    enum Direction
    {
        UP,
        DOWN
    };

    enum ControllerState
    {
        WAITING,
        PROCESSING
    };

public:
    Controller(int floors);
    ~Controller();

public signals:
    void SignalNextFloor(int floor);

public slots:
    void SlotFloorPassed(int floor);
    void SlotFloorReached(int floor);

private slots:
    void SlotFloorToVisit(int floor);

private:
    void AddFloorToQueue(int floor)
    int TakeNextFloor();

    ControllerState state;
    Direction direction;
    int currentFloor;
    int floorCount;
    Set<int> currentDirectionSet;
    Set<int> nextDirectionSet;
    std::vector<Button> buttons;
};