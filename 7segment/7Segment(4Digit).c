//15. 7Segment(4Digit)
//0~1024출력

#include <wiringPi.h>
#include <stdio.h>
#define SEG_A       29
#define SEG_B       27
#define SEG_C       22
#define SEG_D       24
#define SEG_E       25
#define SEG_F       28
#define SEG_G       21
#define SEG_DP      23
#define SEG_Digit1   5
#define SEG_Digit2   4
#define SEG_Digit3   1
#define SEG_Digit4   7

int segmentPinNumber[8] = {// 세그먼트 GPIO 번호
SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G, SEG_DP};
int segmentDigitPinNumber[4] = {
    SEG_Digit1, SEG_Digit2, SEG_Digit3, SEG_Digit4
};
int segmentValue[11][8] = {
    {1,1,1,1,1,1,0,0}, // 0
    {0,1,1,0,0,0,0,0}, // 1
    {1,1,0,1,1,0,1,0}, // 2
    {1,1,1,1,0,0,1,0}, // 3
    {0,1,1,0,0,1,1,0}, // 4
    {1,0,1,1,0,1,1,0}, // 5
    {1,0,1,1,1,1,1,0}, // 6
    {1,1,1,0,0,0,0,0}, // 7
    {1,1,1,1,1,1,1,0}, // 8
    {1,1,1,1,0,1,1,0}, // 9
    {0,0,0,0,0,0,0,1}, // DOT
};

int drawSegment(int number)
{
    for(int i=0;i<8;i++)
    {
digitalWrite(segmentPinNumber[i],segmentValue[number][i]);
    }
    return 0;
}
int draw4DigitSegment(int value)
{
    int D1,D2,D3,D4;
    value = value % 10000;
    D1 = value / 1000;
    D2 = (value / 100) % 10;
    D3 = (value / 10) % 10;
    D4 = value % 10;

    digitalWrite(segmentDigitPinNumber[0],LOW);
    drawSegment(D1);
    delay(2);
    digitalWrite(segmentDigitPinNumber[0],HIGH);

    digitalWrite(segmentDigitPinNumber[1],LOW);
    drawSegment(D2);
    delay(2);
    digitalWrite(segmentDigitPinNumber[1],HIGH);

    digitalWrite(segmentDigitPinNumber[2],LOW);
    drawSegment(D3);
    delay(2);
    digitalWrite(segmentDigitPinNumber[2],HIGH);

    digitalWrite(segmentDigitPinNumber[3],LOW);
    drawSegment(D4);
    delay(2);
    digitalWrite(segmentDigitPinNumber[3],HIGH);

    return 0;
}
int main(void)
{
    int bootMsTime = 0;
    int value = 0;
    wiringPiSetup();

    for(int i=0;i<8;i++)
    {
        pinMode(segmentPinNumber[i],OUTPUT);
    }
    for(int i=0;i<4;i++)
    {
     pinMode(segmentDigitPinNumber[i],OUTPUT);
    }
    bootMsTime = millis();

    while(1)
    {
        value = (millis() - bootMsTime)/10;
draw4DigitSegment(value);
    }
    return 0;
}
