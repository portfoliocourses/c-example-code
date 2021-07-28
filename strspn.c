/*******************************************************************************
*
* Program: strspn demonstration
* 
* Description: Example of using strspn function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=R0qIYWo8igs 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void) 
{
  // strspn will determine the number of chars in the initial segment of s1 
  // that are made up entirely of chars in nums
  char s1[] = "583914502ABJKTMNTY";
  char nums[] = "0128934567";
 
  // we'll get back pos=9
  int pos = strspn(s1, nums);
  printf("pos: %d\n", pos);

  // We might use strspn() to process codes of information with a particular 
  // formatting to determine when one field begins and another ends... e.g. 
  // a field made up of numbers followed by a field made up of letters as in the
  // case of s1.  We could use pointer arithmetic and pos to create a pointer 
  // (essentially a string) we can use to reference the remaining part of the 
  // string.
  char *remaining = s1 + pos;
  printf("%s\n", remaining);

  return 0;
}
