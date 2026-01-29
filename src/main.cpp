#include <Arduino.h>
/*
  - Pin 13: LED integrado (prueba)
  - Pin 8 : salida a MOSFET (SIG)
  Secuencia:
    N destellos cortos -> pausa larga -> repetir
*/
// Pines
const int MOSFET_PIN = 8;
const int LED_PIN    = 13;

// Número de destellos por ciclo
const unsigned int NUM_FLASHES = 5;

// Tiempos (ms) - ajustables
const unsigned int FLASH_ON      = 60;   // duración de cada destello
const unsigned int GAP_BETWEEN   = 80;   // pausa entre destellos
const unsigned int PAUSE_AFTER   = 500;  // pausa tras los destellos

// Función auxiliar: enciende ambos (LED y MOSFET) a la vez
void setOutput(bool on) {
  digitalWrite(MOSFET_PIN, on ? HIGH : LOW);
  digitalWrite(LED_PIN,    on ? HIGH : LOW);
}

void setup() {
  pinMode(MOSFET_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  setOutput(false);
}

void loop() {
  for (unsigned int i = 0; i < NUM_FLASHES; ++i) {
    setOutput(true);
    delay(FLASH_ON);
    setOutput(false);
    if (i + 1 < NUM_FLASHES) {
      delay(GAP_BETWEEN);
    }
  }
  delay(PAUSE_AFTER);
}

