class Doors
{
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
    void SignalDoorIsNotClosed();

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

Doors::Doors(/* args */)
{
}

Doors::~Doors()
{
}
