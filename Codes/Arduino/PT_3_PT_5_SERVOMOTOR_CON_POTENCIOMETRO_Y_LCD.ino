//CODIGO PARA USAR EL SERVOMOTOR AUTOMATICAMENTE

/*
#include <Servo.h> //se declaran las librerias para poder usar el servomotor

Servo servo1;
  //CONECTAR SEÑAL DEL MOTOR AL PUERTO DIGITAL 2 DEL ARDUINO
int PINSERVO = 2;
      //EXPRESADOS EN MICROSEGUNDOS
int PULSOMIN = 1000;  //EQUIVALE PARA 0 GRADOS
int PULSOMAX = 2000;  //EQUIVALE PARA 180 GRADOS  

void setup() {
  servo1.attach(PINSERVO, PULSOMIN, PULSOMAX);
  //ATTACH REQUIERE LOS VALORES EL MICROSEGUNDOS EN VEZ DE MILISEGUNDOS
}

void loop() {
  servo1.write(0);
  delay(5000);
  servo1 .write(180);
  delay(5000);
}
*/



//CODIGO PARA SERVOMOTOR CON POTENCIOMETRO


#include <Servo.h> //se declaran las librerias para poder usar el servomotor

#include <LiquidCrystal.h> // import libreria

LiquidCrystal lcd(7, 6, 5, 4, 3 ,2); // pines RS, E, D4, D5, D6 ,D7 de modulo



Servo servo1;
  //CONECTAR SEÑAL DEL MOTOR AL PUERTO DIGITAL 2 DEL ARDUINO
int PINSERVO = 8;
      //EXPRESADOS EN MICROSEGUNDOS
int PULSOMIN = 1000;  //EQUIVALE PARA 0 GRADOS
int PULSOMAX = 2000;  //EQUIVALE PARA 180 GRADOS  
int VALORPOT;
int ANGULO;
int POT = 0;


void setup() {
  servo1.attach(PINSERVO, PULSOMIN, PULSOMAX);
  //ATTACH REQUIERE LOS VALORES EL MICROSEGUNDOS EN VEZ DE MILISEGUNDOS

  //LAS ENTRADAS ANALOGICAS NO NECESITAN INICIALIZACION

   lcd.begin(16,2); //inicializa a display de  16 columnas y 2 lineas
}

void loop() {
  VALORPOT = analogRead(POT);
              // las entradas analogicas pueden variar entre 0 a 1023 y al rango a cual debe convertirse (como write que toma valores de 0-180)
  ANGULO = map(VALORPOT, 0, 1023, 0, 180);
  servo1.write(ANGULO);
  delay(20); //para darle tiempo al servomotor

  lcd.setCursor(0,0); // ubica cursor en columna 0 , linea 0
  lcd.print(ANGULO); // escribe el texto en pantalla
  lcd.setCursor(0,1); //ubica el cursor en comuna 0 , linea 1
  lcd.print("grados."); // imprime a continuacion 
  
}
