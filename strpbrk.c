/*******************************************************************************
*
* Program: strpbrk Demonstration
* 
* Description: Example of using strpbrk function in C.
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
  char s[] = "AASDFAFS3123123";
  char num[] = "0123456789";

  // the function will return a pointer to the first char in s that matches 
  // the first char in num
  char *match = strpbrk(s, num);
  printf("%s\n", match);

  // when the function cannot find a matching char it will return NULL 
  char punct[] = ",;:";
  char *fail = strpbrk(s, punct);
  if (fail == NULL) printf("Could not find!\n");

  return 0;
}
