#include <SPI.h>

const int ssPin = 10;
const int ledPin = 7;

void setup() {
  pinMode(ssPin, OUTPUT);
  digitalWrite(ssPin, HIGH); // Slave inactivo al inicio
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  SPI.begin(); // Inicia Master
}

void loop() {
  digitalWrite(ssPin, LOW);            // Seleccionar Slave
  byte valor = SPI.transfer(0x00);     // Pedir dato
  digitalWrite(ssPin, HIGH);           // Deseleccionar Slave

  Serial.print("Contador: ");
  Serial.println(valor);

  // LED si contador > 10
  digitalWrite(ledPin, (valor > 10) ? HIGH : LOW);

  delay(500);
}
