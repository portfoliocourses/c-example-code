/*******************************************************************************
*
* Program: Variable number of function arguments demonstration
* 
* Description: Examples of functions that accept a variable number of arguments
* in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=3iX9a_l9W9Y 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

// stdarg.h includes the type and functions necessary for creating functions 
// that accept a variable number of arguments
#include <stdarg.h>

// the ... indicates the beginning of the variable number of arguments
int max(int num_args, ...);
void print(char *placeholders, ... );

int main(void) 
{
  // we can call max with varying numbers of arguments
  printf("max test:\n");
  int max_num = max(7, 10, 15, 25, 30, 120, 11, 2);
  printf("max: %d\n", max_num);
  max_num = max(4, 20, 55, 15, 12);
  printf("max: %d\n", max_num);
  
  // we can call print with varying numbers and types of arguments too!
  printf("\nprint test:\n");
  print("dddfdd", 1,2,3,5.5,-1,-2);

  return 0;
}

// the first argument is the number of int arguments from which to find the 
// max int value
int max(int num_args, ...)
{
  // va_list variables contain the data necessary for the relevant functions to 
  // extract the arguments
  va_list args;
 
  // we call va_start with our va_list variable args, as well as the last 
  // parameter variable preceeding the beginning of the list of arguments of 
  // variable length
  va_start(args, num_args);
  
  // keep track of the current max number as we extract each argument
  int max = 0;
  for (int i = 0; i < num_args; i++)
  {
    // we call va_arg with our va_list variable args as the first argument, and 
    // the second argument is the type of the argument we are extracting next, 
    // in this case it will always be an int 
    int x = va_arg(args, int);

    // if its the first number, set it as our max, update the max whenever a 
    // new max is found throughout the remainder of the list of arguments
    if (i == 0) max = x;
    else if (x > max) max = x;
  }
  
  // va_end ends our access to the list of arguments, again using our va_list 
  // variable args
  va_end(args);

  return max;
}

// Prints out an arbitrary sequence of int and double values much like printf
// is capable of doing, by looking at a string of place holders where the 'd'
// char represents an int and the 'f' char represents a double value.  The 
// sequence of placeholder characters identifies the number of arguments and 
// sequence of argument types to be expected... so print("ddfd",1,2,2.4,3) 
// means print two ints, a double, and an int, and the arguments are provided 
// in this sequence following the placeholder string.
void print(char *placeholders, ... )
{
  // the number of arguments to be expected is equal to the number of 
  // placeholder string chars as returns by strlen()
  int num_args = strlen(placeholders);

  va_list args;
  va_start(args, placeholders);
  
  for (int i = 0; i < num_args; i++)
  {
    // if the next char in the placeholder string is a 'd', extract the next 
    // argument as an int and print it out
    if (placeholders[i] == 'd')
    {
      int x = va_arg(args, int);
      printf("%d\n", x);
    }
    // if the next char in the placeholder string is a 'f', extract the next 
    // argument as a double and print it out    
    else if (placeholders[i] == 'f')
    {
      double x = va_arg(args, double);
      printf("%f\n", x);
    }
  }

  va_end(args);
}
