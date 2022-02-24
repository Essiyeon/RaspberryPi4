import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(14,GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(15,GPIO.OUT, initial=GPIO.HIGH)

p=GPIO.PWM(14,50)
p.start(0)
q=GPIO.PWM(15,50)
q.start(100)

while True:
    for i in range(0,101,5):
        p.ChangeDutyCycle(i)
        time.sleep(0.1)
    for j in range(100,-1,-5):
        q.ChangeDutyCycle(j)
        time.sleep(0.1)

p.stop()
q.stop()
GPIO.cleanup()
