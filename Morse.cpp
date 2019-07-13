#include "Morse.h"

struct Morse morse(int pin) {
  struct Morse result = { pin };
  pinMode(pin, OUTPUT);
  return result;
}

void dot(struct Morse m) {
  digitalWrite(m.pin, HIGH);
  delay(100);
  digitalWrite(m.pin, LOW);
  delay(100);
}

void dash(struct Morse m) {
  digitalWrite(m.pin, HIGH);
  delay(200);
  digitalWrite(m.pin, LOW);
  delay(100);
}
