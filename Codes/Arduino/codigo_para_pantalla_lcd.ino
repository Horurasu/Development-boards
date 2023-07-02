
#include <LiquidCrystal.h> // import libreria

LiquidCrystal lcd(7, 6, 5, 4, 3 ,2); // pines RS, E, D4, D5, D6 ,D7 de modulo


void setup(){
  lcd.begin(16,2); //inicializa a display de  16 columnas y 2 lineas
}

void loop(){
  lcd.setCursor(0,0); // ubica cursor en columna 0 , linea 0
  lcd.print("IMI REPROBADO"); // escribe el texto en pantalla
  lcd.setCursor(0,1); //ubica el cursor en comuna 0 , linea 1
  lcd.print(millis()/1000); // escribe el valor en segundos devuelto por funciones
  lcd.print("seg."); // imprime a continuacion segundos
}
