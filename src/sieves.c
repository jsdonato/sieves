#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "sieves.h"

void eratosthenes(int** res, int* len, int n) {
  assert(n >= 2);
  int* keep = (int*)malloc(n * sizeof(int));

  // makr everything as kept
  for (int i = 0; i < n; ++i) {
    keep[i] = 1;
  }

  // procedure to keep primes
  const int end = (int)sqrt(n);
  for (int i = 2; i <= end; ++i) {
    if (keep[i] == 1) {
      int num = i * i;
      while (num < n) {
        keep[num] = 0;
        num += i;
      }
    }
  }

  // now compress
  // first find size of list to return
  *len = 0;
  for (int i = 2; i < n; ++i) {
    (*len) += keep[i];
  }
  fprintf(stderr, "HERE : %d\n", *len);

  // allocate memory to res
  // and put primes in it
  *res = malloc((*len) * sizeof(int));
  int p = 0;
  for (int i = 2; i < n; ++i) {
    if (keep[i] == 1) {
      (*res)[p] = i;
      ++p;
    }
  }

  free(keep);
}
