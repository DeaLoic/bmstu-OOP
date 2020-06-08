#ifndef DOORS_HPP
#define DOORS_HPP

#include <QObject>
#include <QTimer>

class Doors : public QObject
{
    Q_OBJECT
    enum DoorsState
    {
        CLOSED,
        CLOSING,
        OPENED,
        OPENING
    };

public:
    Doors();

public signals:
    void SignalDoorIsClosed();

public slots:
    void SlotOpening();
    void SlotClosing();

private slots:
    void SlotSetOpen();
    void SlotSetClose();

private:
    DoorsState state;

    QTimer openingTimer;
    QTimer closingTimer;
    QTimer openedTimer;
};

#endif