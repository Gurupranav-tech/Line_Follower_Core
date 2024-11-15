#pragma once
#include <Arduino.h>

struct Data
{
    char d1, d2;
};

class SensorDriver
{
private:
    char i1, i2;

public:
    SensorDriver(char i1, char i2)
        : i1(i1), i2(i2) {}

    void init() const
    {
        pinMode(i1, INPUT);
        pinMode(i2, INPUT);
    }

    Data read() const
    {
        char d1 = digitalRead(i1);
        char d2 = digitalRead(i2);

        return Data{d1, d2};
    }
};