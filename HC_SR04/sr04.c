// 21. HC-SR04.c
//ultrasonic sensor(������ �Ÿ�����)�� ������ ������ ������ ��ü�� �Ÿ��� �͹̳� â���� �ǽð� ����� �ݴϴ�.

#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

#define TRIG 4  // Trig �� wiringPi ��ȣ ����
#define ECHO 5  // ECHO �� wiringPi ��ȣ ����

int main(void){

    int distance=0;
    int pulse=0;


    if(wiringPiSetup()==-1){
        return 1;
    }
    
    pinMode(TRIG,OUTPUT);
    pinMode(ECHO,INPUT);

    while(1){

        long travelTime=0;
        long startTime=0;

        digitalWrite(TRIG,LOW);
        usleep(2);

        digitalWrite(TRIG,HIGH);                  // 10us ������ ���
        usleep(10);
        digitalWrite(TRIG,LOW);

        while(digitalRead(ECHO) == LOW){          // ������ �۽� �ð�
            startTime = micros();
        }

        while(digitalRead(ECHO) == HIGH){         // ������ ���� �ð�
            travelTime = micros() - startTime;      // ������ �� �̵� �ð� ��� 
        }

        int distance = travelTime / 58;           // ������ �ӵ� 340m/s = 0.034cm/us, 1cm�� �����ð� �� 29.41us * 2(�պ�) = 58 
        printf("Distance: %dcm\r\n", distance);

        delay(100);
    }
}