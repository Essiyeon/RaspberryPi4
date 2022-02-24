##ex12) LM35.py

import time
import smbus
bus = smbus.SMBus(1)

Address = 0x48

def readAD():
    analog = bus.read_byte(Address)
    return analog

while True:
    bus.write_byte(Address,0x00)
    readAD()
    an0 = readAD()
    an0 = (an0 * 1.953)/10
    print("%4.3f" % an0)
    time.sleep(0.5)
