##ex10) Light_Detection.py

import RPi.GPIO as GPIO
import smbus
import time

bus = smbus.SMBus(1)

add = 0x48

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(14,GPIO.OUT)
buz = GPIO.PWM(14,100)
buz.start(100)
buz.ChangeDutyCycle(80)

def readAD():
    analog = bus.read_byte(add)
    return analog
while True:
    bus.write_byte(add,0x00)
    time.sleep(0.1)
    readAD()
    an0 = readAD()
    print ("%3d\n" % an0)
    
    if an0 < 100:
        buz.ChangeFrequency(an0)
    
GPIO.cleanup()
