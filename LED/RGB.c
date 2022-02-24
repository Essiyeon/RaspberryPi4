//11. RGB LED.c
//RGB LED 모듈에 내장된 LED 3종을 차례대로 ON/OFF

#include <stdio.h>
#include <wiringPi.h>

#define	LED_R   0  // #17
#define	LED_B   2  // #27
#define	LED_G   3  // #22

int main (void)
{
    wiringPiSetup();

    pinMode(LED_R, OUTPUT);
    pinMode(LED_B, OUTPUT);
    pinMode(LED_G, OUTPUT);

    digitalWrite(LED_R, 1);
    digitalWrite(LED_B, 1);
    digitalWrite(LED_G, 1);

    while(1)
    {
        digitalWrite(LED_R, 0); // 0 (LOW) : LED ON
        delay(1000);
        digitalWrite(LED_R, 1);
    
        digitalWrite(LED_B, 0);
        delay(1000);
        digitalWrite(LED_B, 1);

        digitalWrite(LED_G, 0);
        delay(1000);
        digitalWrite(LED_G, 1);
    }

    return 0;
}
