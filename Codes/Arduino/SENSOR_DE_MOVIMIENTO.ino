int pir_pin = 2;
int led_pin = 3;


void setup() {
  pinMode(pir_pin, INPUT);
  pinMode(led_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(pir_pin) == HIGH)
  {
    digitalWrite(led_pin, HIGH);
    Serial.println("Ama se metio un pejelagarto");
  }
  else
  {
    digitalWrite(led_pin, LOW);
    Serial.println("Todo facha");
  }
}
