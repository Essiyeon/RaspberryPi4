//08. pcf8591ADC.c
//PCF8591 8bit ADC/DAC ���� �Ƴ��α� �����͸� �޾� ��������̷� ����
//PCF8591 ���� I2C ����� ���� ��������� �������� I2C�� Enable ��Ŵ

#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>
#define Q2W_ABASE       120 // pin base ����
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
        *  CH0 : ��� ���� CDS(�� ����)
        *  CH1 : ��� ���� ��̽���(�µ� ����)
        *  CH2 : NC / �߰� �������� + LED PWM ����
        *  CH3 : ��� ���� ��������
        */

        for(int i=0; i<4; i++)  // 4�� ä�� �� �Է¹���
        {
            value[i] = analogRead(Q2W_ABASE + i);
        }
        
        pwmWrite (LED, value[2] * 4);
        printf("> CH0 : %d\t| CH1 : %d\t| CH2 : %d\t| CH3 : %d \n",value[0],value[1],value[2],value[3]);
        delay (100);
    }

    return 0;
}
