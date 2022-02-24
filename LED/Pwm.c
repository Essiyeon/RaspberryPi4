//05. Pwm.c
//PWM 기능을 이용하여 LED 밝기 조절

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (void)
{
    int bright;
    printf ("Raspberry Pi wiringPi PWM test program\n");
    if (wiringPiSetup() == -1) exit(1);
    pinMode (1, PWM_OUTPUT); // LED 핀 PWM 설정

    while (1)  // 무한 반복 - PWM 밝기 제어
    {
        for (bright = 0 ; bright < 1024 ; ++bright)
        {
            pwmWrite(1, bright);
            delay(1);
        }
        for (bright = 1023 ; bright >= 0 ; --bright)
        {
            pwmWrite(1, bright);
            delay(1);
        }
    }
    return 0;
}