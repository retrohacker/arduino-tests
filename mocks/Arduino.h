#ifndef ArduinoMock_h
#define ArduinoMock_h

#include <stdlib.h>

#define HIGH 0x1
#define LOW  0x0
#define OUTPUT 0x1

typedef struct {
  int pin;
  int mode;
} Arduino_pinMode_values;

typedef struct {
  int invoked;
  Arduino_pinMode_values values[10];
} Arduino_pinMode;

typedef struct {
  int pin;
  int value;
} Arduino_digitalWrite_values;

typedef struct {
  int invoked;
  Arduino_digitalWrite_values values[10];
} Arduino_digitalWrite;

typedef struct {
  unsigned long dur;
} Arduino_delay_values;

typedef struct {
  int invoked;
  Arduino_delay_values values[10];
} Arduino_delay;

void Arduino_reset();
Arduino_pinMode getPinModeMock();
Arduino_digitalWrite getDigitalWriteMock();
Arduino_delay getDelayMock();
void pinMode(int pin, int mode);
void digitalWrite(int pin, int value);
void delay(unsigned long dur);

#endif
