#include <Wire.h>

const int potPin = A0;   // Potenciómetro
const int ledPin = 7;    // LED en Peripheral
int potValue = 0;

void setup() {
  Wire.begin(8);                // Dirección I2C del Peripheral
  Wire.onRequest(requestEvent); // Responder al Controller
  pinMode(ledPin, OUTPUT);
}

void loop() {
  potValue = analogRead(potPin) / 4; // Escalar 0-1023 → 0-255

  // Encender/apagar LED local
  digitalWrite(ledPin, (potValue > 125) ? HIGH : LOW);
  delay(50);
}

// Función que envía el valor al Controller
void requestEvent() {
  Wire.write(potValue);  // Enviar un solo byte (0–255)
}
