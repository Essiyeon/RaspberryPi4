/* 19. Servo.c
* PWM�� �̿��Ͽ� �������͸� ������ �ݴϴ�.
* �ʿ� ����
* �������� (SG-90)
* ������ : VCC (5V)
* ����   : GND (GND)
* ��Ȳ�� : Signal | Wpi : 7 | BCM : #4 
* �� Wpi��ȣ�� wiringPi ���̺귯���� ����ϴ� �� ��ȣ�̸�, BCM ��ȣ�� GPIO Cobbler Plus V2 ���忡 �����ִ� ��ȣ�Դϴ�.
* �� ���ʹ� ���� �Ҹ� ũ�� ������ ����������� ������ ���� ����ϱ⿡�� �������� �ʽ��ϴ�. (2�� �̻� ���� ���� �� ���� ���� ��� ����)
*  �������Ϳ� ���ϰ� Ŭ���� ���� �Ҹ� ũ�� ������ �ʹ� ū ���ϰ� �ɸ��� �ʵ��� �� �ݴϴ�. 
*/

#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h> 

#define SERVO_PIN   7   // BCM #4

int main(void)
{
    wiringPiSetup();

    softPwmCreate(SERVO_PIN, 0, 200);  // create a period 20 ms

    while(1)
    {   
        /* 180�� ���������� ��� ���� Duty ������ 500us(5)~2400us(24) �Դϴ� */
        /* ���� : https://blog.naver.com/elepartsblog/221061007108 */
        softPwmWrite(SERVO_PIN,15);   // 0 degree
        delay(500);

        softPwmWrite(SERVO_PIN,5);    // -90 degree
        delay(500);

        softPwmWrite(SERVO_PIN,15);   // 0 degree
        delay(500);

        softPwmWrite(SERVO_PIN,24);   // 90 degree
        delay(500);
            
    }   

    return 0;
}
