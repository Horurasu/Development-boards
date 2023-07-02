from machine import Pin, PWM
import time

#  'codigo martin joaquin aguilar muñoz isw18'

servo1 = PWM(Pin(15))
servo1.freq(50)

servo1.duty_ns()

servo1.duty_u16()

while True:
    servo1.duty_ns(500000)
    time.sleep_ms(500)
    
    servo1.duty_ns(1500000)
    time.sleep_ms(500)
    
    servo1.duty_ns(2500000)
    time.sleep_ms(500)
    
    servo1.duty_ns(1500000)
    time.sleep_ms(500)
    

