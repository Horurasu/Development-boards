/*
  Nombre: Robot Siguelíneas
  Autor: Daniel Pascual Gallegos
  Fecha: Febrero 2017
  Funcionalidad: este proyecto representa la típica función
  del robot siguelíneas que se desplaza siguiendo una linea recta
  de color negro.
*/
// Definición de variables y constantes relacionadas con el motor izquierdo
const int IN1 = 13;  // Pin digital 13 para controlar sentido giro motor izquierdo
const int IN2 = 12;  // Pin digital 12 para controlar sentido giro motor izquierdo
const int ENA = 6;
 
// Definición de variables y constantes relacionadas con el motor derecho
const int IN3 = 11;  // Pin digital 11 para controlar sentido giro motor izquierdo
const int IN4 = 10;  // Pin digital 10 para controlar sentido giro motor izquierdo
const int ENB = 5;
 
const int vel = 175;
 
// Definición de variables y constantes relacionadas con los sensores IR
int lecturaSensorIzq; // Almacena el valor de la lectura del sensor izquierdo
int lecturaSensorDer; // Almacena el valor de la lectura del sensor derecho
const int sensorIzqPin = A0; // El sensor izq irá conectado al pin analógico A0
const int sensorDerPin = A1; // El sensor derecho irá conectado al pin analógico A1
 
void setup()
{
  // Se declaran todos los pines como salidas
  // Pines asociados a los motores
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode( sensorIzqPin  , INPUT) ;
  pinMode( sensorDerPin  , INPUT) ;
  Serial.begin(9600); // Se inicia el puerto de comunicaciones en serie
}
 
void loop()
{
 
  lecturaSensorIR(); // Se lee el valor de los sensores IR
  // Se analiza el resultado de los sensores para hacer que el robot siga la línea negra
 
  // Si el resultado de ambos sensores es 0 (zona blanca) el robot sigue se para
  if(lecturaSensorIzq == 0 &&  lecturaSensorDer == 0)
  {
    
    robotParar(); // El robot para
 
  }
  // Si el izquierdo retorna 0 (zona blanca) y el derecho 1 (negra) el robot gira derecha
  if (lecturaSensorIzq == 0 &&  lecturaSensorDer == 1)
  {
    robotDerecha();
     // El robot gira a la derecha
 
  }
  // Si el izquierdo retorna 1 (zona negra) y el derecho 0 (blanca) el robot gira izquierda
  if (lecturaSensorIzq == 1 &&  lecturaSensorDer == 0)
  {
   robotIzquierda();
 
  }
  // Si ambos sensores retornan 0 (zona negra) el robot sigue recto
  if (lecturaSensorIzq == 1 && lecturaSensorDer == 1)
  {
    robotAvance(); // El robot avanza
    Serial.println("robot avanza");
  }
 
}
/*
  Función lecturaSensorIR: leerá el valor del sensor de infrarrojos TCRT5000
  y lo almacena en una variable. Dicho sensor retornará el valor 0 (LOW) si
  el sensor está en zona blanca y el valor 1 (HIGH) si el sensor está en zona
  negra.
*/
void lecturaSensorIR()
{
  lecturaSensorIzq = digitalRead(sensorIzqPin); // Almacena la lectura del sensor izquierdo
  lecturaSensorDer = digitalRead(sensorDerPin); // Almacena la lectura del sensor derecho
 
  Serial.println("El valor del sensor izquierdo es ");
  Serial.println(lecturaSensorIzq);
 
   Serial.println("El valor del sensor derecho es ");
  Serial.println(lecturaSensorDer);
 
}
/*
  Función robotAvance: esta función hará que ambos motores se activen a máxima potencia
  por lo que el robot avanzará hacia delante
*/
void robotAvance()
{
  // Motor izquierdo
  // Al mantener un pin HIGH y el otro LOW el motor gira en un sentido
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, vel); //Velocidad motor A
 
  // Motor derecho
  // Al mantener un pin HIGH y el otro LOW el motor gira en un sentido
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, vel); //Velocidad motor B  
}
/*
  Función robotRetroceso: esta función hará que ambos motores se activen a máxima potencia 
  en sentido contrario al anterior por lo que el robot avanzará hacia atrás
*/
void robotRetroceso()
{
  // Motor izquierdo
  // Al mantener un pin LOW y el otro HIGH el motor gira en sentido contrario al anterior
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, vel); //Velocidad motor A  
 
  // Motor derecho
  // Al mantener un pin LOW y el otro HIGH el motor gira en sentido contrario al anterior
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, vel); //Velocidad motor B  
}
 
/*
  Función robotDerecha: esta función acccionará el motor izquierdo y parará el derecho
  por lo que el coche girará hacia la derecha (sentido horario)
*/
void robotDerecha()
{
  //  Motor izquierdo
  // Se activa el motor izquierdo
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, vel); //Velocidad motor A  
 
  // Motor derecho
  // Se para el motor derecho
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, vel); //Velocidad motor A  
 
}
/*
  Función robotIzquierda: esta función acccionará el motor derecho y parará el izquierdo
  por lo que el coche girará hacia la izquierda (sentido antihorario)
*/
void robotIzquierda ()
{
   //  Motor izquierdo
  // Se para el motor izquierdo
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, vel); //Velocidad motor A  
 
  // Motor derecho
  // Se activa el motor derecho
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, vel); //Velocidad motor A  
}
/*
  Función robotParar: esta función parará ambos motores
  por lo que el robot se parará.
*/
void robotParar()
{
  // Motor izquierdo
  // Se para el motor izquierdo
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
 
  // Motor derecho
  // Se para el motor derecho
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
 
}
