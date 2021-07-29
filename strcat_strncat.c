/*******************************************************************************
*
* Program: String concatenation 
* 
* Description: A demonstration of using the string concatenation functions in C.
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
  // test strings
  char dest[20] = "This and ";
  char src[5] = "that";
 
  // the src string will be appended on to the dest string and stored in the 
  // dest char array
  char *ptr = strcat(dest, src);

  // strcat returns a pointer to the concatenated string... but since it is 
  // stored in dest, it's really just the same thing as dest!
  printf("dest: %s\n", dest);
  printf("ptr: %s\n", ptr);

  // we can tell they are the same because the memory addresses stored by 
  // dest and ptr are the same
  printf("dest: %p\n", dest);
  printf(" ptr: %p\n", ptr);

  // new test strings
  char dest2[20] = "This and ";
  char src2[5] = "that";
  
  // strncat will append a maximum of 3 chars from src2 to dest2... this is 
  // useful for ensuring we never write a string to dest2 larger than the 
  // char array!
  strncat(dest2, src2, 3);

  printf("dest2: %s\n", dest2);

  return 0;
}
