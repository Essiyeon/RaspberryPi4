##ex6) pin 8번의 LED가 blink되다가
##버튼을 누르면 pin 10번의 LED가 blink

import RPi.GPIO as GPIO
from time import sleep
 
GPIO.setwarnings(False)

GPIO.setmode(GPIO.BCM)
GPIO.setup(14,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(15,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(21,GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
GPIO.output(14,False)
GPIO.output(15,False)

while True:
    GPIO.output(14,GPIO.HIGH)
    sleep(0.5)
    GPIO.output(14,GPIO.LOW)
    sleep(0.5)
    if GPIO.input(21) == 1:
        for i in range(0,5,1):
            GPIO.output(14,GPIO.LOW)
            GPIO.output(15,GPIO.HIGH)
            sleep(0.5)
            GPIO.output(15,GPIO.LOW)
            sleep(0.5)
GPIO.cleanup()
