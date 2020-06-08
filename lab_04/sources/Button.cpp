#include "Button.hpp"

Button::Button(int floor)
{
    this->floor = floor;
}

void Button::Press()
{
    if (state == NOT_PRESSED)
    {
        emit SignalButtonPressed(floor);
    }   
}

void Button::Reset()
{
    state = NOT_PRESSED;
}

void Button::SlotButtonReset(int floor)
{
    if (floor == this->floor)
    {
        Reset();
    }
}

void Button::SlotButtonPress(int floor)
{
    if (floor == this->floor)
    {
        Press();
    }
}