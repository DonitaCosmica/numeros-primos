#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>
#include "../include/limit.h"

static void clearInputBuffer()
{
  int c;
  while((c = getchar()) != '\n' && c != EOF);
}

void getUserInput(limit_t *limit)
{
  system("clear");

  printf("Ingrese el limite inferior: ");
  scanf("%d", &limit->lower);

  printf("Ingrese el limite superior: ");
  scanf("%d", &limit->upper);

  clearInputBuffer();
}

static void activate_no_echo_mode()
{
  struct termios term;
  tcgetattr(STDIN_FILENO, &term);
  term.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

static void desactivate_no_echo_mode()
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
