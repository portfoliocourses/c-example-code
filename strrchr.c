/*******************************************************************************
*
* Program: strrchr demo
* 
* Description: A demonstration of how to use the strrchr function in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=cCmHLaL4nag 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void) 
{
  char s[] = "some,data,in,commas";
  
  // the function will return a pointer to the last char that matches ',' in s
  char *comma = strrchr(s, ',');

  // this effectively gives us a substring of s from the last matching char 
  // to the end of the string
  printf("%s\n", comma);
  
  // if no matching char is found, the function will return NULL
  char *fail = strrchr(s, '@');
  if (fail == NULL) printf("Could not find @!\n");

  return 0;
}
