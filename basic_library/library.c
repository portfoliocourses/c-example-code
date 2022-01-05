// library.c contains functions definitions of our library used by main.c

// we can include libraries, including the standard libraries, in our library
#include <stdio.h>

int add(int x, int y)
{
  printf("add function\n");
  return x + y;
}

int sub(int x, int y)
{
  return x - y;
}