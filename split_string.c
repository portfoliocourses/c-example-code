/*******************************************************************************
*
* Program: Split String
* 
* Description: Example of splitting a string into two at an index in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=ZVxTouF8WTU 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

void string_split(char *s, int index, char *first, char *second);

int main()
{
  // test string, and character arrays for storing each string portion
  char str[] = "I've got one hand in my pocket.";
  char first[100], second[100];
  
  // call the function
  string_split(str, 13, first, second);
  
  // output each portion of the string
  printf("%s\n", first);
  printf("%s\n", second);
  
  return 0;
}

// splits a string s such that first will contain the substring from 0-(index-1)
// and second will contain the substring from index-strlen(s)
void string_split(char *s, int index, char *first, char *second)
{
  int length = strlen(s);
  
  // we can't do anything if the index is greater than the length of the string
  if (index < length)
  {
    // copy the characters from 0-(index-1) to the first character array
    for (int i = 0; i < index; i++)
      first[i] = s[i];
    first[index] = '\0';
    
    // copy the characters from index-strlen(s) to the second character array
    for (int i = index; i <= length; i++)
      second[i - index] = s[i];
  }
}
