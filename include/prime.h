#ifndef PRIME_H
#define PRIME_H

#include <stdbool.h>
#include "./limit.h"

limit_t *initializeLimits();
int *getPrimeNumbers(limit_t*, unsigned short*);
void printNumbers(const int*, unsigned short);

#endif
