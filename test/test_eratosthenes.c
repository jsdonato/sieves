#include "tests.h"

void test_eratosthenes() {
  printf("=== BEGIN TEST ERATOSTHENES ===\n");

  int* res;
  int len;

  eratosthenes(&res, &len, 9);

  assert(len == 4);
  assert(res[0] == 2);
  assert(res[1] == 3);
  assert(res[2] == 5);
  assert(res[3] == 7);

  free(res);

  eratosthenes(&res, &len, 3);

  assert(len == 1);
  assert(res[0] == 2);

  free(res);

  printf("=== END TEST ERATOSTHENES ===\n");
}
