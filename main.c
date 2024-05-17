#include <stdio.h>
#include <stdlib.h>
#include "./include/prime.h"
#include "./include/input.h"

int main(int argc, char *argv[])
{
  unsigned short size = 0;
  int *primeNumbers = NULL;
  bool running = true;
  limit_t *limit = initializeLimits();

  while(running)
  {
    getUserInput(limit);

    if(limit->lower < limit->upper && limit->lower >= 0 && limit->upper > 0)
    {
      primeNumbers = getPrimeNumbers(limit, &size);
      if(primeNumbers != NULL)
      {
        printf("\nNumeros primos:\n");
        printNumbers(primeNumbers, size);
      }
      else
        printf("No se encontraron numeros primos en el rango dado\n\n");
    }
    else
      puts("Error: No se aceptan numeros negativos o que el limite inferior sea mayor al superior\n");

    free(primeNumbers);
    primeNumbers = NULL;
    running = shouldContinue();
  }

  puts("");
  return EXIT_SUCCESS;
}
