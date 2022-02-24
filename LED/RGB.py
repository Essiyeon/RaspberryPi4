##ex7 RGB_LED.py

import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)

GPIO.setmode(GPIO.BCM)
GPIO.setup(17,GPIO.OUT,initial=GPIO.HIGH)
GPIO.setup(22,GPIO.OUT,initial=GPIO.HIGH)
GPIO.setup(27,GPIO.OUT,initial=GPIO.HIGH)

while True:
    
    GPIO.output(17,GPIO.LOW)
    time.sleep(1)
    GPIO.output(17,GPIO.HIGH)

    GPIO.output(22,GPIO.LOW)
    time.sleep(1)
    GPIO.output(22,GPIO.HIGH)
    
    GPIO.output(27,GPIO.LOW)
    time.sleep(1)
    GPIO.output(27,GPIO.HIGH)
    
GPIO.cleanup()