// 16. 74hc595
//LED�� ���������� ����Ǹ� Ȧ����°�� ¦����°�� LED�� ������ �����Ѵ�.

#include <wiringPi.h>
#include <wiringShift.h>
#define data   4    //#23
#define clock  5    //#24
#define latch  6    //#25

/*   WPI : <wiringShift.h> ���̺귯�� shiftOut �Լ��� ���� �߰�   */
void shiftOut1 (uint8_t dPin, uint8_t cPin, uint8_t order, uint8_t val)
{
    int8_t i;

    if (order == MSBFIRST)
    {
        for (i = 7 ; i >= 0 ; --i)
        {
            digitalWrite (dPin, val & (1 << i));
            digitalWrite (cPin, HIGH);
            delayMicroseconds(1);        // ����������� IO ��� 74HC595 �ִ� Ŭ�� �ӵ����� ���� ���� �߰�
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
void updateLEDs(int value)  // LED ���� �Լ�
{
    digitalWrite(latch,LOW);
    shiftOut1(data,clock,MSBFIRST,value); // LSBFIRST MSBFIRST
    digitalWrite(latch,HIGH);
}

int main()
{
    int i;
    wiringPiSetup();
    pinMode(data,OUTPUT); // 74HC595�� �� ����
    pinMode(clock,OUTPUT);
    pinMode(latch,OUTPUT);

    while(1)              // ���ѹݺ� - LED ����
    {
        for (int i = 0; i < 255; i++)
        {
            updateLEDs(i);
            delay(500);
        }
    }
    return 0;
}
