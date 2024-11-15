#pragma once
#include <stdint.h>
#include <Arduino.h>

enum class MOTOR_DIRECTION
{
    FORWARD,
    BACKWARD,
};

class MotorDriver
{
private:
    uint8_t DIRN1, DIRN2, SPEED1_PWM;
    MOTOR_DIRECTION direction;

public:
    MotorDriver(uint8_t DIRN1, uint8_t DIRN2, uint8_t SPEED1_PWM)
        : DIRN1(DIRN1), DIRN2(DIRN2), SPEED1_PWM(SPEED1_PWM)
    {
    }

    void init() const
    {
        pinMode(DIRN1, OUTPUT);
        pinMode(DIRN2, OUTPUT);
        pinMode(SPEED1_PWM, OUTPUT);
    }

    void set_direction(MOTOR_DIRECTION direction)
    {

        this->direction = direction;
    }

    void run(uint8_t speed)
    {

        if (direction == MOTOR_DIRECTION::FORWARD)
        {
            digitalWrite(DIRN1, HIGH);
            digitalWrite(DIRN2, LOW);
        }
        else if (direction == MOTOR_DIRECTION::BACKWARD)
        {
            digitalWrite(DIRN1, LOW);
            digitalWrite(DIRN2, HIGH);
        }

        analogWrite(SPEED1_PWM, speed);
    }
};