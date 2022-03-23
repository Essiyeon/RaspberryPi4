// 23. Step_Moter.c
//STEP ���͸� ULN2003 IC�� �̿��� ������ �ݴϴ�.

/* �� ULN2003�� �޸��� ȸ�� ��̷� ������ ���� ���� ����� �ϴ� IC�Դϴ�. 
*   ���ʹ� �ſ� ���� ������ �Ҹ��ϱ� ������ ����������� GPIO�δ� ���� ��� �Ұ����ϸ�, �̸� ���� ULN2003�� ���� ���� ���� ȸ��(IC)/���� ����̹� ���� ����Ͽ��� �մϴ�.
* �� ���� ���ʹ� ������ ���ڼ��� ���ʴ�� ������ �־��ִ°��� �ݺ��Ͽ� ȸ���ϰ� �˴ϴ�.
*   �� ȸ���� ���� �� ���� �ſ� ���� ������ ��ȯ�Ǳ� ������ �� �ݺ� ������ ����~����ȸ �ݺ��Ͽ��� ���� ���͸� ȸ������ �� �� �ֽ��ϴ�.
*/

#include <stdio.h>
#include <wiringPi.h>

#define PIN_0   7    // #4
#define PIN_1   0    // #17
#define PIN_2   2    // #27
#define PIN_3   3    // #22


int stepMoterWrite(int moveStep)
{
    /* ���ܸ��� ȸ���� - ���ʴ��(��->�Ʒ�/ �Ʒ�->��) �Է� �� �ش� �������� ȸ�� */
    int step[8][4] = {
        {HIGH, LOW, LOW, LOW},  // step   1
        {HIGH,HIGH, LOW, LOW},  // step 1~2
        { LOW,HIGH, LOW, LOW},  // step   2
        { LOW,HIGH,HIGH, LOW},  // step 2~3
        { LOW, LOW,HIGH, LOW},  // step   3
        { LOW, LOW,HIGH,HIGH},  // step 3~4
        { LOW, LOW, LOW,HIGH},  // step   4
        {HIGH, LOW, LOW,HIGH},  // step 4~1
    };

    digitalWrite(PIN_0, step[moveStep][0]);
    digitalWrite(PIN_1, step[moveStep][1]);
    digitalWrite(PIN_2, step[moveStep][2]);
    digitalWrite(PIN_3, step[moveStep][3]);
}


int main(void)
{

    if(wiringPiSetup() == -1){
        return 1;
    }

    pinMode(PIN_0, OUTPUT);
    pinMode(PIN_1, OUTPUT);
    pinMode(PIN_2, OUTPUT);
    pinMode(PIN_3, OUTPUT);


    while(1){

        /* ��ȸ�� */
        for(int loop=0; loop < 535; loop++) // �뷫 360' ȸ�� (1 -> 4 step 535ȸ �ݺ�) 
        {
            for(int i=0; i<8;i++){      // step 1 -> step 4 ���� �ݺ�

                stepMoterWrite(i);
                delay(1);
            }
        }

        delay(500);

        /* ��ȸ�� */  
        for(int loop=0; loop < 535; loop++)
        {
            for(int i=7; i>=0;i--){     // step 4 -> step 1 ���� �ݺ�

                stepMoterWrite(i);
                delay(1);
            }
        }

        delay(500);

    }

    return 0;
}