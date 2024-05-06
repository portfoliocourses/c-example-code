/*******************************************************************************
*
* Program: Remove First Occurrence Of A Character From A String
*
* Description: Program to remove the first occurrence of a character in a string
* using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=80AuxBTYSeA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <string.h>

void remove_first(char string[], const char to_remove);

int main(void)
{
  char string[] = "courses";
  char to_remove = 's';
  
  remove_first(string, to_remove);
  
  printf("string: %s\n", string);
  
  return 0;
}
 
void remove_first(char string[], const char to_remove)
{
  int length = strlen(string);
  int i = 0;
  
  while (i < length)
  {
    if (string[i] == to_remove) break;
    i++;
  }
  
  while (i < length)
  {
    string[i] = string[i + 1];
    i++;
  }
}
