/* 20. Joystick.c
* 
* ���̽�ƽ ����� �Ƴ��α� ������ ���� PCF8591 ADC ����� �̿��Ͽ� ��������̷� �޾� �ݴϴ�.
*
* �ʿ� ����
* ���̽�ƽ ���, PCF8591 ���
* 
* > PCF8591 ��� (0,1 ä���� ����ϱ� ���� ���۸� ������ �־�� �մϴ�.)
* ����� ������ ���� 3.3V, GND ����, SDA, SCL ���� ����������� ������ SDA(#2), SCL(#3) �� �����մϴ�.
* 
* > ���̽�ƽ
* +, - ���� ���� 3.3V, GND�� ������ �ݴϴ�.
* X : PCF8591����� AIN0 (ADC IN ch0)
* Y : PCF8591����� AIN1 (ADC IN ch1)
* B :  Wpi : 7 | BCM : #4   (���̽�ƽ)
* 
* �� Wpi��ȣ�� wiringPi ���̺귯���� ����ϴ� �� ��ȣ�̸�, BCM ��ȣ�� GPIO Cobbler Plus V2 ���忡 �����ִ� ��ȣ�Դϴ�.
* �� female to female ���̺��� ��ǰ ������ ���Ե��� �����Ƿ� �극�庸�带 �����Ͽ� �� ���带 �����ϰų�, PCF8591��⿡ ���ԵǾ��ִ� F/F ���̺��� ����մϴ�.
*/

#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>

#define Q2W_ABASE       120
#define	BUTTON          7     // #4
#define ADC_CH_0        0
#define ADC_CH_1        1

int main (void)
{
    int adcCh0 = 0, adcCh1 = 0, button = 0;

    wiringPiSetup();

    pcf8591Setup(Q2W_ABASE, 0x48);

    pinMode(BUTTON, INPUT);

    while(1)
    {
        adcCh0 = analogRead(Q2W_ABASE + ADC_CH_0);  // ADC 0�� ä�� �б�
        adcCh1 = analogRead(Q2W_ABASE + ADC_CH_1);  // ADC 1�� ä�� �б�
        button = digitalRead(BUTTON);               // ������ �� �б�

        // �Է� �� ȭ�鿡 ���
        printf("> JOY X : %d | Y : %d | BTN : %d \n", adcCh0, adcCh1, button);
        delay (100);
    }

    return 0;
}
