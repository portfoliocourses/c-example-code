/*******************************************************************************
*
* Program: Append A Character To A String Stored In Dynamically Allocated Memory
*
* Description: Program to append a character to a dynamically allocated string 
* using C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=hZeNI901HwA 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  // Allocate space for 10 bytes, i.e. 10 char values worth of space, store the
  // memory address returned by malloc() into buffer
  char *buffer = malloc(10);
  
  // malloc() returns NULL if it fails, so output an error message and return 1
  // to exit with a status that indicates something has gone wrong with the 
  // program's execution
  if (buffer == NULL)
  {
    printf("Error allocating space for string.\n");
    return 1;
  }
  
  // Copy the string subscribe (including the null terminator) into the memory
  // location that buffer points to (note this takes 10 bytes total worth of
  // memory).
  strcpy(buffer, "subscribe"); 
  
  // Call realloc() to reallocate a larger block of memory.  We will be 
  // appending one character to the string, and we know the existing string 
  // takes 10 bytes to store, so we could simply pass 11 as the 2nd argument 
  // to allocate space for 11 bytes / char values.  But if we didn't know the
  // length of the string we could call strlen() to find it, which will return 
  // the length of the string (not including the null terminator).  We could 
  // then add 2 to this number to account for the null terminator and the 
  // additional character.
  //
  // realloc() might return the same memory address as is already stored in 
  // buffer if the existing block of memory can be enlarged at its current 
  // location (say is the memory next to it is unused).  But if this is not 
  // possible realloc() will copy the data in the existing block of memory 
  // to a new location in memory where there is enough space, and it will 
  // return the memory address of this new location.  Either way, we store 
  // the returned memory address (pointer) into buffer.
  //
  buffer = realloc(buffer, strlen(buffer) + 2 );
  
  // If realloc() fails it will return NULL and we again exit with an 
  // error message and status in this case.
  if (buffer == NULL)
  {
    printf("Error re-allocating space for string.\n");
    return 1;
  }
  
  // The character we wish to append to the string
  char character = 'r';
  
  // Appends the character in the variable character to the string buffer
  strncat(buffer, &character, 1);
  
  // Output the string to confirm the character has been appended
  printf("%s\n", buffer);

  // Free the dynamically allocated memory
  free(buffer);
  
  return 0;
}
