// 21. HC-SR04.c
//ultrasonic sensor(초음파 거리측정)의 예제로 초음파 센서와 물체의 거리를 터미널 창으로 실시간 출력해 줍니다.

#include <stdio.h>
#include <wiringPi.h>
#include <unistd.h>

#define TRIG 4  // Trig 핀 wiringPi 번호 정의
#define ECHO 5  // ECHO 핀 wiringPi 번호 정의

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

        digitalWrite(TRIG,HIGH);                  // 10us 초음파 방사
        usleep(10);
        digitalWrite(TRIG,LOW);

        while(digitalRead(ECHO) == LOW){          // 초음파 송신 시간
            startTime = micros();
        }

        while(digitalRead(ECHO) == HIGH){         // 초음파 수신 시간
            travelTime = micros() - startTime;      // 초음파 총 이동 시간 계산 
        }

        int distance = travelTime / 58;           // 초음파 속도 340m/s = 0.034cm/us, 1cm당 지연시간 약 29.41us * 2(왕복) = 58 
        printf("Distance: %dcm\r\n", distance);

        delay(100);
    }
}