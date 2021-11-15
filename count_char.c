/*******************************************************************************
*
* Program: Count The Occurrences Of A Character In A String
* 
* Description: Example of a function for counting the occurrences of a 
* character in a string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=vnGgSU28hU8  
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int count_char(char *s, char c);

int main()
{
  // test string to test the function
  char test[] = "This is my test string.";
  
  // 's' count should be 4
  int count_s = count_char(test, 's');
  printf("count s: %d\n", count_s);
  
  // '.' count should be 1
  int count_period = count_char(test, '.');
  printf("count .: %d\n", count_period);
  
  return 0;
}

// returns the number of times character c occurs in string s
int count_char(char *s, char c)
{
  // length lets us know when to stop the for loop counter variable
  int length = strlen(s);
  
  // count keeps a running tally of the occurrences of c
  int count = 0;
  
  // inspect each element to see if it is equal to c, increment the count if so
  for (int i = 0; i < length; i++)
    if (s[i] == c) count++;

  return count;
}
