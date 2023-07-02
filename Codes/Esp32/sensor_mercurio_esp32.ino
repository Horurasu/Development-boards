//------------------------------------------------------------------------LIBRERIAS DE ESP32

#define CUSTOM_SETTINGS //biblioteca de dabble
#define INCLUDE_LEDCONTROL_MODULE //modulo control de LED
#define INCLUDE_NOTIFICATION_MODULE //modulo de notificaciones
#include <DabbleESP32.h> //libreria de dabble
unsigned long lasttime=0; // variable de uso de dabble.

//------------------------------------------------------------------------/LIBRERIAS DE ESP32

int sensor = 18;
int led = 19;
  // int zuum = 2;

void setup() {
  pinMode(sensor,INPUT);
  Dabble.begin("Martin"); // se inicia nuestro bluethooth
  Dabble.waitForAppConnection(); // conexion con la APP
  Notification.clear(); // si ya existe un dato anterior
  Notification.setTitle("Sensor"); //nombre de notificacion
  pinMode(led, OUTPUT);
    //pinMode(zumm, OUTPUT);
}

void loop() {
  
  Dabble.processInput(); //Estara pendiente de una entrada de datos de los sensores

  if(digitalRead(sensor) == HIGH)
  {
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
      //digitalWrite(zuum, HIGH);
    delay(100);
      //digitalWrite(zuum, LOW);
    Notification.clear();
    Notification.notifyPhone("Alguien movio el ciruito");

  }
  
}
