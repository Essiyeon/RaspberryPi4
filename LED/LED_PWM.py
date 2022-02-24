##ex5) LED_PMW.py

from gpiozero import PWMLED
from signal import pause

led = PWMLED(13)
led.pulse()
pause()
