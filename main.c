#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int);
int *getPrimeNumbers(int, int, int*);
void printNumbers(int*, int);

int main(int argc, char *argv[])
{
  int start = 0, end = 0, size = 0;
  int *primeNumbers = NULL;

  printf("Ingrese el limite inferior: ");
  scanf("%d", &start);

  printf("Ingrese el limite superior: ");
  scanf("%d", &end);

  primeNumbers = getPrimeNumbers(start, end, &size);
  printf("\nNumeros primos:\n");
  printNumbers(primeNumbers, size);

  puts("");
  free(primeNumbers);
  return 0;
}

void printNumbers(int *primeNumbers, int size)
{
  for(int i = 0; i < size; i++)
    printf("%d ", primeNumbers[i]);
}

int *getPrimeNumbers(int start, int end, int *size)
{
  size_t i = start;
  int count = 0, *numbers = NULL;

  for(; i <= end; i++)
  {
    if(isPrime(i))
      count++;
  }

  numbers = (int *)malloc(sizeof(int) * count);
  count = 0;

  for(i = start; i <= end; i++)
  {
    if(isPrime(i))
    {
      numbers[count] = i;
      count++;
    }
  }

  *size = count;
  return numbers;
}

bool isPrime(int num)
{
  if(num <= 1) return false;
  if(num <= 3) return true;
  if(num % 2 == 0 || num % 3 == 0) return false;
  int i = 5;
  while(i * i <= num)
  {
    if(num % i == 0 || num % (i + 2) == 0)
      return false;
    i += 6;
  }
  return true;
}
