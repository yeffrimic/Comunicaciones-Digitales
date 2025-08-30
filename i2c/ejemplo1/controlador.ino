#include <Wire.h>

void setup() {
  Wire.begin(); // Inicia como maestro
  Serial.begin(9600);
}

byte contador = 0;

void loop() {
  Wire.beginTransmission(8); // Dirección del esclavo (8)
  Wire.write(contador);      // Enviar un byte
  Wire.endTransmission();

  Serial.print("Enviado: ");
  Serial.println(contador);

  contador++;
  delay(1000);
}
