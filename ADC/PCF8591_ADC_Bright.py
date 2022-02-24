##ex9) PCF8591_ADC_Bright.py

import RPi.GPIO as GPIO
import smbus
import time

bus = smbus.SMBus(1)

add = 0x48

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(18,GPIO.OUT)

led = GPIO.PWM(18,50)
led.start(0)

def readAD():
    analog = bus.read_byte(add)
    return analog

while True:
    bus.write_byte(add,0x02)
    time.sleep(0.1)
    readAD()
    an2 = readAD()/10
    
    led.ChangeDutyCycle(an2)
    time.sleep(0.1)
    
led.stop()
GPIO.cleanup()
