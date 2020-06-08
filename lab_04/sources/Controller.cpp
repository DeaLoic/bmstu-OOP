#include "Controller.hpp"

Controller::Controller(int floors)
{
    for (int i = 0; i < floors; i++)
    {
        buttons.push_back(new Button(i));
        QObject::connect(buttons[i], SIGNAL(SignalButtonPressed(int)), this, SLOT(SlotFloorToVisit(int)));
        QObject::connect(this, SIGNAL(SignalButtonReset(int)), buttons[i], SLOT(ButtonReset(int)));
    }

    QObject::connect(this, SIGNAL(SignalSelfWaiting()), this, SLOT(SlotMakeWaiting()));
}

void Controller::SlotFloorPassed(int floor)
{
    if (state == PROCESSING || (state == WAITING && floor != 0) || state == GOT_TARGET)
    {
        state = PROCESSING;
        this->currentFloor = floor;
        if (targetFloor == floor)
        {
            currentDirectionSet.Remove(floor);
            emit SignalButtonReset(floor);
        }

        targetFloor = TakeNextFloor();
        emit SignalNextFloor(targetFloor);
    }
}

void Controller::SlotFloorToVisit(int floor)
{
    state = GOT_TARGET;
    AddFloorToQueue(floor);
    floor = TakeNextFloor();
    emit SignalNextFloor(floor);
}

void Controller::SlotMakeWaiting(int floor)
{
    state = WAITING;
}

int Controller::TakeNextFloor()
{
    int floor = 0;
    if (state == PROCESSING || state == GOT_TARGET)
    {
        if (direction == UP)
        {
            if (!currentDirectionSet.Min(floor))
            {
                direction = DOWN;
                currentDirectionSet = nextDirectionSet;
                if (!currentDirectionSet.Max(floor))
                {
                    emit SignalSelfWaiting();
                }
            }
        }
        else
        {
            if (!currentDirectionSet.Max(floor))
            {
                direction = UP;
                currentDirectionSet = nextDirectionSet;
                if (!currentDirectionSet.Min(floor))
                {
                    emit SignalSelfWaiting();
                }
            }
        }
    }

    return floor;
}

void Controller::AddFloorToQueue(int floor)
{
    if (state = WAITING)
    {
        state = PROCESSING;
        if (currentFloor >= floor)
        {
            direction = UP;
            currentDirectionSet.Add(floor);
        }
        else
        {
            direction = DOWN;
            currentDirectionSet.Add(floor);
        }
    }
    else
    {
        if (currentFloor > floor)
        {
            if (direction == UP)
            {
                currentDirectionSet.Add(floor);
            }
            else
            {
                nextDirectionSet.Add(floor);
            }
            
        }
        else if (currentFloor < floor)
        {
            if (direction == DOWN)
            {
                currentDirectionSet.Add(floor);
            }
            else
            {
                nextDirectionSet.Add(floor);
            }
        }
        else
        {
            currentDirectionSet.Add(floor);
        }
    }
}

Controller::~Controller()
{
    for(int i = 0; i < floorCount; i++)
    {
        delete buttons[i];
    }
}
