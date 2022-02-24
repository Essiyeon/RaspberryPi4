//08. pcf8591ADC.c
//PCF8591 8bit ADC/DAC 모듈로 아날로그 데이터를 받아 라즈베리파이로 전달
//PCF8591 모듈과 I2C 통신을 위해 라즈베리파이 설정에서 I2C를 Enable 시킴

#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>
#define Q2W_ABASE       120 // pin base 설정
#define	LED             1

int main (void)
{
    int value[4] = {0,};
    wiringPiSetup();

    pcf8591Setup(Q2W_ABASE, 0x48);

    pinMode(LED, PWM_OUTPUT);
    pwmWrite(LED, 0);

    while(1)
    {   
        /*
        *  CH0 : 모듈 내장 CDS(빛 감지)
        *  CH1 : 모듈 내장 써미스터(온도 감지)
        *  CH2 : NC / 추가 가변저항 + LED PWM 제어
        *  CH3 : 모듈 내장 가변저항
        */

        for(int i=0; i<4; i++)  // 4개 채널 값 입력받음
        {
            value[i] = analogRead(Q2W_ABASE + i);
        }
        
        pwmWrite (LED, value[2] * 4);
        printf("> CH0 : %d\t| CH1 : %d\t| CH2 : %d\t| CH3 : %d \n",value[0],value[1],value[2],value[3]);
        delay (100);
    }

    return 0;
}
