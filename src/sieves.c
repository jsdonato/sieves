#include "sieves.h"

void eratosthenes(int* res, int* len, int n) {
  int* integers = (int*)malloc(n * sizeof(int));
  int* mark = (int*)malloc(n * sizeof(int));

  int p;
  int i;
  int num;

  // initialize buffer of integers in [0,n)
  integers[0] = 0;
  for (i = 1; i < n; ++i) {
    integers[i] = inters[i - 1] + 1;
  }

  // mark everything in the list
  for (i = 0; i < n; ++i) {
    mark[i] = 1;
  }

  // procedure to mark primes as those we
  // want to keep
  p = 2;
  int found = 1;
  while (found == 1) {
    i = 2;
    while (num < n) {
      num = i * p;
      mark[num] = 0;
      ++i;
    }

    found = 0;
    for (i = p + 1; i < num; ++i) {
      if (mark[i] == 1) {
        found = 1;
        p = i;
        break;
      }
    }
  }

  // now compress
  // first find size of list to return
  *len = 0;
  for (i = 2; i < num; ++i) {
    (*len) += mark[i];
  }

  // allocate memory to res
  // and put primes in it
  res = malloc(len * sizeof(int));
  p = 0;
  for (int i = 2; i < num; ++i) {
    if (mark[i] == 1) {
      res[p] = i;
      ++p;
    }
  }

  free(integers);
  free(mark);
}
