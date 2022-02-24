##ex8) PCF8591_ADC.py
import smbus
import time

bus = smbus.SMBus(1)
add = 0x48

# �Ƴ��αװ��� ����
def readAD():
    analog = bus.read_byte(add)
    return analog

while True:
    bus.write_byte(add,0x00) #0��ä��(��������)
    time.sleep(0.01)
    readAD()
    an0 = readAD()
    
    bus.write_byte(add,0x01) #1��ä��(�µ�����)
    time.sleep(0.01)
    readAD()
    an1 = readAD()
    
    bus.write_byte(add,0x02) #2��ä��(�߰���������)
    time.sleep(0.01)
    readAD()
    an2 = readAD()
    
    bus.write_byte(add,0x03) #3��ä��(��⳻�尡������)
    time.sleep(0.01)
    readAD()
    an3 = readAD()
    
    print("value = %3d, %3d, %3d, %3d" % (an0, an1, an2, an3))
