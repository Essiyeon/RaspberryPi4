// 07. Switch input
//텍트 스위치와 틸트(볼) 스위치로 입력을 받아 LED를 ON/OFF

#include <stdio.h>
#include <wiringPi.h>
#define	LED1    4  // #23
#define	LED2    5  // #24
#define	TACTSW  0  // #17
#define	TILTSW  2  // #27
 
int main (void)
{
    int tactsw, tiltsw;
    wiringPiSetup();

    // LED 핀 출력 설정
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);

    // 텍트, 틸트 스위치 입력 설정
    pinMode(TACTSW, INPUT);
    pinMode(TILTSW, INPUT);
    while(1)
    {   
        // 스위치 값(상태) 받아오기
        tactsw = digitalRead(TACTSW);
        tiltsw = digitalRead(TILTSW);
        // 스위치 입력 값에 따라 각 LED 제어
        if(tactsw == 0)
        {
            digitalWrite(LED1, 1);
        }else{
            digitalWrite(LED1, 0);
        }
        if(tiltsw != 0)
        {
            digitalWrite(LED2, 1);
        }else{
            digitalWrite(LED2, 0);
        }
        delay(100);
    }
    return 0;
}