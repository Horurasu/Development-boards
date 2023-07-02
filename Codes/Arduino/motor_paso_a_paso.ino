int LEDRed = 9;
int LEDGreen = 10;
int LEDBlue = 11;
int sensePin1 = A0;
int sensePin2 = A1;
int sensePin3 = A2;
int val0;
int val1;
int val2;

void setup(){
  pinMode(LEDRed, OUTPUT);
  pinMode(LEDGreen, OUTPUT);
  pinMode(LEDBlue, OUTPUT);
  pinMode(sensePin1, INPUT);
  pinMode(sensePin2, INPUT);
  pinMode(sensePin3, INPUT);
  Serial.begin(9600);
}

void loop(){
  val0 = analogRead(sensePin1);
  val1 = analogRead(sensePin2);
  val2 = analogRead(sensePin3);

  if(val0 <10){
   analogWrite(LEDRed, 255);
   analogWrite(LEDBlue, 255); 
    analogWrite(LEDGreen,255);
  }
  else if (val0 <100) {
   analogWrite(LEDRed, 25);
   analogWrite(LEDBlue,125); 
   analogWrite(LEDGreen,255); 
  }
   else if (val0<400) {
    analogWrite(LEDRed,128);
    analogWrite(LEDBlue,map(val1,200,400,0,128)); 
    analogWrite(LEDGreen,map(val1,200,400,128,0));
  } 
  else if (val0  <600) {
   analogWrite(LEDRed, 25);
   analogWrite(LEDBlue,190); 
    analogWrite(LEDGreen,255);

    }
    else if (val0<800) {
    analogWrite(LEDRed,map(val2,400,800,128,0));
    analogWrite(LEDBlue,128); 
    analogWrite(LEDGreen,map(val2,800,400,0,128));
  }
  if(val1 <10){
   analogWrite(LEDRed, 255);
   analogWrite(LEDBlue, 255); 
    analogWrite(LEDGreen,255);
  }
  else if (val1 <100) {
   analogWrite(LEDRed, 25);
   analogWrite(LEDBlue,125); 
   analogWrite(LEDGreen,255); 
  }
   else if (val1<400) {
    analogWrite(LEDRed,128);
    analogWrite(LEDBlue,map(val1,200,400,0,128)); 
    analogWrite(LEDGreen,map(val1,200,400,128,0));
  } 
  else if (val1 <600) {
   analogWrite(LEDRed, 25);
   analogWrite(LEDBlue,190); 
    analogWrite(LEDGreen,255);

    }
    else if (val1<800) {
    analogWrite(LEDRed,map(val2,400,800,128,0));
    analogWrite(LEDBlue,128); 
    analogWrite(LEDGreen,map(val2,800,400,0,128));
  }
  if(val2 <10){
   analogWrite(LEDRed, 255);
   analogWrite(LEDBlue, 255); 
    analogWrite(LEDGreen,255);
  }
  else if (val2 <100) {
   analogWrite(LEDRed, 25);
   analogWrite(LEDBlue,125); 
   analogWrite(LEDGreen,255); 
  }
   else if (val2<400) {
    analogWrite(LEDRed,128);
    analogWrite(LEDBlue,map(val1,200,400,0,128)); 
    analogWrite(LEDGreen,map(val1,200,400,128,0));
  } 
  else if (val2 <600) {
   analogWrite(LEDRed, 25);
   analogWrite(LEDBlue,190); 
    analogWrite(LEDGreen,255);

    }
    else if (val2<800) {
    analogWrite(LEDRed,map(val2,400,800,128,0));
    analogWrite(LEDBlue,128); 
    analogWrite(LEDGreen,map(val2,800,400,0,128));
  }


}
