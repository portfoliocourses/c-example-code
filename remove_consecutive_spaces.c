/*******************************************************************************
*
* Program: Remove Consecutive Spaces In A String
* 
* Description: Remove the consecutive spaces in a string using C, i.e. replace
* multiple consecutive spaces with a single space.
*
* YouTube Lesson: https://www.youtube.com/watch?v=liwJ3Gr-6z0
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void remove_consecutive_spaces(char *string);

int main(void)
{
  char string[] = "String   with   consecutive  spaces.";
  
  printf("Before: '%s'\n", string);
  
  remove_consecutive_spaces(string);
  
  printf(" After: '%s'\n", string);

  return 0;
}

void remove_consecutive_spaces(char *string)
{
  int length = strlen(string);
  
  int j = 0;
  bool last_char_not_space = true;
  for (int i = 0; i < length; i++)
  {
    if (string[i] != ' ' || last_char_not_space)
    {
      string[j] = string[i];
      j++;
    }
      
    if (string[i] == ' ') last_char_not_space = false;
    else last_char_not_space = true;
  }
  
  string[j] = '\0';
}

