//03. Flow_LED.c
//6개의 LED를 차례대로 ON/OFF

#include <wiringPi.h>

int main(void)
{
    wiringPiSetup();
    pinMode(15, OUTPUT);   // Wpi : 15 | BCM : #14
    pinMode(16, OUTPUT);   // Wpi : 16 | BCM : #15
    pinMode(1, OUTPUT);    // Wpi : 1 | BCM : #18
    pinMode(4, OUTPUT);    // Wpi : 4 | BCM : #23
    pinMode(5, OUTPUT);    // Wpi : 5 | BCM : #24
    pinMode(6, OUTPUT);    // Wpi : 6 | BCM : #25

    while (1)   // LED 6ea 차례대로 ON/OFF - 반복
    {
        digitalWrite(15, HIGH);
        delay(500);
        digitalWrite(16, HIGH);
        delay(500);
        digitalWrite(1, HIGH);
        delay(500);
        digitalWrite(4, HIGH);
        delay(500);
        digitalWrite(5, HIGH);
        delay(500);
        digitalWrite(6, HIGH);
        delay(500);
        digitalWrite(6, LOW);
        delay(500);
        digitalWrite(5, LOW);
        delay(500);
        digitalWrite(4, LOW);
        delay(500);
        digitalWrite(1, LOW);
        delay(500);
        digitalWrite(16, LOW);
        delay(500);
        digitalWrite(15, LOW);
        delay(500);
    }
    return 0;
}
