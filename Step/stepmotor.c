// 23. Step_Moter.c
//STEP 모터를 ULN2003 IC를 이용해 제어해 줍니다.

/* ※ ULN2003는 달링턴 회로 어레이로 구성된 전류 증폭 기능을 하는 IC입니다. 
*   모터는 매우 많은 전류를 소모하기 때문에 라즈베리파이의 GPIO로는 직접 제어가 불가능하며, 이를 위해 ULN2003과 같은 전류 증폭 회로(IC)/모터 드라이버 등을 사용하여야 합니다.
* ※ 스텝 모터는 내부의 전자석에 차례대로 전원을 넣어주는것을 반복하여 회전하게 됩니다.
*   이 회전은 내부 기어에 의해 매우 작은 각도로 변환되기 때문에 이 반복 과정을 수십~수백회 반복하여야 스텝 모터를 회전시켜 줄 수 있습니다.
*/

#include <stdio.h>
#include <wiringPi.h>

#define PIN_0   7    // #4
#define PIN_1   0    // #17
#define PIN_2   2    // #27
#define PIN_3   3    // #22


int stepMoterWrite(int moveStep)
{
    /* 스텝모터 회전값 - 차례대로(위->아래/ 아래->위) 입력 시 해당 방향으로 회전 */
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

        /* 정회전 */
        for(int loop=0; loop < 535; loop++) // 대략 360' 회전 (1 -> 4 step 535회 반복) 
        {
            for(int i=0; i<8;i++){      // step 1 -> step 4 순서 반복

                stepMoterWrite(i);
                delay(1);
            }
        }

        delay(500);

        /* 역회전 */  
        for(int loop=0; loop < 535; loop++)
        {
            for(int i=7; i>=0;i--){     // step 4 -> step 1 순서 반복

                stepMoterWrite(i);
                delay(1);
            }
        }

        delay(500);

    }

    return 0;
}