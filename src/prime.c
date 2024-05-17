#include <stdio.h>
#include <stdlib.h>
#include "../include/prime.h"

limit_t *initializeLimits()
{
  limit_t *limit = (limit_t *)malloc(sizeof(limit_t));

  if(limit != NULL)
  {
    limit->lower = 0;
    limit->upper = 0;
  }

  return limit;
}

static bool isPrime(unsigned int num)
{
  if(num <= 1) return false;
  if(num <= 3) return true;
  if(num % 2 == 0 || num % 3 == 0) return false;
  for(size_t i = 5; i * i <= num; i += 6)
  {
    if(num % i == 0 || num % (i + 2) == 0) 
      return false;
  }

  return true;
}

int *getPrimeNumbers(limit_t *limit, unsigned short *size)
{
  int count = 0, *numbers = NULL;

  for(size_t i = limit->lower; i <= limit->upper; i++)
  {
    if(isPrime(i))
      count++;
  }

  if(count == 0)
    return NULL;

  numbers = (int *)malloc(sizeof(int) * count);
  if(numbers == NULL)
  {
    fprintf(stderr, "Error al asignar memoria\n");
    exit(EXIT_FAILURE);
  }

  count = 0;
  for(size_t i = limit->lower; i <= limit->upper; i++)
  {
    if(isPrime(i))
      numbers[count++] = i;
  }

  *size = count;
  return numbers;
}

void printNumbers(const int *primeNumbers, unsigned short size)
{
  for(size_t i = 0; i < size; i++)
    printf("%d ", primeNumbers[i]);
  puts("\n");
}
