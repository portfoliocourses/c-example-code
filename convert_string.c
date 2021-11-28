/*******************************************************************************
*
* Program: Convert String To Double, Int, Long Int
* 
* Description: Example of how to convert strings to doubles, ints and long ints
* in C using the atof(), atoi() and atol() functions available in stdlib.h.
*
* YouTube Lesson: https://www.youtube.com/watch?v=UQOlTdArCRo 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // setup test strings
  char *double_test = "98.45";
  char *int_test = "94";
  char *long_int_test = "1231231213213234";
  
  // use the functions to convert each string to their respective types
  double double_result = atof(double_test);
  int int_result = atoi(int_test);
  long int long_int_result = atol(long_int_test);
  
  // output the converted values to check for correctness
  printf("double: %f\n", double_result);
  printf("int: %d\n", int_result);
  printf("long int: %ld\n", long_int_result);
 
  return 0;
}