#include <Arduino.h>
#include <MotorDriver.hpp>
#include <SensorDriver.hpp>

SensorDriver sensorDriver{6, 5};

MotorDriver motor1{12, 11, 10};
MotorDriver motor2{8, 7, 9};

void setup()
{
    motor1.init();
    motor2.init();
    motor1.set_direction(MOTOR_DIRECTION::FORWARD);
    motor2.set_direction(MOTOR_DIRECTION::FORWARD);

    sensorDriver.init();
    Serial.begin(9600);
}

void loop()
{
    auto [d1, d2] = sensorDriver.read();

    if (!d1 && !d2)
    {
        motor1.run(95);
        motor2.run(95);
    }
    else if (!d1 && d2)
    {
        motor2.set_direction(MOTOR_DIRECTION::BACKWARD);
        motor2.run(80);
        motor1.set_direction(MOTOR_DIRECTION::FORWARD);
        motor1.run(80);
    }
    else if (d1 && !d2)
    {
        motor2.set_direction(MOTOR_DIRECTION::FORWARD);
        motor2.run(80);
        motor1.set_direction(MOTOR_DIRECTION::BACKWARD);
        motor1.run(80);
    }
    else
    {
        motor1.set_direction(MOTOR_DIRECTION::FORWARD);
        motor2.set_direction(MOTOR_DIRECTION::FORWARD);
        motor1.run(95);
        motor2.run(95);
    }
    motor1.set_direction(MOTOR_DIRECTION::BACKWARD);
    motor2.set_direction(MOTOR_DIRECTION::BACKWARD);
}