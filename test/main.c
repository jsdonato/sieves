#include "tests.h"

#undef NUM_TESTS
#define NUM_TESTS 2

int main() {
  int tests[NUM_TESTS];

  tests[0] = test_eratosthenes();
  tests[1] = test_sundaram();

  for (int i = 0; i < NUM_TESTS; ++i) {
    if (tests[i] == EXIT_FAILURE) {
      return 1;
    }
  }

  return 0;
}
