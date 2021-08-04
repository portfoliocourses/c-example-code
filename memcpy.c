/*******************************************************************************
*
* Program: memcpy demo
* 
* Description: Example of using the memcpy function in C.  The memcpy function 
* allows us to copy a block of data located at an address in memory to another 
* address in memory.
*
* YouTube Lesson: https://www.youtube.com/watch?v=yoa_mMmvlMc
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void) 
{
  char s[] = "abcdefghijklmnopqrstuvwxyz";
  char d[27];
 
  // copy 27 chars worth of data from s to do... the 26 letters + the null 
  // terminator
  memcpy(d, s, sizeof(char) * 27);
  printf("d: %s\n", d);

  // copy 9 chars worth of data from the memory address of s shifted over by 
  // 8 ints worth of memory addresses (using pointer arithmetic with s+8)
  char e[10];
  memcpy(e, s+8, sizeof(char) * 9);

  // append the null terminator manually to the end of e since this time we 
  // did not copy it from s
  e[9] = '\0';
  printf("e: %s\n", e);

  return 0;
}
