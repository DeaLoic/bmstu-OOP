#include "Controller.hpp"

Controller::Controller(int floors)
{
    for (int i = 0; i < floors; i++)
    {
        buttons.push_back(new Button(i));
        QObject::connect(buttons[i], SIGNAL(SignalButtonPressed(int)), this, SLOT(SlotFloorToVisit(int)));
    }
}

void Controller::SlotFloorPassed(int floor)
{
    this->currentFloor = floor;

}

void Controller::SlotFloorReached(int floor)
{
    if (state == PROCESSING)
    {
        this->currentFloor = floor;
        if (currentDirectionSet.IsContain(floor))
        {
            currentDirectionSet.Remove(floor);
            buttons[floor]->Reset();
        }

        floor = TakeNextFloor();
        if (floor != currentFloor)
        {
            emit SignalNextFloor(floor);
        }
        else
        {
            state = WAITING;
        }
    }
}

void Controller::SlotFloorToVisit(int floor)
{
    state = PROCESSING;
    AddFloorToQueue(floor);
    floor = TakeNextFloor();
    emit SignalNextFloor(floor);
}

int Controller::TakeNextFloor()
{
    int floor = 0;
    if (state == PROCESSING)
    {
        if (direction == UP)
        {
            if (!currentDirectionSet.Min(floor))
            {
                direction = DOWN;
                currentDirectionSet = nextDirectionSet;
                if (!currentDirectionSet.Max(floor))
                {
                    state = WAITING;
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
                    state = WAITING;
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
