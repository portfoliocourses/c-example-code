/*******************************************************************************
*
* Program: Optionally Active Debug Code
* 
* Description: Example of using preprocessor directives in C to optionally 
* active / de-activate debug code.
*
* YouTube Lesson: https://www.youtube.com/watch?v=5a4jsVMfjlg 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

// if we define DEBUG_OUTPUT, the below debug code will be included when the
// source code is compiled
#define DEBUG_OUTPUT 0

int main()
{
  // create an array
  int a[] = {0,1,2,3,4,5,6,7,8,9};
  
  // do some work with the array
  for (int i = 0; i < 10; i++)
    a[i] = a[i] * 5;
  
  // typically programmers will throw in some statements to output the state of 
  // variables, arrays, etc, to help them debug... we can *optionally* include 
  // these statements if a constant is defined (in this case, DEBUG_OUTPUT)
  #ifdef DEBUG_OUTPUT
  for (int i = 0; i < 10; i++)
    printf("a[%d] = %d\n", i, a[i]);
  #endif
  
  // we can use ifdef multiple times like this and it will work
  #ifdef DEBUG_OUTPUT
  printf("Additional output statement.\n");
  #endif
  
  // do some more 'real work' with the data
  int sum = 0;
  for (int i = 0; i < 10; i++)
    sum += a[i];
  printf("sum = %d\n", sum);
  
  return 0;
}