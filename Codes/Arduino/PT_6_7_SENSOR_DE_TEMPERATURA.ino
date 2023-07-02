//codigo sensor temperatura y sensor movimiento sini pantalla lcd
/*
#include <DHT.h>
DHT dht(9, DHT11);

#define echo 10
#define trig 11



void setup() {
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  dht.begin();
  pinMode(echo, INPUT);     // define el pin 2 como entrada (echo)
  pinMode(trig, OUTPUT);    // define el pin 3 como salida  (triger)
}

void loop() {
  float TempC = dht.readTemperature();
  float TempF = dht.readTemperature(true);

  Serial.println("Temp:" + String(TempC, 1)+"C");

  // genera el pulso de triger por 10ms
  
  int duracion, distancia;  

  digitalWrite(trig, LOW);

  delay(2);

  digitalWrite(trig, HIGH);

  delay(5);

  digitalWrite(trig, LOW);

   duracion = pulseIn(echo, HIGH);

  distancia = (duracion/2)/29;

  Serial.print(distancia); 
  Serial.println("cm");
  
   
  delay(400);

  
}

*/

#include <DHT.h>
DHT dht(9, DHT11);

#define echo 10
#define trig 11

#include <LiquidCrystal.h> // import libreria

LiquidCrystal lcd(7, 6, 5, 4, 3 ,2); // pines RS, E, D4, D5, D6 ,D7 de modulo



void setup() {
  lcd.begin(16,2); //inicializa a display de  16 columnas y 2 lineas
  Serial.begin (9600);       // inicializa el puerto seria a 9600 baudios
  dht.begin();
  pinMode(echo, INPUT);     // define el pin 2 como entrada (echo)
  pinMode(trig, OUTPUT);    // define el pin 3 como salida  (triger)
}

void loop() {
  float TempC = dht.readTemperature();
  float TempF = dht.readTemperature(true);
  
  // genera el pulso de triger por 10ms
  
  int duracion, distancia;  

  digitalWrite(trig, LOW);

  delay(2);

  digitalWrite(trig, HIGH);

  delay(5);

  digitalWrite(trig, LOW);

   duracion = pulseIn(echo, HIGH);

  distancia = (duracion/2)/29;

  

  lcd.setCursor(0,0); // ubica cursor en columna 0 , linea 0
  lcd.print(TempF); // escribe el texto en pantalla
  lcd.print("f."); // escribe el texto en pantalla
  lcd.setCursor(0,1); //ubica el cursor en comuna 0 , linea 1
  lcd.print(distancia); // escribe el valor en segundos devuelto por funciones
  lcd.print("cm."); // imprime a continuacion segundos
   
  delay(400);
}
