#include "./Morse.h"

int pin = 13;

void setup()
{
}

void loop()
{
  struct Morse m = morse(pin);
  // S
  dot(m); dot(m); dot(m);
  // O
  dash(m); dash(m); dash(m);
  // S
  dot(m); dot(m); dot(m);
  delay(1000);
}
