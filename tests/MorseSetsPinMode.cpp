#include "Morse.h"
#include <stdio.h>

int fail() {
  printf("[FAIL]\n");
  return 1;
}

int main() {
  int i;
  for(i = 0; i < 3; i++) {
    morse(i);
    Arduino_pinMode mock = getPinModeMock();
    printf("Validating pinmode was set to %d... ", i);
    if (
        mock.invoked == 0 ||
        mock.values[0].pin != i ||
        mock.values[0].mode != OUTPUT
    ) {
      return fail();
    } else {
      printf("[OK]\n");
    }
    Arduino_reset();
  }
  return 0;
}
