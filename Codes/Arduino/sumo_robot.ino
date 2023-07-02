// Definición de variables y constantes relacionadas con el motor derecho
const int IN3 = 11;  // Pin digital 11 para controlar sentido giro motor izquierdo
const int IN4 = 10;  // Pin digital 10 para controlar sentido giro motor izquierdo
const int ENB = 9;
 
const int vel = 255;
 
 
// Definición de variables y constantes relacionadas con los sensores IR
int lecturaSensorIzq; // Almacena el valor de la lectura del sensor izquierdo
int lecturaSensorDer; // Almacena el valor de la lectura del sensor derecho
const int sensorIzqPin = A0; // El sensor izq irá conectado al pin analógico A0
const int sensorDerPin = A1; // El sensor derecho irá conectado al pin analógico A1
 
void lecturaSensorIR()
{
  lecturaSensorIzq = digitalRead(sensorIzqPin); // Almacena la lectura del sensor izquierdo
  lecturaSensorDer = digitalRead(sensorDerPin); // Almacena la lectura del sensor derecho
  Serial.print(lecturaSensorIzq);
  Serial.println(lecturaSensorDer);

  digitalWrite(trig, LOW);

  delay(2);

  digitalWrite(trig, HIGH);

  delay(5);

  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  distance = (duration/2)*0.0343;
  
  delay(100);        
}

void setup() {
  // put your setup code here, to run once:
  pinMode( sensorIzqPin  , INPUT) ;
  pinMode( sensorDerPin  , INPUT) ;
  Serial.begin(9600); // Se inicia el puerto de comunicaciones en serie
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   lecturaSensorIR(); // Se lee el valor de los sensores IR
  // Se analiza el resultado de los sensores para hacer que el robot siga la línea negra
 
   // Si el resultado de ambos sensores es 0 (zona blanca) el robot sigue se para
  if(lecturaSensorIzq == 0 &&  lecturaSensorDer == 0 && distance < 16)
  {
   Serial.println("robot avanza");
   //robotAvance(); 
    digitalWrite (IN1, HIGH);
    digitalWrite (IN2, LOW);
    analogWrite (ENA, vel); 

    digitalWrite (IN3, HIGH);
    digitalWrite (IN4, LOW);
    analogWrite (ENB, vel);
    
  }
  
  if(lecturaSensorIzq == 0 &&  lecturaSensorDer == 0 && distance > 15)
  {
    Serial.println("robot buscando enemigo");
   //robotAvance(); 
    digitalWrite (IN1, HIGH);
    digitalWrite (IN2, LOW);
    analogWrite (ENA, vel); 

    digitalWrite (IN3, LOW);
    digitalWrite (IN4, LOW);
    analogWrite (ENB, vel);
    
  }
  // Si el izquierdo retorna 0 (zona blanca) y el derecho 1 (negra) el robot gira derecha
  if (lecturaSensorIzq == 0 &&  lecturaSensorDer == 1 && distance > 15)
  {
    Serial.println("robot der");
    Serial.println("robot buscando enemigo");
    //robotDerecha();
    //  Motor izquierdo
    // Se activa el motor izquierdo
    digitalWrite (IN1, HIGH);
    digitalWrite (IN2, LOW);
    analogWrite (ENA, vel); //Velocidad motor A  
   
    // Motor derecho
    // Se para el motor derecho
    digitalWrite (IN3, LOW);
    digitalWrite (IN4, LOW);
    analogWrite (ENB, vel); //Velocidad motor A  
     // El robot gira a la derecha
 
  }

  // Si el izquierdo retorna 0 (zona blanca) y el derecho 1 (negra) el robot gira derecha
  if (lecturaSensorIzq == 1 &&  lecturaSensorDer == 0 && distance > 15)
  {
    Serial.println("robot izq");
    Serial.println("robot buscando enemigo");
    //robotDerecha();
    //  Motor izquierdo
  // Se activa el motor izquierdo
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, vel); //Velocidad motor A  
 
  // Motor derecho
  // Se para el motor derecho
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, vel); //Velocidad motor A  
     // El robot gira a la derecha
 
  }
 
  // Si ambos sensores retornan 1 (zona negra) el robot sigue recto
  if (lecturaSensorIzq == 1 && lecturaSensorDer == 1 )
  {
   
    Serial.println("robot atras");
   //robotAvance(); 
    digitalWrite (IN1, LOW);
    digitalWrite (IN2, HIGH);
    analogWrite (ENA, vel); 

    digitalWrite (IN3, LOW);
    digitalWrite (IN4, HIGH);
    analogWrite (ENB, vel);
    
  }
}
