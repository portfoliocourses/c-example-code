/*******************************************************************************
*
* Program: Remove Char At Position 
* 
* Description: Example of removing a character from a string at a given 
* position in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=6nUr72r9sDI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool remove_char(char *s, int pos);

int main()
{ //               12345
  char s[] = "12345-12345";
  
  
  bool result1 = remove_char(s, 20);
  if (result1) printf("Char removed from string!\n");
  else printf("Char not removed from string!\n");
  
  bool result2 = remove_char(s, 5);
  if (result2) printf("Char removed from string!\n");
  else printf("Char not removed from string!\n");
  
  printf("%s\n", s);
  
  return 0;
}

bool remove_char(char *s, int pos)
{
  int length = strlen(s);
  
  if (pos >= length) return false;
  
  for (int i = pos; i < length; i++)
    s[i] = s[i + 1];
  
  return true;
}
