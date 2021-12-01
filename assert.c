/*******************************************************************************
*
* Program: assert() Demonstration
* 
* Description: Example of using assertions with assert() in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=4cL5WwBnwCw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

// if we define NDEBUG assertions will be turned off!
// #define NDEBUG

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void print_string(char *s);

int main(void)
{
  // if we dynamically allocate space for string, it won't be set to NULL
  char *string = malloc(sizeof(char) * 10);
  strcpy(string, "abc");
  
  // if we don't dynamically allocate space for a string, it will be NULL
  char *bad_string;
  
  // we could call a function that depends on a dynamically allocated string 
  // and forget to allocate it as we have above...
  print_string(bad_string);
  
  return 0;
}

// prints string s, but uses an assertion to ensure s is not NULL first
void print_string(char *s)
{
  // if s is NULL our program will abort with an descriptive message as to 
  // what assertion failed and where
  assert(s != NULL);

  // we would not normally want to ever abort our program for the end user of 
  // the program, we would normally like to "fail gracefully" with a friendlier
  // message as below...
  if (s == NULL)
  {
    printf("Problem with program, let admin know!\n");
    exit(1);
  }

  // prints the string
  printf("@@@%s@@@\n", s);
}