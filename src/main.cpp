#include <Arduino.h>

#define MOTOR1 12
#define MOTOR2 11
#define SPEED 10

void setup()
{
    Serial.begin(9600);
    pinMode(MOTOR1, OUTPUT);
    pinMode(MOTOR2, OUTPUT);
    pinMode(SPEED, OUTPUT);
}

void loop()
{
    static int num = 10;
    if (Serial.available())
    {
        num = Serial.read();
        Serial.println(num);
    }

    digitalWrite(MOTOR1, LOW);
    digitalWrite(MOTOR2, HIGH);
    analogWrite(SPEED, num);
    delay(1000);
}
