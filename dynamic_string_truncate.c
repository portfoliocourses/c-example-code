/*******************************************************************************
*
* Program: Truncate A Dynamically Allocated String
*
* Description: Example of how to truncate a dynamically allocated string in C.
*
* YouTube Lesson: https://www.youtube.com/watch?v=MiqLsSFrQP0
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dynamic_string_truncate(char *string, int n);

int main(int argc, char *argv[])
{
  // Use malloc to allocate a block of memory able to store 25 bytes (chars)
  // and store the pointer (memory address) it returns for this block of memory
  // into string.
  char *string = malloc(25);

  // Copy the string "It works on my machine." into the block of memory that
  // string points to.
  strcpy(string, "It works on my machine.");

  // Print out the string before truncating the string.
  printf("before string: %s\n", string);

  // If we want to truncate the string down to the text "It works" we would
  // insert a null terminator to end the string at the index 8, the index
  // after the 's' character.  This will cause the string to stop here as the
  // null terminator signifies the end of a string.  BUT we would then have
  // unused memory as we would only be using 9 bytes/chars total to store
  // the string, even though the block of memory allocated is 25 bytes/chars
  // large.  If we stored our string into a char array on the stack declared
  // with:
  //
  // char string[25];
  //
  // ...then there is nothing we could do to re-size the array, we would have
  // unused memory.  But because we've used dynamically allocated memory we
  // could instead call realloc() to change the size of the block of memory
  // used to store the string.  We call realloc() and supply it with the pointer
  // to the existing block of memory as the first argument, and the new amount
  // of bytes/chars required as the second argument, and realloc() will allocate
  // space for this smaller block of memory.  It's technically possible that
  // realloc() will move the block of memory to a different location in memory,
  // with a differeny memory address (pointer), and so it returns this
  // potentially different pointer that we store into string so that we
  // are sure to maintain a pointer to the block of memory storing our string.
  //
  // In this way, we would be using a smaller block of memory and no longer
  // have "unused memory".  Also note that in general if we want to truncate
  // a string down to n characters we want to insert the null terminator at
  // the index n and call realloc to reallocate the block of memory to the size
  // n + 1, where the + 1 is to account for the special null terminator
  // character that terminates the string (which also needs to be stored in
  // memory).
  //
  // We could uncomment the below code and comment out the function call to
  // test out the code.
  //
  // string[8] = '\0';
  // string = realloc(string, 9);

  // The dynamic_string_truncate function will truncate the string down to its
  // first 8 characters, it uses realloc() internally and so returns the
  // potentially new memory address (pointer) that we store into string to
  // ensure string will be a pointer to the correct block of memory.
  string = dynamic_string_truncate(string, 8);

  // Print out the string after truncating the string.
  printf(" after string: %s\n", string);

  // Free the dynamically allocated block of memory used to store the string to
  // prevent a memory leak from occurring.
  free(string);

  return 0;
}

// Truncates the string stored in dynamically allocated memory that string
// points to (i.e. stores the memory address of) down to the first n characters,
// and returns a pointer to the block of memory where the truncated string is
// stored.
char *dynamic_string_truncate(char *string, int n)
{
  // Truncate the string by inserting the null terminator at index n
  string[n] = '\0';

  // Use realloc() to reallocate space for the string, return the potentially
  // new pointer (memory address)
  return realloc(string, n + 1);
}