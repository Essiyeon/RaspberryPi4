##ex1) LED_Blink.py

import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)

GPIO.setmode(GPIO.BCM)
GPIO.setup(13,GPIO.OUT)

'''
while True:
    GPIO.output(13,True)
    time.sleep(1)
    GPIO.output(13,False)
    time.sleep(1)
'''

for i in range(3):
    GPIO.output(13,True)
    time.sleep(1)
    GPIO.output(13,False)
    time.sleep(1)
    
GPIO.cleanup()
