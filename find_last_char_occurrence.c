/*******************************************************************************
*
* Program: Find The Last Occurrence Of A Character In A String
* 
* Description: Example of how to find the index of the last occurrence of a 
* character in a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=lm0ZSSYP0hg
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int last_occurrence(char string[], char character);

int main()
{
  char string[] = "abcdefghab";
  
  char character = 'z';
  
  int index = last_occurrence(string, character);
  
  if (index == -1)
  {
    printf("%c not found in string.\n", character);
  }
  else
  {
    printf("%c last occurrence: %d.\n", character, index);
  }
  
  return 0;
}

int last_occurrence(char string[], char character)
{
  int index = -1;
  
  int length = strlen(string);
  
  for (int i = 0; i < length; i++)
  {
    if (string[i] == character)
    {
      index = i;
    }
  }
  
  return index;
}