
#include <Servo.h> //se declaran las librerias para poder usar el servomotor


Servo servo1;
  //CONECTAR SEÑAL DEL MOTOR AL PUERTO DIGITAL 2 DEL ARDUINO

int pir_pin = 2; // variable para la lectura del sensor PIR


int PINSERVO = 3;
      //EXPRESADOS EN MICROSEGUNDOS
int PULSOMIN = 1000;  //EQUIVALE PARA 0 GRADOS
int PULSOMAX = 2000;  //EQUIVALE PARA 180 GRADOS  

void setup() {
  servo1.attach(PINSERVO, PULSOMIN, PULSOMAX);
  //ATTACH REQUIERE LOS VALORES EL MICROSEGUNDOS EN VEZ DE MILISEGUNDOS
  pinMode(pir_pin, INPUT); //declarar la variable de pir como entrada de datos
  Serial.begin(9600);
}

void loop() {
  
  delay(1000);
  
  if(digitalRead(pir_pin) == HIGH)
  {
    Serial.println("Compa ya se metieron a robar!!!");
    servo1.write(180);
    delay(4000);
    servo1.write(0);
    delay(4000);
  }
  else
  {
    Serial.println("Todo tranquilo de momento");
  }
}
