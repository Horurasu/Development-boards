// programa que utiliza el modulo controlador de motor L298N para controlar el control el giro de un motor de corriente continua con caja reductora y rueda.

  int IN1 = 2;   // IN3 dec L298N a pin digital 4
  int IN2 = 3;   // IN4 dec L298N a pin digital 6
  int ENA = 5;   // ENA2 dec L298N a pin digital 7
  
  
void setup() {
  pinMode(IN1, OUTPUT);// pin 4 como salida
  pinMode(IN2, OUTPUT);// pin 6 como salida
  pinMode(ENA, OUTPUT);// pin 7 como salida
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ENA, HIGH);  //habilita motor B(giro en un sentido)                      
  digitalWrite(IN1, LOW); // IN1 a 0
  digitalWrite(IN2, HIGH);  //IN2 a 1 
  delay(5000); 

  digitalWrite(ENA,LOW); //ENA en 0 para deshabilitar motor
  delay(3000); 

  digitalWrite(ENA, HIGH);  //habilita motor B(giro en un sentido)                      
  digitalWrite(IN1, HIGH); // IN1 a 0
  digitalWrite(IN2, LOW);  //IN2 a 1 
  delay(5000);

  digitalWrite(ENA, LOW); //ENA en 0 para deshabilitar motor
  delay(3000); 

}
