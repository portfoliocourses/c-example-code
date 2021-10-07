/*******************************************************************************
*
* Program: Count letters in a string
* 
* Description: Example of counting the letters in a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=JXL8NYoVv6U 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(char *s);

int main()
{
  // test the function
  char s[] = "A string with some letters 123456789 !@#%^&*(";
  int result = count_letters(s);
  printf("letter count: %d\n", result);
  
  return 0;
}

// returns the number of letters in string s
int count_letters(char *s)
{
  int length = strlen(s);
  int count = 0;

  // check each character in the string, increment count each time a letter is 
  // encountered (isalpha() returns true if the char is a letter) 
  for (int i = 0; i < length; i++)
    if (isalpha(s[i])) count++;
  
  return count;
}
