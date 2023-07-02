
#define verde 18
#define amarillo 19
#define rojo 21


void setup() {
  
  pinMode(verde,OUTPUT);
  pinMode(amarillo,OUTPUT);
  pinMode(rojo,OUTPUT);
  
}

void loop() {
  digitalWrite(verde,HIGH);
  delay(500);
  digitalWrite(verde,LOW);
  delay(500);
   digitalWrite(amarillo,HIGH);
  delay(500);
  digitalWrite(amarillo,LOW);
  delay(500);
   digitalWrite(rojo,HIGH);
  delay(500);
  digitalWrite(rojo,LOW);
  delay(500);


}
