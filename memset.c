/*******************************************************************************
*
* Program: memset demo
* 
* Description: Example of how to use memset in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Njsn5HAnAnk 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main(void) 
{
  char buffer[10];
  
  // We use memset by passing in a memory address where we want to begin setting
  // the value (the array buffer decays to a pointer / memory address when we 
  // use it like this), the value to set ('c'), and the number of bytes to set 
  // that value (sizeof(char) * 5, which will be 5 chars of memory, the first 5 
  // chars of the array.
  memset(buffer, 'c', sizeof(char) * 5);
  
  // We use pointer arithmetic here to set the NEXT 5 chars in the buffer to 
  // 'd', when we add '5' to 'buffer' the expression results in the memory 
  // address shifted over 5 ints from buffer (since buffer stores the memory 
  // address of the first element in the array, this results in buffer+5 
  // pointing to the 5th element of the array).
  memset(buffer+5, 'd', sizeof(char) * 5);

  // print out the contents of buffer
  for (int i = 0; i < 10; i++)
    printf("%c", buffer[i]);
  printf("\n");

  return 0;
}
