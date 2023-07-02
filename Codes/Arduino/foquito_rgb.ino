const int verde = 9;
const int azul = 6;
const int roja = 5;


void setup() {
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(roja, OUTPUT);

}

void loop() {
  analogWrite(verde, 0);
  analogWrite(azul, 255);
  analogWrite(roja, 255);
  delay(5000);
  analogWrite(verde, 255);
  analogWrite(azul, 0);
  analogWrite(roja, 255);
  delay(5000);
  analogWrite(verde, 255);
  analogWrite(azul, 255);
  analogWrite(roja, 0);
  delay(5000);

}
