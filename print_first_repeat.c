/*******************************************************************************
*
* Program: Print First Repeating Character demonstration
* 
* Description: Example of printing the first repeating character in a string 
* with C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=vSIVnsYQrz0 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print_first_repeat(char *s);

int main()
{
  // test the function
  char s[] = "abcdefghij";
  print_first_repeat(s);

  return 0;
}

// prints the first repeating character in string s
void print_first_repeat(char *s)
{
  int length = strlen(s);
  bool found_repeat = false;
  
  // check every character in the string to see if it has a repeat
  for (int i = 0; i < length; i++)
  {
    // check the character against every other character in the string 
    // to see if we can find a repeat
    for (int j = 0; j < length; j++)
      if (s[i] == s[j] && i != j)
        found_repeat = true;
    
    // if we find a repeat, print out the character and stop looking
    if (found_repeat)
    {
      printf("%c\n", s[i]);
      break ;
    }
  }
  
  // if we do not find a repeating character at all, print this out instead
  if (!found_repeat)
    printf("No repeating character found\n");
}


