##ex14 7세그먼트4digit
## 세그먼트에 n값을 출력

import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

segments = (21,16,6,19,26,20,5,13)

for seg in segments :
    GPIO.setup(seg,GPIO.OUT)
    GPIO.output(seg, 1)
    
digits = (24,23,18,4)

for dig in digits :
    GPIO.setup(dig, GPIO.OUT)
    GPIO.output(dig, 0)
    

seg = {
    '0' : (1,1,1,1,1,1,0,0),
    '1' : (0,1,1,0,0,0,0,0),
    '2' : (1,1,0,1,1,0,1,0),
    '3' : (1,1,1,1,0,0,1,0),
    '4' : (0,1,1,0,0,1,1,0),
    '5' : (1,0,1,1,0,1,1,0),
    '6' : (1,0,1,1,1,1,1,0),
    '7' : (1,1,1,1,1,1,1,0),
    '8' : (1,1,1,1,0,1,1,0),
    '9' : (0,0,0,0,1,0,0,1),
   # 'DOT' : (0,0,0,0,0,0,0,1)
}

try:
    while True:
        n = 1234
        s = str(n).rjust(4) #seg 딕셔너리의 키 값이 문자이기 때문에 변환과정이 필요
        for digit in range(4):
            for loop in range(0,8):
                GPIO.output(segments[loop], seg[s[digit]][loop])
            GPIO.output(digits[digit], 0)
            time.sleep(1)
            GPIO.output(digits[digit], 1)
	   time.sleep(1)
finally:
    GPIO.cleanup()
