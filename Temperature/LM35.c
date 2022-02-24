/* 13.LM35
* LM35 �µ� ������ �Ƴ��α� ��� ��ȣ�� �޾� �µ��� ����Ͽ� ����� �ݴϴ�.
* �� �� ������ PCF8591 ���� ��� �� ���� ��Ȯ�ϰ� ������ �ʽ��ϴ�.
* LM35�� 4V �̻���(4~20V)������ ���� �� 1'C �� 10mV�� ������ ����ϴ� �����Դϴ� (1~150'C / 10~1500mV) 
* ��, PCF8591 Ĩ/����� 8bit(256) ADC�� ���е��� ���� 3.3V ���� �� �ּ� ���� ���� ������ 12.9mV�� �˴ϴ�. 
* ����, 500mV ������ ���� ���п��� ũ�Դ� 100mV ���� ������ �߻��ϴ� ���� ���� �־� ���(25'C / 250mV) ��� ������ ��Ȯ�ϰ� ������ �ʽ��ϴ�.
* ������ ������ ADC���尡 �ִ� ��찡 �ƴ϶�� �뷫���� �µ� ��ȭ�� ���� Ȯ�ο����θ� ����Ͻô� ���� ����帳�ϴ�.
*/

#include <wiringPi.h>
#include <pcf8591.h>    // Need i2C Enable
#include <stdio.h>
#define Q2W_ABASE   120
#define ADC_CH        0

int main(void)
{
    float value, dat, temp;
    wiringPiSetup();
    pcf8591Setup(Q2W_ABASE, 0x48);


    while(1)
    {
        value = analogRead(Q2W_ABASE + ADC_CH);
        /*
        *  ADC data :
        *  19.61 : ADC 8bit(256 / 0~5V)
        *  12.94 : ADC 8bit(256 / 0~3.3V)
        */
        dat = (value * 19.53);
        temp = dat / 10; 
        printf("dat : %f mV | temp : %4.2f 'C \n", dat, temp);
        delay(1000);
    }

    return 0;
}
