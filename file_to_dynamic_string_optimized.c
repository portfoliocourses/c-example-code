/*******************************************************************************
*
* Program: Store File Contents Into A Dynamically Allocated String (Optimized)
*
* Description: An optimized example of how to store the contents of a file
* into a dynamically allocated string in C.  In this version of the program
* we only read the file contents once, which will optimize performance compared
* to an easier to understand version of the program which reads the file twice.
* Reading the file only once improves performance because it is an expensive
* operation to access a file on a disk.
*
* YouTube Lesson: https://www.youtube.com/watch?v=Oa_ji3dDFew 
*
* Author: Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// We will increase the size of our dynamically allocated memory as more space
// is needed to store the file contents when reading the file.  Each time we
// need to increase the size of the dynamically allocated memory, we will do
// so by an increasing amount, starting from a lower bound up until some
// upper bound is reached, as defined using the preprocessor constants below.
#define LOWER 1024
#define UPPER 65536

int main(int argc, char *argv[])
{
  // File pointer variable to allow us to access the file.
  FILE *file;

  // We'll accept the name of the file to be read as a command-line argument,
  // and so argc should be set to 2 (the program name + the argument).
  if (argc != 2)
  {
    // Exit with an error message and status if we have the incorrect number
    // of arguments... returning 1 instead of returning 0 is a signal to the
    // shell/terminal that something has gone wrong in the execution of our
    // program.
    printf("Invalid number of arguments!\n");
    return 1;
  }

  // Open the file for reading, where argv[1] is the command-line argument
  // that was provided to our program (i.e. the name of the file).
  file = fopen(argv[1], "r");

  // If fopen() fails to open the file it will return NULL, so we check if file
  // is set to NULL and exit with an error message and status if so.
  if (file == NULL)
  {
    printf("Error opening file!\n");
    return 1;
  }

  // increase will keep track of the size by which to increase the dynamically
  // allocated block of memory
  size_t increase = LOWER;

  // allocated will keep track of the total size of the dynamically allocated
  // block of memory
  size_t allocated = increase;

  // Initially allocate a block of memory of size equal to our lower bound
  char *string = malloc(allocated);

  // total will keep track of the total number of characters in the file
  size_t total = 0;

  // Keep reading the file one character at a time, incrementing total each
  // time, until we reach the end of the file (as deteched by feof()) or an
  // error occurs (as deteched by ferror()).
  while (!feof(file) && !ferror(file))
  {
    // Store the next character we've read into the string at the index total,
    // and increment total by 1 to keep track of the total number of characters
    // in the file (and so that in the next loop iteration the next char
    // in the string is set to the next char read from the file).
    string[total] = fgetc(file);
    total++;

    // If we've reached the total size of our dynamically allocated block of
    // memory, we need to use realloc() to increase the size of that block
    // of memory.
    if (total >= allocated)
    {
      // We'll increase the size of the block of memory by an increasing
      // amount each time we do, doubling the increase each time, starting from
      // the lower bound until an upper bound is reached, at which point
      // we'll limit the increase to this upper bound.
      if (increase >= UPPER) increase = UPPER;

      // Increase the total allocated memory by this amount
      allocated += increase;

      // Re-allocate the block of memory... it's possible realloc() will need
      // to move our string to a new place in memory if it cannot find enough
      // memory adjacent to the string's current location in memory, this is
      // why it returns a potentially new pointer value that we store into
      // string.
      string = realloc(string, allocated);

      // Double increase so that if realloc() is required again we increase
      // the size of our block of memory by a greater amount.
      increase *= 2;
    }
  }

  // If there has been an error reading from the file, exit with an error
  // message and status
  if (ferror(file))
  {
    printf("Error reading from file!\n");
    return 1;
  }

  // It's most likely that we have more space allocated than we actually need
  // to store the string, e.g. if realloc() is never we'll have allocated
  // 1024 chars/bytes worth of space (or whatever our lower limit was) for
  // a string that might only be 50 characers long.  This would be a lot of
  // unused memory, so we use realloc() to decrease the size of the block of
  // memory down to exactly the number of chars requires (total).
  string = realloc(string, total);

  // Set the null terminator as the last char in the string to termiante
  // the string.
  string[total - 1] = '\0';

  // Close the file as we are done working with it now.
  fclose(file);

  // Output the string containing the file contents
  printf("File Contents:\n\n");
  printf("%s\n", string);

  // Free the dynamically allocated string as we are done working with it too.
  free(string);

  return 0;
}