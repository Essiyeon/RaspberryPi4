##ex22 릴레이모듈

import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)

GPIO.setmode(GPIO.BCM)
GPIO.setup(4,GPIO.OUT)

try:
    while True:
        GPIO.output(4,1)
        time.sleep(1)
        GPIO.output(4,0)
        time.sleep(1)

finally:
    GPIO.cleanup()
