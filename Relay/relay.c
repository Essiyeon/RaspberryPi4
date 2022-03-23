// 22. Relay.c
// GPIO ��ȣ�� �����̸� �̿�/�����Ͽ� ������ ������ ����ϴ� ȸ�θ� ������ �ݴϴ�.

/* ������ ����� ����(VCC,GND)/����(DAT)���� �ݴ��� �͹̳��� �մܰ� �и��� ����(����ġ) ȸ���Դϴ�.
* ��� ����(COM)�� (5V or 3.3V) ������ �Է�, ������ �� ����(NO/NC)�� ������ ���¿� ���� COM �ɰ� ����Ǵ� ����ġ ���� �̹Ƿ� �� ���� �ڷ� LED,������ ������ �ֽø� �˴ϴ�.
* > �����̴� ���ڼ��� �̿��� ����ġ�� �����ϴ� ��ǰ���� �Էºο� ����ΰ� �����Ǿ� �ֱ� ������ ������ ����ȸ��(������, �������� ��)�� �����ϴ� ������ �����մϴ�. 
* (��, �������� ���忡 ����)
* �� ������ ����(NO,NC,COM)�� ���Ͽ� : https://blog.naver.com/elepartsblog/221470372661
*/

#include <stdio.h>
#include <wiringPi.h>

#define RELAY    7  // #4


int main(void){

    if(wiringPiSetup()==-1){
        return 1;
    }
    
    // ������ GPIO ����
    pinMode(RELAY,OUTPUT);
    digitalWrite(RELAY,LOW);


    while(1){                   // ���ѹݺ� - ������ On-Off

        digitalWrite(RELAY,HIGH);
        delay(1000);

        digitalWrite(RELAY,LOW);
        delay(1000);

    }
}