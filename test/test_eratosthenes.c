#include "tests.h"

int test_eratosthenes() {
  printf("=== BEGIN TEST ERATOSTHENES ===\n");

  int* res;
  int len;

  eratosthenes(&res, &len, 9);

  ASSERT_TRUE(len == 4);
  ASSERT_TRUE(res[0] == 2);
  ASSERT_TRUE(res[1] == 3);
  ASSERT_TRUE(res[2] == 5);
  ASSERT_TRUE(res[3] == 7);

  free(res);

  eratosthenes(&res, &len, 3);

  ASSERT_TRUE(len == 1);
  ASSERT_TRUE(res[0] == 2);

  free(res);

  printf("=== END TEST ERATOSTHENES ===\n");
  return EXIT_SUCCESS;
}
