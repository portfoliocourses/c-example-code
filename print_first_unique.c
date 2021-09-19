/*******************************************************************************
*
* Program: Print first unique character demonstration
* 
* Description: Example of printing the first unique character in a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=FanAYSSHABU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print_first_unique(char *s);

int main()
{
  // test the function
  char s[] = "abcdefghijklmnopabcdefghi";  
  print_first_unique(s);

  return 0;
}

// prints the first unique character in string s
void print_first_unique(char *s)
{
  int length = strlen(s);
  bool found_repeat = false;
  bool found_unique = false;
  
  // check each character in the string 
  for (int i = 0; i < length; i++)
  { 
    // see if the character has a repeat in the string
    found_repeat = false;
    for (int j = 0; j < length; j++)
      if (s[i] == s[j] && i != j)
        found_repeat = true;

    // if it does print it out and stop looking
    if (!found_repeat)
    {
      printf("%c\n", s[i]);
      found_unique = true;
      break ; 
    }
  }
  
  // if no unique character was found, print this out instead
  if (!found_unique)
    printf("No unique character found!\n");

}
