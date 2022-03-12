##ex20 ¡∂¿ÃΩ∫∆Ω

import RPi.GPIO as GPIO
import time
import smbus
  
GPIO.setwarnings(False)

address = 0x48
bus = smbus.SMBus(1)
cmd = 0x40

Z_Pin = 4

GPIO.setmode(GPIO.BCM)
GPIO.setup(Z_Pin,GPIO.IN,GPIO.PUD_UP)

def analogRead(chn):
    bus.write_byte(address,cmd+chn)
    value = bus.read_byte(address)
    return value

def analogWrite(value):
    bus.write_byte_data(address,cmd,value)
    
while True:
    val_Z = GPIO.input(Z_Pin)
    val_Y = analogRead(1)
    val_X = analogRead(0)
    print("Click: %d, Y: %d, X: %d" % (val_Z, val_Y, val_X))
