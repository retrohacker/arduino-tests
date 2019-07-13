#include "Arduino.h"

Arduino_pinMode pinModeMock;
Arduino_digitalWrite digitalWriteMock;
Arduino_delay delayMock;

void Arduino_reset() {
  pinModeMock.invoked = 0;
  digitalWriteMock.invoked = 0;
  delayMock.invoked = 0;
}

Arduino_pinMode getPinModeMock() {
  return pinModeMock;
}

Arduino_digitalWrite getDigitalWriteMock() {
  return digitalWriteMock;
}

Arduino_delay getDelayMock() {
  return delayMock;
}

void pinMode(int pin, int mode) {
  pinModeMock.values[pinModeMock.invoked++] = { pin, mode };
}

void digitalWrite(int pin, int value) {
  digitalWriteMock.values[digitalWriteMock.invoked++] = { pin, value};
}

void delay(unsigned long dur) {
  delayMock.values[delayMock.invoked++] = { dur };
}
