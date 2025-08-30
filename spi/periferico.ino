#include <SPI.h>

volatile byte contador = 0;
const int ledPin = 7;

void setup() {
  pinMode(MISO, OUTPUT);   // Salida SPI
  pinMode(ledPin, OUTPUT); // LED en Peripheral
  SPCR |= _BV(SPE);        // Habilitar SPI en modo Slave
  SPI.attachInterrupt();   // Interrupción SPI
}

ISR(SPI_STC_vect) {
  SPDR = contador++;        // Enviar contador
  digitalWrite(ledPin, (contador > 10) ? HIGH : LOW); // LED si > 10
}

void loop() {
  // Nada aquí, todo en la interrupción
}
