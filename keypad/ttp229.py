##ex24_2 TTP229 Å°ÆÐµå

import RPi.GPIO as GPIO
import time
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

SCL = 21
SDO = 20

GPIO.setup(SCL, GPIO.OUT)
GPIO.setup(SDO, GPIO.IN,GPIO.PUD_DOWN)

def Read_Keypad():
    result = 0
    for i in range(1,9):
        GPIO.output(SCL,GPIO.LOW)
        if GPIO.input(SDO) == 0:
            result = i
        GPIO.output(SCL,GPIO.HIGH)
    return result

try:
    while True:
        value = Read_Keypad()
        if value != 0:
            print(value)
            time.sleep(0.1)
            
except KeyboardInterrupt:
    GPIO.cleanup()
