/*
  PROGRAMA 1 PARA VERIFICAR EL CODIGO DE EL LLAVERO Y TARJETA



#include <SPI.h>      // incluye libreria bus SPI
#include <MFRC522.h>      // incluye libreria especifica para MFRC522

#define RST_PIN  5      // constante para referenciar pin de reset
#define SS_PIN  53      // constante para referenciar pin de slave select

MFRC522 mfrc522(SS_PIN, RST_PIN); // crea objeto mfrc522 enviando pines de slave select y reset

void setup() {
  Serial.begin(9600);     // inicializa comunicacion por monitor serie a 9600 bps
  SPI.begin();        // inicializa bus SPI
  mfrc522.PCD_Init();     // inicializa modulo lector
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) // si no hay una tarjeta presente
    return;         // retorna al loop esperando por una tarjeta
  
  if ( ! mfrc522.PICC_ReadCardSerial())   // si no puede obtener datos de la tarjeta
    return;         // retorna al loop esperando por otra tarjeta
    
  Serial.print("UID:");       // muestra texto UID:
  for (byte i = 0; i < mfrc522.uid.size; i++) { // bucle recorre de a un byte por vez el UID
    if (mfrc522.uid.uidByte[i] < 0x10){   // si el byte leido es menor a 0x10
      Serial.print(" 0");     // imprime espacio en blanco y numero cero
      }
      else{         // sino
      Serial.print(" ");      // imprime un espacio en blanco
      }
    Serial.print(mfrc522.uid.uidByte[i], HEX);  // imprime el byte del UID leido en hexadecimal  
  } 
  Serial.println();       // nueva linea
  mfrc522.PICC_HaltA();                   // detiene comunicacion con tarjeta
}

*/


/*
  Capitulo 40 de Arduino desde cero en Español.
  Programa que obtiene el UID de la tarjeta o llavero del kit RFID RC522, compara con
  valores previos obtenidos de UID y permite acceso con texto en monitor serie de bienvenida
  Cualquier otra tarjeta o llavero no listado muestra texto de No te conozco, es decir,
  acceso denegado. Requiere instalar libreria MFRC522

  Autor: bitwiseAr  

*/

#include <SPI.h>      // incluye libreria bus SPI
#include <MFRC522.h>      // incluye libreria especifica para MFRC522

#define RST_PIN  5      // constante para referenciar pin de reset
#define SS_PIN  53      // constante para referenciar pin de slave select

MFRC522 mfrc522(SS_PIN, RST_PIN); // crea objeto mfrc522 enviando pines de slave select y reset

byte LecturaUID[4];         // crea array para almacenar el UID leido
byte Usuario1[4]= {0xB6, 0xCB, 0xB3, 0x31} ;    // UID de tarjeta leido en programa 1
byte Usuario2[4]= {0xD1, 0xDF, 0xF4, 0x02} ;    // UID de llavero leido en programa 1

//tarjeta B6 CB B3 31
//llavero D1 DF F4 02



void setup() {
  Serial.begin(9600);     // inicializa comunicacion por monitor serie a 9600 bps
  SPI.begin();        // inicializa bus SPI
  mfrc522.PCD_Init();     // inicializa modulo lector
  Serial.println("Listo");    // Muestra texto Listo

  //FOCOS LED

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent())   // si no hay una tarjeta presente
    return;           // retorna al loop esperando por una tarjeta
  
  if ( ! mfrc522.PICC_ReadCardSerial())     // si no puede obtener datos de la tarjeta
    return;           // retorna al loop esperando por otra tarjeta
    
    Serial.print("UID:");       // muestra texto UID:
    for (byte i = 0; i < mfrc522.uid.size; i++) { // bucle recorre de a un byte por vez el UID
      if (mfrc522.uid.uidByte[i] < 0x10){   // si el byte leido es menor a 0x10
        Serial.print(" 0");       // imprime espacio en blanco y numero cero
        }
        else{           // sino
          Serial.print(" ");        // imprime un espacio en blanco
          }
          Serial.print(mfrc522.uid.uidByte[i], HEX);    // imprime el byte del UID leido en hexadecimal
          LecturaUID[i]=mfrc522.uid.uidByte[i];     // almacena en array el byte del UID leido      
          }
          
          Serial.print("\t");         // imprime un espacio de tabulacion    
          
          if(comparaUID(LecturaUID, Usuario1))    // llama a funcion comparaUID con Usuario1
            digitalWrite(4, !digitalRead(4)); // si retorna verdadero muestra texto bienvenida
          else if(comparaUID(LecturaUID, Usuario2)) // llama a funcion comparaUID con Usuario2
            digitalWrite(3, !digitalRead(3)); // si retorna verdadero muestra texto bienvenida
           else           // si retorna falso
            Serial.println("No te conozco");    // muestra texto equivalente a acceso denegado          
                  
                  mfrc522.PICC_HaltA();     // detiene comunicacion con tarjeta                
}

boolean comparaUID(byte lectura[],byte usuario[]) // funcion comparaUID
{
  for (byte i=0; i < mfrc522.uid.size; i++){    // bucle recorre de a un byte por vez el UID
  if(lectura[i] != usuario[i])        // si byte de UID leido es distinto a usuario
    return(false);          // retorna falso
  }
  return(true);           // si los 4 bytes coinciden retorna verdadero
}
