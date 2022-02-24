//09. Light detection.c
//CDS(LDR)의 빛 감지(저항 변화)값을 ADC 모듈(PCF8591)을 통해 받아 부저를 제어해 줍니다.

#include <wiringPi.h>
#include <pcf8591.h>        // Need i2C Enable
#include <stdio.h>
#define	BUZZER       15
#define Q2W_ABASE   120
#define ADC_CH        0

void voice_freq(int del)
{
    digitalWrite(BUZZER,HIGH);
    delay(del);
    digitalWrite(BUZZER,LOW);
    delay(del);
}
int main(void)
{
    int value;
    wiringPiSetup();
    pcf8591Setup(Q2W_ABASE,0x48);
    pinMode(BUZZER,OUTPUT);
    digitalWrite(BUZZER,LOW);
    while(1)
    {
        // 아날로그 값 입력받음
        value = analogRead(Q2W_ABASE + ADC_CH);
        printf("> %d \r\n",value);       // 출력 값 확인용, 밝아질수록 값이 작아짐
        if (value<100)
            voice_freq(value*0.005); //주파수를 조정하여 잘 들리도록 함
    }
    return 0;
}
