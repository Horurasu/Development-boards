import machine
import utime

#   ' programa martin joaquin aguilar muñoz ISW18'

ledrojo = machine.Pin(18,machine.Pin.OUT)
ledamarillo = machine.Pin(19,machine.Pin.OUT)
ledverde = machine.Pin(20,machine.Pin.OUT)

while True:
#      'prende el led rojo'
        ledrojo.value(1)
        ledamarillo.value(0)
        ledverde.value(0)
        utime.sleep(2)
        
# #      'prende el led amarillo'
        ledrojo.value(0)
        ledamarillo.value(1)
        ledverde.value(0)
        utime.sleep(2)
        
# #      'prende el led verde'
        ledrojo.value(0)
        ledamarillo.value(0)
        ledverde.value(1)
        utime.sleep(2)
