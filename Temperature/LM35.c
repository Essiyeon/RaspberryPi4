/* 13.LM35
* LM35 온도 센서의 아날로그 출력 신호를 받아 온도로 계산하여 출력해 줍니다.
* ※ 본 예제는 PCF8591 보드 사용 시 값이 정확하게 나오지 않습니다.
* LM35는 4V 이상의(4~20V)전압을 공급 시 1'C 당 10mV의 전압을 출력하는 소자입니다 (1~150'C / 10~1500mV) 
* 단, PCF8591 칩/모듈이 8bit(256) ADC로 정밀도가 낮아 3.3V 연결 시 최소 전압 측정 범위가 12.9mV가 됩니다. 
* 또한, 500mV 이하의 낮은 전압에서 크게는 100mV 까지 오차가 발생하는 현상 등이 있어 상온(25'C / 250mV) 출력 전압이 정확하게 읽히지 않습니다.
* 별도의 고정밀 ADC보드가 있는 경우가 아니라면 대략적인 온도 변화의 유무 확인용으로만 사용하시는 것을 권장드립니다.
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
