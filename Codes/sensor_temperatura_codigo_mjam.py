import Adafruit_DHT #codigo que realiza la toma de temeperatura del sensor DHT11
import time

while True:
    sensor = Adafruit_DHT.DHT11  #Cambia por DHT22 y solo si usas dicho sensor
    pin = 4 #Pin en la raspberry donde conectamos el sensor
    humedad, temperatura = Adafruit_DHT.read_retry(sensor, pin) 
    
    print('Humedad', humedad)
    print('Temperatura', temperatura)
    
    time.sleep(1) #Cada segundo se evalua el sensor