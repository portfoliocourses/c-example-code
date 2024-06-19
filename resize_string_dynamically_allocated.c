/*******************************************************************************
*
* Program: Resize A Dynamically Allocated String
* 
* Description: Program to resize a dynamically allocated string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=hKT4EFD4xNI 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  // Pointer variable to store memory address of dynamically allocated block
  // of memory.
  char *string;
  
  // malloc() will allocate space for 5 bytes, i.e. 5 chars worth of space
  string = malloc(5);
  
  // Copy the string "abcd" into the block of memory, which will be 5 chars
  // when considering the null terminator.
  strcpy(string, "abcd");

  // Output the string  
  printf("%s\n", string);

  // If we want to make the string larger we could realloc to re-allocate a
  // larger block of memory.  Here we will get a 6 byte block of memory.  The
  // memory address of the block of memory could potentially be new and will
  // be returned by the function either way, so we assign it to string.
  string = realloc(string, 6);
  
  // We could then write additional string characters to the block of memory
  // (which we can access using array notation).
  string[4] = 'e';
  string[5] = '\0'; 
  
  //  string:  a  b  c  d  e  \0
  //   index:  0  1  2  3  4  5
  
  // Output the string after making it larger
  printf("%s\n", string);

  // We could also make the block of memory smaller
  string = realloc(string, 4);

  // We'll now have the string "abc"
  string[3] = '\0';

  // Output the string again
  printf("%s\n", string);

  // Free the block of memory
  free(string);
  
  return 0;
}