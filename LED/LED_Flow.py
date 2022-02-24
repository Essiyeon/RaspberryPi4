##ex4) 4개의 LED 순차 점멸

import RPi.GPIO as GPIO
from time import sleep

GPIO.setwarnings(False)

GPIO.setmode(GPIO.BOARD)
GPIO.setup(8, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(10, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(12, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(16, GPIO.OUT, initial=GPIO.LOW)

while True:
    GPIO.output(8, GPIO.HIGH)
    sleep(0.5)
    GPIO.output(8,GPIO.LOW)
    sleep(0.5)
    GPIO.output(10, GPIO.HIGH)
    sleep(0.5)
    GPIO.output(10,GPIO.LOW)
    sleep(0.5)
    GPIO.output(12, GPIO.HIGH)
    sleep(0.5)
    GPIO.output(12,GPIO.LOW)
    sleep(0.5)
    GPIO.output(16, GPIO.HIGH)
    sleep(0.5)
    GPIO.output(16,GPIO.LOW)
    sleep(0.5)
