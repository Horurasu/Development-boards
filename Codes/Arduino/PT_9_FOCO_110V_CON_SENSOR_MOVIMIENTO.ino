
#define echo 8
#define trig 9


void setup() {

  pinMode(echo, INPUT);     // define el pin 2 como entrada (echo)
  pinMode(trig, OUTPUT);    // define el pin 3 como salida  (triger)
  
  pinMode(3, OUTPUT);
 
}

// the loop function runs over and over again forever
void loop() {
  
  long duration, distance;

  
  digitalWrite(trig, LOW);

  delay(2);

  digitalWrite(trig, HIGH);

  delay(5);

  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  distance = (duration/2)*0.0343;

  if (distance < 50)
  {
   digitalWrite(3, HIGH);   
   delay(2500);                       
   digitalWrite(3, LOW); 
   delay(2500);                       
 
  }else{
   
  }

  
 
}
