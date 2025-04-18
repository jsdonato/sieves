#ifndef SIEVES_H
#define SIEVES_H

#include <stdlib.h>

/**
 * @brief returns the primes in the interval [2,n)
 * @param[in] n An integer n we wil find primes up to
 * and not including n.
 * @param[out] res List of primes this function returns
 * @param[out] len Length of the return list res.
 */
void eratosthenes(int** res, int* len, int n);

#endif
