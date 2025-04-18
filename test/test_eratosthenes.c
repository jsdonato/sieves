#include "tests.h"

void test_eratosthenes() {
  printf("=== BEGIN TEST ERATOSTHENES ===\n");

  int* res;
  int len;

  eratosthenes(&res, &len, 9);

  fprintf(stderr, "HERE : %d\n", len);
  assert(len == 4);
  assert(res[0] == 2);
  assert(res[1] == 3);
  assert(res[2] == 5);
  assert(res[3] == 7);

  free(res);

  printf("=== END TEST ERATOSTHENES ===\n");
}
