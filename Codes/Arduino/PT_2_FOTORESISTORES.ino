const int verde = 9;
const int azul = 6;
const int rojo = 5;


const int fotores = A0;
const int fotores1 = A1;
const int fotores2 = A2;

int valorFoto = 0;
int valorFoto1 = 0;
int valorFoto2 = 0;

int mapa = 0;
int mapa1 = 0;
int mapa2 = 0;

void setup() {

  pinMode (verde, OUTPUT);
   pinMode (azul , OUTPUT);
    pinMode (rojo, OUTPUT);
    Serial.begin(9600);

}

void loop() {

  valorFoto = analogRead(fotores);
  valorFoto1 = analogRead(fotores1);
  valorFoto2 = analogRead(fotores2);
  delay(5);

  mapa = map(valorFoto, 35, 200, 0, 255);
  mapa1 = map(valorFoto1, 65, 400, 0, 255);
  mapa2 = map(valorFoto2, 70, 500, 0, 255);

  analogWrite(rojo, mapa); 
  analogWrite(verde, mapa1); 
  analogWrite(azul, mapa2); 

   Serial.print(" rojo: ");
  Serial.println(mapa);

  
  /*Serial.print(valorFoto);
  Serial.print(" rojo: ");
  Serial.println(valorFoto/4);
  Serial.println(" ");*/
   /*Serial.print(valorFoto);
  Serial.print(" rojo: ");
  Serial.println(mapa);
/*  analogWrite(verde, 0);
  analogWrite(azul, 0);
   analogWrite(rojo, 255);
   delay(5000);

   analogWrite(verde, 255);
    analogWrite(azul, 0);
     analogWrite(rojo, 0);
     delay(5000);

   analogWrite(verde, 0);
    analogWrite(azul, 255);
     analogWrite(rojo, 0);
     delay(5000); */

}
