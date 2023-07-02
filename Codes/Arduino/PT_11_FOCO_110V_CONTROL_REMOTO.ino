// CODIGO PARA PODER DETECTAR LOS VALORES SOBRE CADA BOTON
/*
#include <IRremote.h>

int sensor = 8;
decode_results codigo;

IRrecv irrecv(sensor);


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
 if(irrecv.decode(&codigo)){
  Serial.println(codigo.value, HEX);
  irrecv.resume();
 }
 delay (100);
}
*/



 /*codigo de foco led con tiempo a control remoto

#include <IRremote.h>
#define boton_1 0xFF30CF
#define boton_2 0xFF18E7

int LEDROJO = 7;

int sensor = 8;

decode_results codigo;

IRrecv irrecv(sensor);


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(LEDROJO, OUTPUT);
}

void loop() {
 if(irrecv.decode(&codigo)){
  Serial.println(codigo.value, HEX);
    if(codigo.value == boton_1){
      digitalWrite(LEDROJO, !digitalRead(LEDROJO));
       delay(2500);      
    }
  irrecv.resume();
 }
 delay (100);
}

*/




#include <IRremote.h>
/*
#define boton_1 0xFF30CF
#define boton_2 0xFF18E7
*/

#define boton_1 0xFF30CF
#define boton_2 0xFF18E7
int LEDROJO = 7;

int sensor = 8;

decode_results codigo;

IRrecv irrecv(sensor);


void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(LEDROJO, OUTPUT);
}

void loop() {
 if(irrecv.decode(&codigo)){
    if(codigo.value == boton_1){
      digitalWrite(LEDROJO, HIGH
     );
       delay(2500);      
    }
    if(codigo.value == boton_2){
      digitalWrite(LEDROJO, LOW);
       delay(2500);      
    }
  irrecv.resume();
 }
 delay (100);
}
