// 17. 7219matrix.c
/* MAX7219 LED Display Drivers로 LED Matrix 를 제어해 줍니다.
* VCC : 5V | GND : GND
* DIN : Wpi : 12 | BCM : #10
* CS  : Wpi : 10 | BCM : #8
* CLK : Wpi : 14 | BCM : #11
* ※ 예제 실행을 위해서는 라즈베리파이 설정에서 SPI를 Enable 해 주어야 합니다.
*/

#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>

#define Max7219_CLK     14 // #11
#define Max7219_CS      10 // #8
#define Max7219_DIN     12 // #10

#define CHANNEL 0 // SPI_CE0_N 사용(SPI 0번 채널)
#define SPEED 1000000

unsigned char characterData[63][8] = {
{ 0x3E, 0x7F, 0x71, 0x59, 0x4D, 0x7F, 0x3E, 0x00 }, // '0'
    { 0x40, 0x42, 0x7F, 0x7F, 0x40, 0x40, 0x00, 0x00 }, // '1'
    { 0x62, 0x73, 0x59, 0x49, 0x6F, 0x66, 0x00, 0x00 }, // '2'
    { 0x22, 0x63, 0x49, 0x49, 0x7F, 0x36, 0x00, 0x00 }, // '3'
    { 0x18, 0x1C, 0x16, 0x53, 0x7F, 0x7F, 0x50, 0x00 }, // '4'
    { 0x27, 0x67, 0x45, 0x45, 0x7D, 0x39, 0x00, 0x00 }, // '5'
    { 0x3C, 0x7E, 0x4B, 0x49, 0x79, 0x30, 0x00, 0x00 }, // '6'
    { 0x03, 0x03, 0x71, 0x79, 0x0F, 0x07, 0x00, 0x00 }, // '7'
    { 0x36, 0x7F, 0x49, 0x49, 0x7F, 0x36, 0x00, 0x00 }, // '8'
    { 0x06, 0x4F, 0x49, 0x69, 0x3F, 0x1E, 0x00, 0x00 }, // '9'
};

unsigned char initMax7219[5][2] = {
    {0x09, 0x00},       //decoding ：BCD
    {0x0a, 0x03},       //brightness 
    {0x0b, 0x07},       //scanlimit；8 LEDs
    {0x0c, 0x01},       //power-down mode：0，normal mode：1
    {0x0f, 0x00}        //test display：1；EOT，display：0
};

unsigned char adress[8] = {1,2,3,4,5,6,7,8}

void WriteMax7219(unsigned char *data) 
{
    unsigned char buf[2] = {0,};
    for(int i=0;i<8;i++)
    {
        buf[0] = adress[i];
        buf[1] = data[i];
        wiringPiSPIDataRW(CHANNEL, buf, 2);
    }
}
int main(void)
{
    if(wiringPiSetup () == -1)                    // Wpi 사용 설정
        return -1;
    if(wiringPiSPISetup(CHANNEL, SPEED) == -1)    // SPI 설정
        return -1;
    for(int i=0; i<5; i++) // Max7219 초기설정 init
    {
        wiringPiSPIDataRW(CHANNEL, initMax7219[i], 2);
    }
    while(1)
    {
        for(int j=0;j<64;j++)                    
// characterData 문자 한글자씩 출력
        {
            WriteMax7219(characterData[j]);
            delay(500);
        }
    }
    return 0;
}
