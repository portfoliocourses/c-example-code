/*******************************************************************************
*
* Program: strtod() Tutorial
* 
* Description: Example of how to use the strtod() function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Kc5V2Hq4Fmc  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char s[] = "978.45 Some text after the double value!";
  double result;
  char *ptr;
  
  // converts the string in s to a double and returns it, and via 
  // pass-by-pointer also "returns" a pointer to the portion of the string 
  // after the double in this case " Some text..."
  result = strtod(s, &ptr);
  
  printf("result: %f\n", result);
  printf("string: |%s|\n", ptr);
 
  return 0;
}