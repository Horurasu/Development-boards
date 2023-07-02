#include <Servo.h>

#define SERVO_PIN 9
#define GROUND_JOY_PIN A3            //joystick ground pin will connect to Arduino analog pin A3
#define VOUT_JOY_PIN A2              //joystick +5 V pin will connect to Arduino analog pin A2
#define XJOY_PIN A1                  //X axis reading from joystick will go into analog pin A1

Servo myservo;
 
void setup(){
 Serial.begin(9600);
 pinMode(VOUT_JOY_PIN, OUTPUT) ;    //pin A3 shall be used as output
 pinMode(GROUND_JOY_PIN, OUTPUT) ;  //pin A2 shall be used as output
 digitalWrite(VOUT_JOY_PIN, HIGH) ; //set pin A3 to high (+5V)
 digitalWrite(GROUND_JOY_PIN,LOW) ; //set pin A3 to low (ground)
 myservo.attach(9);
}
 
void loop(){
 
}
