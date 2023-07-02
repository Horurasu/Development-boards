from machine import PWM, ADC, Pin
import utime

a=PWM(Pin(15))
a.freq(50)

b=PWM(Pin(14))
b.freq(50)

c=PWM(Pin(13))
c.freq(50)

d=PWM(Pin(12))
d.freq(50)


adc = ADC(1)

pot = 0

eleccion = 2

if (eleccion == 1):
    while True:
        pot =int(adc.read_u16()*179/65535)
        print(pot) 
        ton=(pot+45)*100000/9
        a.duty_ns(int(ton))    
        utime.sleep_ms(300)
        
elif (eleccion == 2):
    while True:
        pot =int(adc.read_u16()*179/65535)
        print(pot)
        ton=(pot+45)*100000/9
        b.duty_ns(int(ton))    
        utime.sleep_ms(300)
        
elif (eleccion == 3):        
    while True:
        pot =int(adc.read_u16()*179/65535)
        print(pot)
        ton=(pot+45)*100000/9
        c.duty_ns(int(ton))    
        utime.sleep_ms(300)
        
elif (eleccion == 4):        
    while True:
        pot =int(adc.read_u16()*179/65535)
        print(pot)
        ton=(pot+45)*100000/9
        d.duty_ns(int(ton))    
        utime.sleep_ms(300)
else:
    print("error")
      

    
    

    
    
    
        
    
