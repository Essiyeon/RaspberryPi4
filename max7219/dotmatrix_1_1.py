##ex18-3
##���پ� �������� ������ �ذ�
import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)

CLK = 23
DIN = 19
CS = 24
GPIO.setup(DIN,GPIO.OUT)
GPIO.setup(CS,GPIO.OUT)
GPIO.setup(CLK,GPIO.OUT)

DOTDATA = [
    [0x00, 0x7e, 0xff, 0x81, 0x81, 0xff, 0x7e, 0x00],
    [0x00, 0x00, 0x02, 0xff, 0xff, 0x00, 0x00, 0x00],
    [0x00, 0xe6, 0xf7, 0x91, 0x91, 0xdf, 0xce, 0x00],
    [0x00, 0x42, 0xc3, 0x89, 0x89, 0xff, 0x76, 0x00],
    [0x00, 0x30, 0x28, 0x24, 0x22, 0xff, 0xff, 0x00],
    [0x00, 0x8f, 0x8f, 0x89, 0x89, 0xf9, 0x71, 0x00],
    [0x00, 0x7e, 0xff, 0x89, 0x89, 0xfb, 0x72, 0x00],
    [0x00, 0x01, 0xc1, 0x21, 0x11, 0x0f, 0x07, 0x00],
    [0x00, 0x76, 0xff, 0x99, 0x99, 0xff, 0x76, 0x00],
    [0x00, 0x4e, 0xdf, 0x91, 0x91, 0xff, 0x7e, 0x00],
]
def Write_Data_byte(num) :
    GPIO.output(CS,GPIO.LOW)
    Mask = 128;
    for i in range(0,8):
        GPIO.output(CLK,GPIO.LOW)
        Flag = num & Mask
        GPIO.output(DIN,Flag) 
        Mask = Mask >> 1;
        GPIO.output(CLK,GPIO.HIGH)

def Write_Data(address, dat) :
    GPIO.output(CS,GPIO.LOW)
    Write_Data_byte(address)
    Write_Data_byte(dat)
    GPIO.output(CS,GPIO.HIGH)

Write_Data(0x09,0x00)
Write_Data(0x0A,0x03)
Write_Data(0x0B,0x07)
Write_Data(0x0C,0x01)

while True :
for i in range(0,10) :
        for j in range(1,9) :
            Write_Data(j,DOTDATA[i][j-1])
            
        time.sleep(1)
GPIO.cleanup()