#include "Morse.h"
#include <stdio.h>

int fail() {
  printf("[FAIL]\n");
  return 1;
}

int main() {
  Morse m = morse(13);
  dot(m);
  dash(m);

  Arduino_delay delayMock = getDelayMock();

  printf("Validating we waited four times... ");
  if (
      delayMock.invoked != 4
  ) {
    return fail();
  } else {
    printf("[OK]\n");
  }

  printf("Validating first wait less than second... ");
  if (
      delayMock.values[0].dur >= delayMock.values[2].dur
  ) {
    return fail();
  } else {
    printf("[OK]\n");
  }

  return 0;
}
