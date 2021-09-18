/*******************************************************************************
*
* Program: Recursive Reverse Print String 
* 
* Description: Example of using recursion to print a string in reverse in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=iWQ5rGWmkXw 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>

void print_reverse(char *s);

int main()
{
  // test the function out
  char s[] = "This is the way.";
  print_reverse(s);
  printf("\n");

  return 0;
}

// prints string s in reverse
void print_reverse(char *s)
{
  // stop recursive function calls once we reach null terminator (end of string)
  if (*s != '\0')
  {
    // before printing the current character, call the function recursively 
    // with a pointer to the next character... because we always call the 
    // function pointing to the next character BEFORE we print the character, 
    // we'll end up printing the last character first, then the 2nd last, and 
    // on and one as we "unroll" the stack of recursive function calls...
    print_reverse(s + 1);
    printf("%c", *s);
  }
}


