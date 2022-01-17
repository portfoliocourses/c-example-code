#include <stdio.h>

// the static keyword will make the global variable number ONLY accessible 
// in this file
static int number = 0;

// function definitions that work with the global variable number

void add_one()
{
  number++;
}

void print()
{
  printf("number: %d\n", number);
}
