#include <Wire.h>

const int ledPin = 7; // LED en Controller
int potValue = 0;

void setup() {
  Wire.begin(); 
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  Wire.requestFrom(8, 1); // Pedir 1 byte al Peripheral

  if (Wire.available()) {
    potValue = Wire.read(); // Recibir valor (0-255)
    Serial.print("Pot = ");
    Serial.println(potValue);

    // Encender LED local si pot > ~500 (≈125 en escala 0–255)
    digitalWrite(ledPin, (potValue > 125) ? HIGH : LOW);
  }

  delay(500);
}
