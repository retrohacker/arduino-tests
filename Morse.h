#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

struct Morse {
  int pin;
};

struct Morse morse(int pin);
void dot(struct Morse m);
void dash(struct Morse m);

#endif
