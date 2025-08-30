#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
const int ledPin = 7;
byte valor = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  mySerial.write(1); // Pedir dato al Peripheral

  delay(100); // Dar tiempo a que Peripheral responda

  if (mySerial.available()) {
    valor = mySerial.read(); // Leer contador
    Serial.print("Contador recibido: ");
    Serial.println(valor);

    // Encender LED si contador > 10
    digitalWrite(ledPin, (valor > 10) ? HIGH : LOW);
  }

  delay(500);
}
