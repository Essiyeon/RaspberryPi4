##ex21 �����İŸ�����
import RPi.GPIO as GPIO
import time


GPIO.setwarnings(False)

GPIO.setmode(GPIO.BCM)
#23(Trig)
GPIO.setup(23, GPIO.OUT)
#24(Echo)
GPIO.setup(24, GPIO.IN)

try:
    while True:
        GPIO.output(23, False)
        time.sleep(0.5)

        GPIO.output(23, True)
        time.sleep(0.001)
        GPIO.output(23, False)

        # 18���� OFF�� �Ǵ� ������ ���۽ð����� ����
        while GPIO.input(24) == 0:
            start = time.time()

        # 18���� ON�� �Ǵ� ������ �ݻ��� ���Žð����� ����
        while GPIO.input(24) == 1:
            stop = time.time()

        # �����İ� �ǵ��ƿ��� �ð����� �Ÿ��� ����Ѵ�
        time_interval = stop - start
        distance = time_interval * 17000
        distance = round(distance, 2)
        ##distance = time_interval / 58



        print("Distance => ", distance, "cm")

except KeyboardInterrupt:
    GPIO.cleanup()

