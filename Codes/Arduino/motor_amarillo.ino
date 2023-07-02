/* 
 *  PROGRAMA QUE UTILIZA EL MODULO CONTROLADOR DE MOTOR 1298N PARA CONTROLAR EL DE UN MOTOR DE CORRIENTE CONTINUA CON CAJA REDUCTORA DE RUEDA 
 *  
 *  
 */
int IN1 = 2; 
int IN2 = 3; // IN2 DE 1.298N a pin digital 5
int ENA = 5; // ENA de 1.298N a pin digital 5


void setup() {

  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop() {

  digitalWrite(ENA, HIGH); // HABILITAR MOTOR A (giro en un sentido) 
  digitalWrite(ENA, HIGH); // IN1 a 0 
  digitalWrite(ENA, HIGH); // IN2 a 1 
  delay(3000);  // demora de 3 seg. 

  digitalWrite(ENA, LOW); // ENA en 0 para deshabilitar motor 
  delay(2000); 

}
