// 07. Switch input
//��Ʈ ����ġ�� ƿƮ(��) ����ġ�� �Է��� �޾� LED�� ON/OFF

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

    // LED �� ��� ����
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);

    // ��Ʈ, ƿƮ ����ġ �Է� ����
    pinMode(TACTSW, INPUT);
    pinMode(TILTSW, INPUT);
    while(1)
    {   
        // ����ġ ��(����) �޾ƿ���
        tactsw = digitalRead(TACTSW);
        tiltsw = digitalRead(TILTSW);
        // ����ġ �Է� ���� ���� �� LED ����
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