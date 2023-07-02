// puertos para el buzzer

#define trig 7 

#define echo 6

#define buzzer 12

// puertos para el motor

#include <Servo.h>
#define SERVO_PIN 9
#define GROUND_JOY_PIN A3            //joystick ground pin will connect to Arduino analog pin A3
#define VOUT_JOY_PIN A2              //joystick +5 V pin will connect to Arduino analog pin A2
#define XJOY_PIN A1                  //X axis reading from joystick will go into analog pin A1
Servo myservo;

//puertos focos led

#define foco1 0

#define foco2 1

#define foco3 2

#define foco4 3

void setup() {
  pinMode(foco1, OUTPUT);
  pinMode(foco2, OUTPUT);
  pinMode(foco3, OUTPUT);
  pinMode(foco4, OUTPUT);

  Serial.begin(9600);
  pinMode(VOUT_JOY_PIN, OUTPUT) ;    //pin A3 shall be used as output
  pinMode(GROUND_JOY_PIN, OUTPUT) ;  //pin A2 shall be used as output
  digitalWrite(VOUT_JOY_PIN, HIGH) ; //set pin A3 to high (+5V)
  digitalWrite(GROUND_JOY_PIN,LOW) ; //set pin A3 to low (ground)
  myservo.attach(9);

  pinMode(trig, OUTPUT);

  pinMode(echo, INPUT);

  pinMode(buzzer, OUTPUT);

  

}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(foco1 , HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(foco2 , HIGH);
  digitalWrite(foco3 , HIGH);
  digitalWrite(foco4 , HIGH);
  
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
   noTone(buzzer);
    
  }else{
   tone(buzzer, 1000);
   delay(1000);
  }

 delay(200);                    
 int joystickXVal = analogRead(XJOY_PIN) ;  //read joystick input on pin A1
 Serial.print(joystickXVal);                //print the value from A1
 Serial.println(" = input from joystick");  //print "=input from joystick" next to the value
 Serial.print((joystickXVal+520)/10);       //print a from A1 calculated, scaled value
 Serial.println(" = output to servo");      //print "=output to servo" next to the value
 Serial.println() ;
 myservo.write((joystickXVal+520)/10);      //write the calculated value to the servo 
}
