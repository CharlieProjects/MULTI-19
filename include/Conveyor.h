#include<arduino.h>

void conveyor(bool dir, int speed)
{
}

void batteryCheck()
{
}

void breaks()
{
}

void elevation()
{
}

void illumination(byte L1, byte L2, byte S1, byte S2)
{
    digitalWrite(L1, digitalRead(S1));
    digitalWrite(L2, digitalRead(S2));
}
