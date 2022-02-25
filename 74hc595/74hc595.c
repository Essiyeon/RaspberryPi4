// 16. 74hc595
//LED가 순차적으로 점등되며 홀수번째와 짝수번째의 LED가 번갈아 점멸한다.

#include <wiringPi.h>
#include <wiringShift.h>
#define data   4    //#23
#define clock  5    //#24
#define latch  6    //#25

/*   WPI : <wiringShift.h> 라이브러리 shiftOut 함수에 지연 추가   */
void shiftOut1 (uint8_t dPin, uint8_t cPin, uint8_t order, uint8_t val)
{
    int8_t i;

    if (order == MSBFIRST)
    {
        for (i = 7 ; i >= 0 ; --i)
        {
            digitalWrite (dPin, val & (1 << i));
            digitalWrite (cPin, HIGH);
            delayMicroseconds(1);        // 라즈베리파이의 IO 제어가 74HC595 최대 클럭 속도보다 빨라 지연 추가
            digitalWrite (cPin, LOW);
            delayMicroseconds(1);
        }
    }else{
        for (i = 0 ; i < 8 ; ++i)
        {
            digitalWrite (dPin, val & (1 << i));
            digitalWrite (cPin, HIGH);
            delayMicroseconds(1);
            digitalWrite (cPin, LOW);
            delayMicroseconds(1);
        }
    }
}
void updateLEDs(int value)  // LED 제어 함수
{
    digitalWrite(latch,LOW);
    shiftOut1(data,clock,MSBFIRST,value); // LSBFIRST MSBFIRST
    digitalWrite(latch,HIGH);
}

int main()
{
    int i;
    wiringPiSetup();
    pinMode(data,OUTPUT); // 74HC595용 핀 설정
    pinMode(clock,OUTPUT);
    pinMode(latch,OUTPUT);

    while(1)              // 무한반복 - LED 제어
    {
        for (int i = 0; i < 255; i++)
        {
            updateLEDs(i);
            delay(500);
        }
    }
    return 0;
}
