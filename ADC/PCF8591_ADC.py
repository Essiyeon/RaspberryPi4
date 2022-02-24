##ex8) PCF8591_ADC.py
import smbus
import time

bus = smbus.SMBus(1)
add = 0x48

# 아날로그값을 받음
def readAD():
    analog = bus.read_byte(add)
    return analog

while True:
    bus.write_byte(add,0x00) #0번채널(조도센서)
    time.sleep(0.01)
    readAD()
    an0 = readAD()
    
    bus.write_byte(add,0x01) #1번채널(온도센서)
    time.sleep(0.01)
    readAD()
    an1 = readAD()
    
    bus.write_byte(add,0x02) #2번채널(추가가변저항)
    time.sleep(0.01)
    readAD()
    an2 = readAD()
    
    bus.write_byte(add,0x03) #3번채널(모듈내장가변저항)
    time.sleep(0.01)
    readAD()
    an3 = readAD()
    
    print("value = %3d, %3d, %3d, %3d" % (an0, an1, an2, an3))
