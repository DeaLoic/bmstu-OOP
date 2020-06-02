#include <QObject>

class Button
{
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
    void SlotButtonPress(int floor);
    void SlotButtonReset(int floor);

private:
    ButtonState state;
    int floor;
}