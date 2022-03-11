##ex19 서브모터

import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)

servo_pin = 4
GPIO.setmode(GPIO.BCM)
GPIO.setup(servo_pin, GPIO.OUT)

pwm = GPIO.PWM(servo_pin, 50)
pwm.start(3.0)

time.sleep(2.0)
GPIO.cleanup()
