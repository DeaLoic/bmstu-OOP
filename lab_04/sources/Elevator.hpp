#include "Controller.hpp"
#include "Cabin.hpp"

class Elevator
{
public:
    Elevator(int floursCount);
    ~Elevator();
private:
    Controller controller;
    Cabin cabin;
};