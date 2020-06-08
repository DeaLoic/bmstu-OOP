#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <QObject>

class Button : public QObject
{
    Q_OBJECT
    enum ButtonState
    {
        NOT_PRESSED,
        PRESSED
    };

public:
    Button(int floor);
    void Press();
    void Reset();
    
public signal:
    void SignalButtonPressed(int floor);

public slot:
    void ButtonPress(int floor);
    void ButtonReset(int floor);

private:
    ButtonState state;
    int floor;
};

#endif