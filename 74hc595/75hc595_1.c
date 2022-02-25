// 16. 74hc595_2
//LED를 순차적으로 켜고 끕니다.

#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h> //usleep 사용을 위한 lib

void SIPO(unsigned char byte);
void pulse(int pin);

int SER   = 4;
int RCLK  = 6;
int SRCLK = 5;
unsigned char LED[8]={0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

void init() 
{
    pinMode(SER, OUTPUT);
    pinMode(RCLK, OUTPUT);
    pinMode(SRCLK, OUTPUT);
    digitalWrite(SER, 0);
    digitalWrite(SRCLK, 0);
    digitalWrite(RCLK, 0);
}

void delayMS(int x) 
{
    usleep(x * 1000);
}
int main (void)
{
    if (wiringPiSetup() == -1) {
        printf("Setup wiringPi failed!");
        return 1;
    }
    init();
    int i;
    while(1)
    {  
        for(i = 0; i < 8; i++)
        {
            SIPO(LED[i]);
            pulse(RCLK);
            delayMS(100);
            //printf(" i = %d", i);
        }
        //printf("\n");
        delayMS(500); // 500 ms
        for(i = 7; i >= 0; i--)
        {
            SIPO(LED[i]);
            pulse(RCLK);
            delayMS(100);
            //printf(" i = %d", i);
        }
        delayMS(500); // 500 ms
    }
    usleep(1000);
    digitalWrite(RCLK, 1);
}
void SIPO(unsigned char byte) 
{
    int i;
    for (i=0;i<8;i++) 
    {
        digitalWrite(SER,((byte & (0x80 >> i)) > 0));
        pulse(SRCLK);
    }
}
void pulse(int pin) 
{
    digitalWrite(pin, 1);
    usleep(1);
    digitalWrite(pin, 0);
    usleep(1);
}
