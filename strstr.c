/*******************************************************************************
*
* Program: strstr demo
* 
* Description: Example of using the strstr function in C.
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
  char haystack[] = "This is the way.";
  char needle[] = "the";

  // strstr will return a pointer to the first occurrence of needle in the 
  // haystack, effectively giving us a substring of the original string 
  // from the matching string to the end of the string  
  char *the = strstr(haystack, needle);
  printf("the: %s\n" , the);
  
  // if strstr cannot find a match, it will return NULL
  char now[] = "now";
  char *fail = strstr(haystack, now);
  if (fail == NULL) printf("failed to find string!\n");

  return 0;
}
