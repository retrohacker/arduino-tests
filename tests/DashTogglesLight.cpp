#include "Morse.h"
#include <stdio.h>

int fail() {
  printf("[FAIL]\n");
  return 1;
}

int main() {
  Morse m = morse(13);
  dash(m);

  Arduino_digitalWrite digitalWriteMock = getDigitalWriteMock();
  Arduino_delay delayMock = getDelayMock();

  printf("Validating pin was toggled... ");
  if (
      digitalWriteMock.invoked != 2
  ) {
    return fail();
  } else {
    printf("[OK]\n");
  }

  printf("Validating pin was set high first... ");
  if (
      digitalWriteMock.values[0].pin != 13 ||
      digitalWriteMock.values[0].value != HIGH
  ) {
    return fail();
  } else {
    printf("[OK]\n");
  }

  printf("Validating pin was then set low... ");
  if (
      digitalWriteMock.values[1].pin != 13 ||
      digitalWriteMock.values[1].value != LOW
  ) {
    return fail();
  } else {
    printf("[OK]\n");
  }

  printf("Validating we waited twice... ");
  if (
      delayMock.invoked != 2
  ) {
    return fail();
  } else {
    printf("[OK]\n");
  }

  return 0;
}
