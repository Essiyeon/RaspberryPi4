// 12.DHT11
// �½��� �������� ���ŵ� �����͸� �͹̳� â���� �ݺ��� ����ϴ� ������ �մϴ�.

#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define COUNT_DEBUG 0       
// COUNT �� Ȯ�ο� DEBUG �ɼ�
#define MAX_TIMINGS	85
#define DHT_PIN     29

int data[5] = {0,};

void read_dht_data()
{
    unsigned char laststate = HIGH;
    unsigned char counter   = 0;
    unsigned char get_data  = 0;
    int data_cnt[MAX_TIMINGS] = {0,};
    data[0] = data[1] = data[2] = data[3] = data[4] = 0;
 
    /* DHT Data ���� 18ms ���� LOW�� ������ ������ ������ �۽� ���� ��û */
    pinMode( DHT_PIN, OUTPUT );
    digitalWrite( DHT_PIN, LOW );
    delay(18);
 

   /* DHT Data ���� READ�� ������ ������ ���� �غ� */
    pinMode( DHT_PIN, INPUT );
 
    /* ���� �غ�, ready ��ȣ(0~3) �� DATA ��ȣ(40*2) ����(counter �̿�) ���� */
    for ( int i = 0; i < MAX_TIMINGS; i++ )
    {
        counter = 0;
        while ( digitalRead( DHT_PIN ) == laststate )
        {
            counter++;
            delayMicroseconds( 1 );
            if ( counter >= 255 )
            {
                break;
            }
        }
        laststate = digitalRead( DHT_PIN );
 
        if ( counter >= 255 )
        {
            break;
        }
        data_cnt[i] =  counter;
    }
    /* 
    * ����� ������ ����ó�� 
    * DHT 11�� �����ʹ� 50us�� LOW ��ȣ ���� HIGH�� ��ȣ ���̿� ���� �����͸� LOW / HIGH�� �����մϴ�. (28us : LOW, 70us : HIGH)
    * �̸� �̿��Ͽ� ���� LOW ��ȣ ���̸� �������� ���� HIGH ��ȣ�� ���̸� ���� HIGH/LOW �����ͷ� ������ �� �ֽ��ϴ�.
    */
    for ( int i = 0; i < MAX_TIMINGS; i++ )
    {
        /* ó�� 3�� �����ʹ� ���� �غ� ��ȣ�� ���� */
        if ( (i >= 4) && (i % 2 == 0) )
        {
            /* ��&���� ������ ���� */
            data[get_data / 8] <<= 1;
            /* ���� HIGH ��ȣ�� ���̰� ���� LOW ��ȣ���� ª���� LOW, ��� HIGH �� �з�, ���� */
            if ( data_cnt[i] > data_cnt[i-1] ){
                data[get_data / 8] |= 1;
            }
            get_data++;
        }
    }
    #if COUNT_DEBUG
    /* COUNT_DEBUG�� flag �� 1�� ������ �������ϸ� ����� counter ���� Ȯ���� �� �ֽ��ϴ�. */
    printf("\r\ncounter :");
    for(int i=0; i<MAX_TIMINGS; i++)
    {
        if ( (i >= 4) && (i % 2 == 0) )
        {
            printf(":(%d)",data_cnt[i]);    // HIGH/LOW data
        }else{
            printf(" %d",data_cnt[i]);      // other data (start + Reference)
        }
    }
    printf("\r\n");
    #endif
    /* �� 40 bits (8bit x 5 ) �����Ͱ� ���������� ���Դ��� Ȯ�� �� üũ�� �˻�(CRC), �½��� ������ ��� */
    if ( (get_data >= 40) && (data[4] == ( (data[0] + data[1] + data[2] + data[3]) & 0xFF) ) )
    {
        float h = (float)((data[0] << 8) + data[1]) / 10;
        if ( h > 100 ){
            h = data[0];	// for DHT11
        }
     float c = (float)(((data[2] & 0x7F) << 8) + data[3]) / 10;

        if ( c > 125 ){
            c = data[2];	// for DHT11
        }
        if ( data[2] & 0x80 ){
            c = -c;
        }
        float f = c * 1.8f + 32;
        printf( "Humidity = %.1f %% Temperature = %.1f *C (%.1f *F)\n", h, c, f );
    }else{
        printf( "CRC  %d:%d | Get data(>40) : %d | ",data[4], ( (data[0] + data[1] + data[2] + data[3]) & 0xFF), get_data );
        printf( "Data not good, skip\n" );
    }
}
int main(void)
{
    printf( "Raspberry Pi DHT11 temperature/humidity test\n" );
    if (wiringPiSetup() == -1) return 1;

    while(1)
    {
        read_dht_data();  // DHT �½��� ���� ������ �б� �Լ� ȣ��
        delay(2000);    // ���� �б���� 2�� ����
    }
 
    return(0);
}