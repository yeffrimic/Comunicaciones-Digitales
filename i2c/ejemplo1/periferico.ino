#include <Wire.h>

void setup() {
  Wire.begin(8); // Dirección I2C del esclavo (8)
  Wire.onReceive(receiveEvent); // Función que maneja recepción
  Serial.begin(9600);
}

void loop() {
  delay(100);
}

// Función que se ejecuta al recibir datos del maestro
void receiveEvent(int howMany) {
  while (Wire.available()) {
    byte dato = Wire.read();
    Serial.print("Recibido: ");
    Serial.println(dato);
  }
}
