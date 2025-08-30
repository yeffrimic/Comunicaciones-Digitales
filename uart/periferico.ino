#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
const int ledPin = 7;
byte contador = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  mySerial.begin(9600);
}

void loop() {
  // Si recibe cualquier dato del Controller, responde con el contador
  if (mySerial.available()) {
    mySerial.read(); // Limpiar buffer de la solicitud
    mySerial.write(contador); // Enviar contador
    contador++;

    // Encender LED si contador > 10
    digitalWrite(ledPin, (contador > 10) ? HIGH : LOW);
  }

  delay(50);
}
