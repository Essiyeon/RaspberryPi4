##ex17 74hc595 사용 LED제어

import RPi.GPIO as GPIO
import time

GPIO.setwarnings(False)

DATA = 16
CLOCK = 18
LATCH = 22

LED0 = [0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80]
LED1 = [0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff]
LED2 = [0x01, 0x05, 0x15, 0x55, 0xb5, 0xf5, 0xfb, 0xff]
LED3 = [0x01, 0x03, 0x0b, 0x0f, 0x2f, 0x3f, 0xbf, 0xff]

def setup():
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup(DATA, GPIO.OUT)
    GPIO.setup(CLOCK, GPIO.OUT)
    GPIO.setup(LATCH, GPIO.OUT)
    GPIO.output(DATA, GPIO.LOW)
    GPIO.output(CLOCK, GPIO.LOW)
    GPIO.output(LATCH, GPIO.LOW)

def hc595_in(dat):
    for bit in range(0, 8):
        GPIO.output(DATA, 0x80 & (dat << bit))
        GPIO.output(CLOCK, GPIO.HIGH)
        time.sleep(0.001)
        GPIO.output(CLOCK, GPIO.LOW)

def hc595_out():
    GPIO.output(LATCH, GPIO.HIGH)
    time.sleep(0.001)
    GPIO.output(LATCH, GPIO.LOW)

def loop():
    WhichLeds = LED0 #LED값 변경되는곳
    while True:
        for i in range(0, len(WhichLeds)):
            hc595_in(WhichLeds[i])
            hc595_out()
            time.sleep(0.1)

        for i in range(len(WhichLeds)-1, -1, -1):
            hc595_in(WhichLeds[i])
            hc595_out()
            time.sleep(0.1)


if __name__ == '__main__':
    setup()
    try:
        loop()
    except KeyboardInterrupt:
        GPIO.cleanup()
