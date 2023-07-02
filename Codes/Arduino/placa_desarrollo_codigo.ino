
#include <IRremote.h>

#include <DHT.h>
DHT dht(10, DHT11);


#define boton_1 0xFF30CF
#define boton_2 0xFF18E7
int sensor = 8;

decode_results codigo;

IRrecv irrecv(sensor);


void setup() {
  // sensor temperatura

  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  dht.begin();

  
  // sensor IR
  Serial.begin(9600);
  irrecv.enableIRIn();

  // semaforo de focos led
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {

  float TempC = dht.readTemperature();
  float TempF = dht.readTemperature(true);

  Serial.println("Temp:" + String(TempC, 1)+"C");
  
 if(irrecv.decode(&codigo)){
    if(codigo.value == boton_1){
      digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);                       // wait for a second
      digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
      delay(100);                       // wait for a second
      digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);                       // wait for a second
      digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
      delay(100);  
      digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);                       // wait for a second
      digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
      delay(100); 
      digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);                       // wait for a second
      digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
      delay(100); 
    }
    if(codigo.value == boton_2){
      digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);                       // wait for a second
      digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
      delay(100);                       // wait for a second
      digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);                       // wait for a second
      digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
      delay(100);  
      digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);                       // wait for a second
      digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
      delay(100); 
      digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(100);                       // wait for a second
      digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
      delay(100);     
    }
  irrecv.resume();
 }

 
  
}
