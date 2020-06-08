#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include <QObject>
#include "Controller.hpp"
#include "Cabin.hpp"

class Elevator : public QObject
{
    Q_OBJECT
public:
    Elevator(int floursCount);
    ~Elevator();
private:
    Controller controller;
    Cabin cabin;
};

#endif