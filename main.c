#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>

void clearInputBuffer();
void getUserInput(int*, int*);
bool isPrime(int);
int *getPrimeNumbers(int, int, int*);
void printNumbers(const int*, int);
bool shouldContinue();

int main(int argc, char *argv[])
{
  int start = 0, end = 0, size = 0;
  int *primeNumbers = NULL;
  bool running = true;

  while(running)
  {
    getUserInput(&start, &end);

    if(!(start >= end || start < 0 || end <= 0))
    {
      primeNumbers = getPrimeNumbers(start, end, &size);
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

void clearInputBuffer()
{
  int c;
  while((c = getchar()) != '\n' && c != EOF);
}

void getUserInput(int *start, int *end)
{
  system("clear");

  printf("Ingrese el limite inferior: ");
  scanf("%d", start);

  printf("Ingrese el limite superior: ");
  scanf("%d", end);

  clearInputBuffer();
}

void printNumbers(const int *primeNumbers, int size)
{
  for(int i = 0; i < size; i++)
    printf("%d ", primeNumbers[i]);
  puts("\n");
}

int *getPrimeNumbers(int start, int end, int *size)
{
  int count = 0, *numbers = NULL;

  for(size_t i = start; i <= end; i++)
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
  for(size_t i = start; i <= end; i++)
  {
    if(isPrime(i))
      numbers[count++] = i;
  }

  *size = count;
  return numbers;
}

bool isPrime(int num)
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

void activate_no_echo_mode()
{
  struct termios term;
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void desactivate_no_echo_mode()
{
  struct termios term;
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag |= (ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

bool shouldContinue()
{
  int key;
  puts("Presiona 'esc' para salir o cualquier otra tecla para repetir...");

  activate_no_echo_mode();
  key = getchar();
  desactivate_no_echo_mode();

  return key != 27;
}
