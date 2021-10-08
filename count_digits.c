/*******************************************************************************
*
* Program: Standar deviaton demonstration
* 
* Description: Example of calculating standard deviation in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=epqWMKa--xk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_digits(char *s);

int main()
{
  // test the function
  char s[] = "asdfasdfsdaHFGGJGJG 123456789 @#$@#^$%^$#%^";
  int result = count_digits(s);
  printf("digit total: %d\n", result);
  
  return 0;
}

// returns the number of digits in string s
int count_digits(char *s)
{
  int length = strlen(s);
  int count = 0;
  
  // examine each character in the string using isdigit which returns true 
  // if the character is a digit... and keep a running count 
  for (int i = 0; i < length; i++)
    if (isdigit(s[i])) count++;
  
  return count;
}
