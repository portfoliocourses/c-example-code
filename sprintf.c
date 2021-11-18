/*******************************************************************************
*
* Program: sprintf() function
* 
* Description: Examples of using sprintf() in C to create a string from a 
* format string.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Ps-KajI0asw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
  // character array for string the string produced by sprintf()
  char string[100];
  
  // create the string, store it into sprintf
  // the 2nd argument is the format string, which build a string using 
  // placeholders for an int and a double, see:
  //   https://en.wikipedia.org/wiki/Printf_format_string
  sprintf(string, "Hello %d %f", 2, 10.5);
  
  // output the string
  printf("%s", string);
  printf("\n");
  
  // because we've stored the string in a char array, we can output it again!
  printf("%s", string);
  printf("\n");
  
  // output the string one char at a time so we can see exactly what's stored
  // in the string char array
  int length = strlen(string);
  for (int i = 0; i < length; i++)
    printf("string[%d] = %c\n", i, string[i]);
  
  // notably we can use sprintf() to convert doubles and other numbers to 
  // strings, like convering a double representation of Pi to a string...
  char pi[10];
  double dblpi = 3.141592;
  sprintf(pi, "%f", dblpi);
  printf("%s\n", pi);
  
  return 0;
}