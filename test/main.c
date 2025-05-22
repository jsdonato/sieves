#include "tests.h"

int main() {
  const int num_tests = 2;
  int tests[num_tests];

  tests[0] = test_eratosthenes();
  tests[1] = test_sundaram();

  for (int i = 0; i < num_tests; ++i) {
    if (tests[i] == EXIT_FAILURE) {
      return 1;
    }
  }

  return 0;
}
